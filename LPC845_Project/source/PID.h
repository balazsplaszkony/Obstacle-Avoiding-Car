/*
 * PID.h
 *
 *  Created on: 2023. márc. 27.
 *      Author: plasz
 */

#ifndef PID_H_
#define PID_H_
#include <stdbool.h>
#include <math.h>

/* Allowable PWM duty cycle is between 40% and 80%
 * For higher resolution it's scaled up to between 400 and 800
*/
#define MAX_PID_OUTPUT 400
#define MIN_PID_OUTPUT 800

extern volatile bool updated;
typedef struct {
    float Kp;
    float Ki;
    float Kd;
    float setpoint;
    float integral;
    float last_error;
    float output;
    float min_output;
    float max_output;
} PidController;

extern PidController pid_right;
extern PidController pid_left;

bool isPIDUpdated();
void PIDContollerUpdate(PidController* pid, float measurement);
void PIDInit();
int RoundPIDOutput(float output);

#endif /* PID_H_ */
