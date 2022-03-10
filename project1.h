/*
 * project1.h
 *
 *  Created on: Sep 8, 2021
 *      Author: Sama Mostafa
 */

void display();
void Engine_displaymenu();
void control(char *opt);
void display_traffic();
void enginecontrol(char *engine_opt);
int traffic(char *data);
float Room(int temp, int *speed, unsigned *AC_room);
float engine(int *temp, int *speed, unsigned *temp_control);
void display_states(float *temp_room, float *temp_eng, unsigned *AC_data,
		unsigned *Eng_data, int *traffic_data);
