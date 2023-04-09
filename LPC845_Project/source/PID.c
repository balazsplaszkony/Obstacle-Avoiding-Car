#include "PID.h"

	PidController pid_right;
	PidController pid_left;
	volatile bool updated = false;
void PIDInit(){;
//TODO;
}

void PIDContollerUpdate(PidController* pid, float measurement){

	float error = pid->setpoint - measurement;

    float proportional = pid->Kp * error;

    pid->integral += pid->Ki * error;

    float derivative = pid->Kd * (error - pid->last_error);

    pid->output = proportional + pid->integral + derivative;

    pid->last_error = error;
}
bool isPIDUpdated()
{
	return updated;
}
