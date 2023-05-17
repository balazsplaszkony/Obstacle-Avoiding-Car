#include "ultrasonic.h"
volatile uint32_t capture_value_0 = 0;
volatile uint32_t capture_value_1 = 0;
volatile uint32_t microseconds_elapsed = 0;
volatile UltraSonicMeasurement ultrasonic_measurement;

void InitUltrasonicMeasurement(volatile UltraSonicMeasurement* ultrasonic_measurement)
{
	ultrasonic_measurement->distance_in_cm = 400;
	ultrasonic_measurement->is_valid = false;
	ultrasonic_measurement->status = START;
}

void UltrasonicMeasure()
 {
	 switch(ultrasonic_measurement.status){
	 case START: TriggerUltrasonicSensor(); break;
	 case TRIG: if(TimeoutDone1()){ EndTriggerUltrasonicSensor();} break;
	 case WAITFIRSTIT: break;
	 case WAITSECONDIT: if(TimeoutDone2()){ InvalidateMeasurement();} break;
	 }
 }

void TriggerUltrasonicSensor(){
	GPIO_PinWrite(BOARD_INITPINS_UltraSonicTrig_GPIO, BOARD_INITPINS_UltraSonicTrig_PORT, BOARD_INITPINS_UltraSonicTrig_PIN, 1);
	ultrasonic_measurement.status = TRIG;
	StartTimeout1(2);
}

void EndTriggerUltrasonicSensor()
{
	ultrasonic_measurement.status = WAITFIRSTIT;
	GPIO_PinWrite(BOARD_INITPINS_UltraSonicTrig_GPIO, BOARD_INITPINS_UltraSonicTrig_PORT, BOARD_INITPINS_UltraSonicTrig_PIN, 0);
	StartTimeout2(30);
}

void InvalidateMeasurement(){
	ultrasonic_measurement.status = START;
	ultrasonic_measurement.is_valid = false;
}

void Ultrasonic_Callback(uint32_t flags) {
	if (ultrasonic_measurement.status == WAITFIRSTIT)
		{
         capture_value_0 = CTIMER0->CR[0];
        ultrasonic_measurement.status = WAITSECONDIT;
        return;
		}

    if (ultrasonic_measurement.status == WAITSECONDIT) {
         capture_value_1 = CTIMER0->CR[0];
        if (capture_value_1 > capture_value_0) {
            microseconds_elapsed = capture_value_1 - capture_value_0;
        } else {
            microseconds_elapsed = capture_value_1 + (UINT32_MAX - capture_value_0) + 1;
        }
        ultrasonic_measurement.distance_in_cm = microseconds_elapsed * (SpeedOfSound / 2);
        ultrasonic_measurement.is_valid = true;
        ultrasonic_measurement.status = START;
    }
}
// for debugging
//  	  	if(ultrasonic_measurement.status == START && ultrasonic_measurement.is_valid)
//  	  	{
//  	  		char str_uh[16];
//  	  		snprintf(str_uh, sizeof(str_uh), "%d", (int)ultrasonic_measurement.distance_in_cm);
//  	  		PRINTF("%s cm\n", str_uh);
//  	  	}
