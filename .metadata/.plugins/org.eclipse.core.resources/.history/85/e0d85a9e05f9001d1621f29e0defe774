/*
 * servo.c
 *
 *  Created on: 2023. ápr. 11.
 *      Author: plasz
 */

#include "servo.h"

volatile bool servo_turn_finished = false;

//Ezt az egészet simán át fogom szervezni egy függvénybe, és egy enum lesz a paraméter

void LookToTheRight()
{
	  uint32_t primask = DisableGlobalIRQ();
	  MRT_StartTimer(MRT0_PERIPHERAL, MRT0_CHANNEL_2, MRT0_CHANNEL_2_TICKS);
	  //look to the right
	  MRT_StartTimer(MRT0_PERIPHERAL, MRT0_CHANNEL_3, 60000);
	  GPIO_PinWrite(GPIO, 0U, BOARD_INITPINS_Servo_PIN, 1);
	  EnableGlobalIRQ(primask);

}
void LookToTheLeft()
{
	  uint32_t primask = DisableGlobalIRQ();
	  MRT_StartTimer(MRT0_PERIPHERAL, MRT0_CHANNEL_2, MRT0_CHANNEL_2_TICKS);
	  //look to the right
	  MRT_StartTimer(MRT0_PERIPHERAL, MRT0_CHANNEL_3, 30000);
	  GPIO_PinWrite(GPIO, 0U, BOARD_INITPINS_Servo_PIN, 1);
	  EnableGlobalIRQ(primask);
}
void LookStraight()
{
	  uint32_t primask = DisableGlobalIRQ();
	  MRT_StartTimer(MRT0_PERIPHERAL, MRT0_CHANNEL_2, MRT0_CHANNEL_2_TICKS);
	  //look to the right
	  MRT_StartTimer(MRT0_PERIPHERAL, MRT0_CHANNEL_3, 45000);
	  GPIO_PinWrite(GPIO, 0U, BOARD_INITPINS_Servo_PIN, 1);
	  EnableGlobalIRQ(primask);

}

