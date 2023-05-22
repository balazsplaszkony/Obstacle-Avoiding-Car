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
#include <stdint.h>
#include "car.h"

/* Allowable PWM duty cycle is between 40% and 80%
 * For higher resolution it's scaled up to between 400 and 800
*/

#define MAXOUTPUT 700.0
#define MINOUTPUT 0.0

#define MAX_PID_OUTPUT (MAXOUTPUT - MINOUTPUT)//400.0
#define PID_OUTPUT_OFFSET (MINOUTPUT) //400.0
#define MIN_PID_OUTPUT 0.0
#define MAX_RPM 300.0 //üresjárásban ennyi
#define NUM_CONSECUTIVE_MEASUREMENTS 3


extern volatile bool pid_updated;
typedef struct {
    float Kp;
    float Ki;
    float Kd;
    float setpoint;
    float integral;
    float last_error;
    float output;
    Motor motor;
//    float min_output;
//    float max_output;
//    float output_offset;
} PidController;

extern PidController pid_right;
extern PidController pid_left;

bool isPIDUpdated();
void PIDContollerUpdate(PidController* pid, float measurement);
void PIDInit();
int RoundPIDOutput(float output);
float ScaleUpRPM(float rpm);
void PIDTIMERHandler();

#endif /* PID_H_ */
