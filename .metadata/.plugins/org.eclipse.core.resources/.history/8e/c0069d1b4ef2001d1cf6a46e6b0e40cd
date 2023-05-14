#include "PID.h"

	PidController pid_right;
	PidController pid_left;
	volatile bool pid_updated = false;
void PIDInit(){

	pid_right.Kd = 1.0;
	pid_right.Ki = 1.0;
	pid_right.Kp = 1.0;
	pid_right.integral = 0.0;
	pid_right.last_error = 0.0;
	pid_right.output = 0.0;
	pid_right.setpoint = 0.0;

	pid_left.Kd = 1.0;
	pid_left.Ki = 1.0;
	pid_left.Kp = 1.0;
	pid_left.integral = 0.0;
	pid_left.last_error = 0.0;
	pid_left.output = 0.0;
	pid_left.setpoint = 0.0;
}

void PIDContollerUpdate(PidController* pid, float measurement){

	float error = pid->setpoint - measurement;

    float proportional = pid->Kp * error;

    pid->integral += pid->Ki * error;

    // Limit the integral term to prevent windup
    if (pid->integral > MAX_PID_OUTPUT) {
            pid->integral = MAX_PID_OUTPUT;
        }
    else if (pid->integral < MIN_PID_OUTPUT) {
            pid->integral = MIN_PID_OUTPUT;
        }

    float derivative = pid->Kd * (error - pid->last_error);

    pid->output = proportional + pid->integral + derivative;

    // Limit the output to within the allowable range
    if (pid->output > MAX_PID_OUTPUT) {
    	pid->output = MAX_PID_OUTPUT;
      }
    else if (pid->output < MIN_PID_OUTPUT) {
    	pid->output = MIN_PID_OUTPUT;
      }
    pid->output += PID_OUTPUT_OFFSET;
    pid->last_error = error;

}
bool isPIDUpdated()
{
	return pid_updated;
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
float ScaleUpSetpoint(float rpm){
	return (rpm/MAX_RPM)*MAX_PID_OUTPUT;
}
void PIDTIMERHandler(){
    if(1)//car.direction == GOFORWARD)
    {
        PIDContollerUpdate(&pid_right, Encoder_right.RPM);
        PIDContollerUpdate(&pid_left, Encoder_left.RPM);
        pid_updated = true;}
}
