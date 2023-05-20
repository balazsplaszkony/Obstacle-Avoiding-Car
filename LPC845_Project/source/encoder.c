/*
 * encoder.c
 *
 *  Created on: 2023. márc. 23.
 *      Author: plasz
 */

#include "encoder.h"

volatile uint32_t captured_time_right = 0;
volatile uint32_t captured_time_left = 0;
volatile uint32_t captured_time_right_prev = 0;
volatile uint32_t captured_time_left_prev = 0;
volatile double  microseconds_elapsed_right = 0;
volatile double microseconds_elapsed_left = 0;



volatile Encoder Encoder_right;
volatile Encoder Encoder_left;

void InitEncoder(volatile Encoder* encoder) {
    encoder->RPM = 0.0f;
    encoder->RPM_prev = 0.0f;
    encoder->updated = false;
}



float lowPassFilter(float input, float prevOutput, float deltaTime, float cutoffFreq)
{
    float RC = 1.0f / (2.0f * 3.14159 * cutoffFreq);
    float alpha = deltaTime / (RC + deltaTime);

    return alpha * input + (1.0f - alpha) * prevOutput;
}



float butterworthSecondOrderLowPassFilter(float input, float* prevInputs, float* prevOutputs, float deltaTime)
{
    const float samplingFreq = 1.0f / deltaTime;
    const float omega = 2.0f * M_PI * FILTER_CUTOFF_FREQ;
    const float t = 1.0f / samplingFreq;
    const float c = 1.0f / (omega * omega * t * t + 2.0f * omega * t + 1.0f);
    const float a1 = 2.0f * (omega * omega * t * t - 1.0f) * c;
    const float a2 = (omega * omega * t * t - 2.0f * omega * t + 1.0f) * c;
    const float b0 = (omega * omega * t * t) * c;
    const float b1 = 2.0f * (omega * omega * t * t) * c;
    const float b2 = b0;
    const float output = b0 * input + b1 * prevInputs[0] + b2 * prevInputs[1] - a1 * prevOutputs[0] - a2 * prevOutputs[1];
    // Update history
    // Update history
    prevInputs[1] = prevInputs[0];
    prevInputs[0] = input;
    prevOutputs[1] = prevOutputs[0];
    prevOutputs[0] = output;

    return output;
}
void EncoderRightCallback(uint32_t flags) {
    static float deltaTimeRight = 0.0f;

    Encoder_right.RPM_prev = Encoder_right.RPM;
    captured_time_right_prev = captured_time_right;
    captured_time_right = CTIMER0->CR[1];

    if (captured_time_right_prev) {
        microseconds_elapsed_right = captured_time_right - captured_time_right_prev;
        Encoder_right.RPM = (1.0 / (microseconds_elapsed_right / (60.0 * 1000000.0))) * (1.0 / Resolution);
    }

    deltaTimeRight = microseconds_elapsed_right / 1000000.0f;

    Encoder_right.RPM = lowPassFilter(Encoder_right.RPM, Encoder_right.RPM_prev, deltaTimeRight, FILTER_CUTOFF_FREQ);

//    PRINTF("%d\n", (int)Encoder_right.RPM);
    Encoder_right.updated = true;
    // Print or use filteredRPMRight as needed
    // ...
    // Rest of the callback function
}

void EncoderLeftCallback(uint32_t flags) {
    static float deltaTimeLeft = 0.0f;

    Encoder_left.RPM_prev = Encoder_left.RPM;
    captured_time_left_prev = captured_time_left;
    captured_time_left = CTIMER0->CR[2];

    if (captured_time_left_prev) {
        microseconds_elapsed_left = captured_time_left - captured_time_left_prev;
        Encoder_left.RPM = (1.0 / (microseconds_elapsed_left / (60.0 * 1000000.0))) * (1.0 / Resolution);
    }

    deltaTimeLeft = microseconds_elapsed_left / 1000000.0f;

    Encoder_left.RPM = lowPassFilter(Encoder_left.RPM, Encoder_left.RPM_prev, deltaTimeLeft, FILTER_CUTOFF_FREQ);

    Encoder_left.updated = true;
    // Print or use filteredRPMLeft as needed
    // ...
    // Rest of the callback function
}
void EncoderTimerHandler(uint32_t flags)
{
	static int i = 0;
	PRINTF("R: %s\n", Encoder_right.updated ? "true" : "false");
	PRINTF("L: %s\n", Encoder_left.updated ? "true" : "false");

	if(!Encoder_right.updated)
		HandleNoEncoderSignal(&Encoder_right);

	if(!Encoder_left.updated)
		HandleNoEncoderSignal(&Encoder_left);

	Encoder_right.updated = false;
	Encoder_left.updated = false;
	i++;
	CTIMER0->MR[0] = i * 500000 ;
//	CTIMER_StopTimer(CTIMER0, kCTIMER_Timer0);
//	CTIMER0->TCR |= CTIMER_TCR_CRST_MASK;  // Set CRST bit to reset the timer
//	CTIMER0->TCR &= ~CTIMER_TCR_CRST_MASK; // Clear CRST bit to resume normal operation
//	CTIMER_StartTimer(CTIMER0, kCTIMER_Timer0);

}

void HandleNoEncoderSignal(volatile Encoder* encoder)
{
	 // Reset RPM values to 0
	    encoder->RPM = 0.0f;
	    encoder->RPM_prev = 0.0f;

}
