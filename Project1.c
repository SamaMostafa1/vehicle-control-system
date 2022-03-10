/*
 * Project1.c
 *
 *  Created on: Sep 6, 2021
 *      Author: Sama Mostafa
 */
#include <stdio.h>
#include "project1.h"
#define WITH_ENGINE_TEMP_CONTROLLER 1
typedef enum {
	off = 0, on = 1
} data;

int main(void) {
	setbuf(stdout, NULL);
	data AC_temp = off, Engine_temp = off;
	char option, engine_opt, trafficdata, option_off, option_b;
	int room_temp = 27, eng_temp = 110;
	int speed_vec;
	float roomtemp, enginetemp;
	display(); //display start menu
	scanf(" %c", &option);
	if (option == 'b') { // if  input is b  user need to enter new input again  equal b to turn off engine
		printf("Choose again to turn off the engine  \n");
		display();
		scanf(" %c", &option);
		control(&option); //function that control star menu options
	} else {
		control(&option);
	}
	while (option == 'a') { //while loop is used as long as input is 'a' display menu to choose engine options
		Engine_displaymenu();
		scanf(" %c", &engine_opt);
		switch (engine_opt) { //To choose engine option

		case 'a': // case 'a'  the engine is turned off we need to display the start menu again
			printf("The engine is turned off\n");
			display(); //display star menu again
			scanf(" %c", &option_off);
			if (option_off == 'b') { //To check  input is b  user need to enter new input again  equal b to turn off engine
				printf("Choose again to turn off the engine  \n");
				display();
				scanf(" %c", &option_b);
				control(&option_b);
			} else {
				control(&option_off);

			}
			break;
		case 'b': // case b control traffic light colors
			printf("To set  traffic light color choose one of this colors\n ");
			display_traffic(); //function to display traffic color option
			scanf(" %c", &trafficdata);
			speed_vec = traffic(&trafficdata); // the return of the function that control traffic color is stored in spped_vec
			roomtemp = Room(room_temp, &speed_vec, &AC_temp); //the return of the function that control room temperature is stored in roomtemp
			enginetemp = engine(&eng_temp, &speed_vec, &Engine_temp); //the return of the function that control engine temperature is stored in enginetemp
			display_states(&roomtemp, &enginetemp, &AC_temp, &Engine_temp,
					&speed_vec); //function that display engine state
			break;
		case 'c': //use case c to control room temperature

			printf("please enter room temperature\n ");
			scanf("%d", &room_temp);
			speed_vec = traffic(&trafficdata);
			roomtemp = Room(room_temp, &speed_vec, &AC_temp);
			enginetemp = engine(&eng_temp, &speed_vec, &Engine_temp);
			display_states(&roomtemp, &enginetemp, &AC_temp, &Engine_temp,
					&speed_vec);

			break;
		case 'd': //use case d to control engine  temperature
# if (WITH_ENGINE_TEMP_CONTROLLER==1)
			printf("please enter engine temperature");
			scanf("%d", &eng_temp);
			speed_vec = traffic(&trafficdata);
			enginetemp = engine(&eng_temp, &speed_vec, &Engine_temp);
			roomtemp = Room(room_temp, &speed_vec, &AC_temp);
			display_states(&roomtemp, &enginetemp, &AC_temp, &Engine_temp,
					&speed_vec);
			break;
# endif
		default:
			printf("invalid\n");
			break;
		}
	}

}

