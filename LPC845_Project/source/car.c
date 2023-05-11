/*
 * car.c
 *
 *  Created on: 2023. márc. 28.
 *      Author: plasz
 */


#include "car.h"
Car car;
Car car_prev;

void InitComponents()
{
	InitUltrasonicMeasurement(&ultrasonic_measurement);
	InitOpticMeasurement(&optic_measurement);
	InitMotors();
	UsartBufferInit();
	PIDInit();
	InitEncoders();
}

void InitCar()
{
	car.direction = STOPCAR;
	car.obstacle_avoidance = false;
	car.tempomat = false;
	car.speed = 0;
	car.duty = 0;
	car.is_obstacle_in_the_way = false;
	car.is_car_blocked = false;
	car.collision = false;

	car_prev.direction = STOPCAR;
	car_prev.obstacle_avoidance = false;
	car_prev.tempomat = false;
	car_prev.speed = 0;
	car_prev.duty = 0;
	car_prev.is_obstacle_in_the_way = false;
	car_prev.is_car_blocked = false;
	car_prev.collision = false;
}

void ProcessPrompt()
{
	Car car_new = car;
        char* prompt = buffer.prompt;

		if(strcmp(prompt, "F\0")==0){ //FORWARD
			car_new.direction = GOFORWARD;
			PrintUSART1_NB("OK");
		}

		else if(strcmp(prompt, "B\0")==0){ //BACKWARD
			car_new.direction = GOBACKWARD;
			PrintUSART1_NB("OK");
		}
		else if(strcmp(prompt, "R\0")==0){  //RIGHT
			car_new.direction = TURNRIGHT;
			PrintUSART1_NB("OK");
		}
		else if(strcmp(prompt, "L\0")==0){	//LEFT
			car_new.direction = TURNLEFT;
			PrintUSART1_NB("OK");
		}
		else if(strcmp(prompt, "S\0")==0){	//STOP
			car_new.direction = STOPCAR;
			PrintUSART1_NB("OK");
		}
		else if(strcmp(prompt, "T\0")==0){	//TOGGLE_TEMPOMAT
			car_new.tempomat = (!car_new.tempomat);
			if(car_new.tempomat)
			{
				if((car_new.direction == GOFORWARD || car_new.direction == GOBACKWARD)
					&& car.direction == car_new.direction)
				{
					float rpm_setpoint = ScaleUpSetpoint((Encoder_right.RPM + Encoder_left.RPM)/2.0);
					pid_right.setpoint = rpm_setpoint;
					pid_left.setpoint =  rpm_setpoint;
				}
				else
				{
					pid_right.setpoint = ScaleUpSetpoint(Encoder_right.RPM);
					pid_left.setpoint = ScaleUpSetpoint(Encoder_left.RPM);
				}
				MRT_StartTimer(MRT0_PERIPHERAL, MRT0_CHANNEL_1, MRT0_CHANNEL_1_TICKS);
			}
			else if(!car_new.tempomat)
			{
	          	 MRT_StopTimer(MRT0_PERIPHERAL, MRT0_CHANNEL_1);
			}
			PrintUSART1_NB("OK");
		}
//		else if(strcmp(prompt, "D\0")==0){	//SLOWDOWN
//			if(car_new.tempomat)
//			{
//				car_new.speed -= buffer.parameter;
//				float rpm_setpoint = ScaleUpSetpoint(CalculateRPMfromSpeed(car_new.speed));
//				pid_right.setpoint = rpm_setpoint;
//				pid_left.setpoint =  rpm_setpoint;
//				MRT_StartTimer(MRT0_PERIPHERAL, MRT0_CHANNEL_1, MRT0_CHANNEL_1_TICKS);
//			}
//			else{
//
//			}
//			PrintUSART1_NB("OK");
//		}
//		else if(strcmp(prompt, "U\0")==0){	//SPEEDUP
//			if(car_new.tempomat)
//			{
//				car_new.speed = buffer.parameter;
//				float rpm_setpoint = ScaleUpSetpoint(CalculateRPMfromSpeed(car_new.speed));
//				pid_right.setpoint = rpm_setpoint;
//				pid_left.setpoint =  rpm_setpoint;
//				MRT_StartTimer(MRT0_PERIPHERAL, MRT0_CHANNEL_1, MRT0_CHANNEL_1_TICKS);
//			}
//			else{
//
//			}
//			PrintUSART1_NB("OK");
//		}
		else if(strcmp(prompt, "O\0")==0){	//TOGGLE_OBSTACLE_AVOIDANCE
			car_new.obstacle_avoidance = (!car_new.obstacle_avoidance);
			PrintUSART1_NB("OK");
		}
		else if(strcmp(prompt, "Speed\0")==0){
					if(car.tempomat)
					{
						car_new.speed = buffer.parameter;
						float rpm_setpoint = ScaleUpSetpoint(CalculateRPMfromSpeed(car_new.speed));
						rpm_setpoint = (rpm_setpoint > MAX_PID_OUTPUT) ? rpm_setpoint : MAX_PID_OUTPUT;
						rpm_setpoint = (rpm_setpoint < MIN_PID_OUTPUT) ? rpm_setpoint : MIN_PID_OUTPUT;

						pid_right.setpoint = rpm_setpoint;
						pid_left.setpoint =  rpm_setpoint;
						MRT_StartTimer(MRT0_PERIPHERAL, MRT0_CHANNEL_1, MRT0_CHANNEL_1_TICKS);
					}
					PrintUSART1_NB("OK");
				}
		else if(strcmp(prompt, "Duty\0")==0){
					if(!car.tempomat && (buffer.parameter > MinimalDuty) && (buffer.parameter < MaximumDuty))
						car_new.duty = buffer.parameter;
					PrintUSART1_NB("OK");
						}
		else{
			PrintUSART1_NB("invalid prompt");
		}

	car_prev = car;
	car = car_new;
}
void GoForward()
{
	RotateForward(&motor_right); RotateForward(&motor_left);
}
void GoBackward()
{
	RotateBackward(&motor_right); RotateBackward(&motor_left);
}

void TurnRight()
{
	RotateForward(&motor_right); StopMotor(&motor_left);
}

void TurnLeft()
{
	RotateForward(&motor_left); StopMotor(&motor_right);
}

void TurnRightStationary()
{
	RotateForward(&motor_right); RotateBackward(&motor_left);
}

void TurnLeftStationary()
{
	RotateForward(&motor_left); RotateBackward(&motor_right);
}

void StopCar()
{
	StopMotor(&motor_right); StopMotor(&motor_left);
}

bool isObstacleDetected(){
	return((ultrasonic_measurement.distance_in_cm > UltrasonicTreshold && ultrasonic_measurement.is_valid)
			|| optic_measurement.back_left < OpticTreshold
			|| optic_measurement.back_right < OpticTreshold
			|| optic_measurement.front_left < OpticTreshold
			|| optic_measurement.front_right < OpticTreshold
			);
}

bool isRoadBlockedinEveryDirection()
{
	return((ultrasonic_measurement.distance_in_cm > UltrasonicTreshold && ultrasonic_measurement.is_valid)
			&& optic_measurement.back_left < OpticTreshold
			&& optic_measurement.back_right < OpticTreshold
			&& optic_measurement.front_left < OpticTreshold
			&& optic_measurement.front_right < OpticTreshold
			);
}

//legelso kozelites, ha nem valtozott az irany, sebesseg, de lecsökkent hirtelen az rpm akkor ütközés volt
bool DetectCollision(){
	if((car.direction == car_prev.direction) && ((car.tempomat && car.speed == car_prev.speed) ||
			(!car.tempomat && car.duty == car_prev.duty)) &&
			((abs(Encoder_left.RPM - Encoder_left.RPM_prev) > Maximum_Tolerated_RPM_Drop) ||
			(abs(Encoder_right.RPM - Encoder_right.RPM_prev) > Maximum_Tolerated_RPM_Drop))){
		car.collision = true;
	}
	return car.collision;
}

void SetSpeed(){
	if(car.is_car_blocked)
		return;
	if(car.tempomat)
	{
		 if(isPIDUpdated())
		 {
		 SetPWM(RoundPIDOutput(pid_right.output), &motor_right);
		 SetPWM(RoundPIDOutput(pid_left.output), &motor_left);
		 pid_updated = false;
		 }
	}
	else if(!car.tempomat)
	{
		if(car.duty != car_prev.duty)
		{
			SCTIMER_UpdatePwmDutycycle(SCT0_PERIPHERAL, kSCTIMER_Out_0, car.duty, SCT0_pwmEvent[0]);
			SCTIMER_UpdatePwmDutycycle(SCT0_PERIPHERAL, kSCTIMER_Out_1, car.duty, SCT0_pwmEvent[1]);
		}
	}

}
float CalculateSpeedfromRPM(float rpm)
{
	return (WheelCircumference * rpm) / 60;
}
float CalculateRPMfromSpeed(float speed)
{
	return (speed / WheelCircumference) * 60;
}
