/*
 * PID.h
 *
 *  Created on: 2023. márc. 27.
 *      Author: plasz
 */

#ifndef PID_H_
#define PID_H_
#include <stdbool.h>

extern volatile bool updated;
typedef struct {
    float Kp;
    float Ki;
    float Kd;
    float setpoint;
    float integral;
    float last_error;
    float output;
} PidController;

extern PidController pid_right;
extern PidController pid_left;

bool isPIDUpdated();
void PIDContollerUpdate(PidController* pid, float measurement);
void PIDInit();


#endif /* PID_H_ */
