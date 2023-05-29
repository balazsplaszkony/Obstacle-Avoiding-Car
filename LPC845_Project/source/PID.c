#include "PID.h"

	PidController pid_right;
	PidController pid_left;
	volatile bool pid_updated = false;
void PIDInit(){

	pid_right.Kd = 1.4;//0.465;
	pid_right.Ki = 0.06;//1.145;
	pid_right.Kp = 1.4;
	pid_right.integral = 0.0;
	pid_right.last_error = 0.0;
	pid_right.output = 0.0;
	pid_right.setpoint = 50; //60.0;
	pid_right.motor = motor_right;

	pid_left.Kd = 1.4;
	pid_left.Ki = 0.06;
	pid_left.Kp = 1.4;
	pid_left.integral = 0.0;
	pid_left.last_error = 0.0;
	pid_left.output = 0.0;
	pid_left.setpoint = 50; //60.0;
	pid_left.motor = motor_left;
}

void PIDContollerUpdate(PidController* pid, float measurement){

	float error = pid->setpoint - measurement;

    float proportional = pid->Kp * error;

    pid->integral += pid->Ki * error;

    // Limit the integral term to prevent windup
    LimitIntegralTerm(pid);

    // Reset the integral term if the wheel is stopped intentionally
    ResetIntegralTerm();

    float derivative = pid->Kd * (error - pid->last_error);

    pid->output = proportional + pid->integral + derivative;

    // Limit the output to be within the allowable range
    if (pid->output > MAX_PID_OUTPUT) {
    	pid->output = MAX_PID_OUTPUT;
      }
    else if (pid->output < MIN_PID_OUTPUT) {
    	pid->output = MIN_PID_OUTPUT;
      }
    pid->last_error = error;
}
bool isPIDUpdated()
{
	return pid_updated;
}
void LimitIntegralTerm(PidController* pid)
{
	if (pid->integral > MAX_PID_OUTPUT) {
	            pid->integral = MAX_PID_OUTPUT;
	        }
	    else if (pid->integral < MIN_PID_OUTPUT) {
	            pid->integral = MIN_PID_OUTPUT;
	        }

    // Reset the integral term if the wheel is stopped intentionally
}
void ResetIntegralTerm()
{
    if(car.direction == STOPCAR || car.direction == TURNLEFT)
    	pid_right.integral = 0;

    if(car.direction == STOPCAR || car.direction == TURNRIGHT)
    	pid_left.integral = 0;
}
void ResetController()
{
	pid_right.integral = 0;
	pid_left.integral = 0;
}

int RoundPIDOutput(float output)
{
	float decimal = output- floor(output);

	if(decimal > 0.5)
		decimal = (int) 1;
	else
		decimal = (int) 0;
	return decimal + (int) output;
}
float ScaleUpRPM(float rpm){
	return (rpm/MAX_RPM)*MAX_PID_OUTPUT;
}
void PIDTIMERHandler(){
	static int counter = 0;
	if(counter == 0)
	{
		pid_left.setpoint = 60;
		pid_right.setpoint = 60;
	}
//	if(counter == 1000)
//	{
//		pid_left.setpoint = 100;
//		pid_right.setpoint = 100;
//	}
	static uint8_t consecutiveMeasurementsLeft = 0;
	    static uint8_t consecutiveMeasurementsRight = 0;
//	    static float prevRpmLeft = 0.0f;
//	    static float prevRpmRight = 0.0f;
    	__disable_irq();
    	float rpm_left = Encoder_left.RPM;
    	float rpm_right = Encoder_right.RPM;
    	__enable_irq();
    	if (Encoder_right.updated == false) {
    	        consecutiveMeasurementsLeft++;
    	        if (consecutiveMeasurementsLeft >= NUM_CONSECUTIVE_MEASUREMENTS) {
    	            Encoder_left.RPM = 0.0f; // Reset RPM value
    	            rpm_left = 0.0f;
    	            consecutiveMeasurementsLeft = 0; // Reset consecutive measurements counter
    	        }
    	    } else {
    	        consecutiveMeasurementsLeft = 0; // Reset consecutive measurements counter
    	        Encoder_left.updated = false;

    	    }
    	    //prevRpmLeft = rpm_left;

    	    if (Encoder_right.updated == false) {
    	        consecutiveMeasurementsRight++;
    	        	if (consecutiveMeasurementsRight >= NUM_CONSECUTIVE_MEASUREMENTS) {
    	            Encoder_right.RPM = 0.0f; // Reset RPM value
    	            rpm_right = 0.0f;
    	            consecutiveMeasurementsRight = 0; // Reset consecutive measurements counter
    	        }
    	    } else {
    	        consecutiveMeasurementsRight = 0; // Reset consecutive measurements counter
    	        Encoder_right.updated = false;
    	    }
    	    //prevRpmRight = rpm_right;

        PIDContollerUpdate(&pid_right, rpm_right);
        PIDContollerUpdate(&pid_left, rpm_left);
        //pid_updated = true;
		 SetPWM(RoundPIDOutput(pid_right.output), &motor_right);
		 SetPWM(RoundPIDOutput(pid_left.output), &motor_left);
//        PRINTF("%d,%d,%d,%d,%d, \n", (int)rpm_left, (int)rpm_right,
//    		(int)pid_left.output, (int)pid_right.output, (int)pid_right.setpoint);

        counter++;
        counter = counter % 2000;
}
