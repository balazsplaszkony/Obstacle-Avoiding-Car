#include "PID.h"

	PidController pid_right;
	PidController pid_left;
	volatile bool pid_updated = false;
void PIDInit(){;
//TODO;

//pid->max_output =
//
//pid->min_output =
}

void PIDContollerUpdate(PidController* pid, float measurement){

	float error = pid->setpoint - measurement;

    float proportional = pid->Kp * error;

    pid->integral += pid->Ki * error;

    // Limit the integral term to prevent windup
    if (pid->integral > pid->max_output) {
            pid->integral = pid->max_output;
        }
    else if (pid->integral < pid->min_output) {
            pid->integral = pid->min_output;
        }

    float derivative = pid->Kd * (error - pid->last_error);

    pid->output = RoundPIDOutput(proportional + pid->integral + derivative);

    // Limit the output to within the allowable range
    if (pid->output > pid->max_output) {
    	pid->output = pid->max_output;
      }
    else if (pid->output < pid->min_output) {
    	pid->output = pid->min_output;
      }

    pid->last_error = error;
    double x = 1;
    double y =pow(x, 5);

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
