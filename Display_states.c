/*
 * Display_states.c
 *
 *  Created on: Sep 9, 2021
 *      Author: Sama Mostafa
 */
#include "project1.h"
#include <stdio.h>
#define WITH_ENGINE_TEMP_CONTROLLER 1
void display_states(float *temp_room, float *temp_eng, unsigned *AC_data,
		unsigned *Eng_data, int *traffic_data) { //function to display engine states
	printf("The vehicle speed is = %d  Km/hr \n", *traffic_data);
	if (*traffic_data == 30) { //use to turn on AC when vehicle speed =30 km/hr and set room temperature
		*AC_data = 1;
		*temp_room = *temp_room * (5.0 / 4) + 1;
		printf("The room temperature is %.1f c\n", *temp_room);
	} else {
		printf("The room temperature is %.1f c\n", *temp_room);
	}

#if( WITH_ENGINE_TEMP_CONTROLLER ==1)
	if (*traffic_data == 30) { //use to turn on Engine controller on when vehicle speed =30 km/hr and set vehicle temperature
		*Eng_data = 1;
		*temp_eng = *temp_eng * (5.0 / 4) + 1;
		printf("The engine temperature is %.1f c\n", *temp_eng);
	} else {
		printf("The engine temperature is %.1f c\n", *temp_eng);
	}
#endif
	if (*AC_data == 0) { // AC is turned off
		printf("The AC is turned off\n");
	} else if (*AC_data == 1) { //Ac is turned on
		printf("The AC is turned on\n");
	}
#if( WITH_ENGINE_TEMP_CONTROLLER== 1)
	if (*Eng_data == 0) { //engine is turned off
		printf("The engine is turned off\n");
	} else if (*Eng_data == 1) { //engine is turned on
		printf("The engine is turned on\n");
	}
#endif

}

