/*
 * control_system.c
 *
 *  Created on: Sep 6, 2021
 *      Author: Sama Mostafa
 */
#include<stdio.h>
#include "project1.h"
#include <stdlib.h>
char engine_opt;
void control(char *opt) {//control start options
	switch (*opt) {
	case 'a':
		printf("The engine is turned on\n");

		break;
	case 'b':
		printf("The  vehicle engine is turned off\n");
		exit(0);
		break;
	case 'c':
		printf("the program has been quit");
		exit(0);
		break;
	default:
		printf("invalid");
	}
}

