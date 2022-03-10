/*
 * Traffic.c
 *
 *  Created on: Sep 9, 2021
 *      Author: Sama Mostafa
 */

int traffic(char *data) { //function control speed using  traffic light
	int speed = 10;
	switch (*data) {
	case 'G':
		speed = 100;
		break;
	case 'O':
		speed = 30;
		break;
	case 'R':
		speed = 0;
		break;
	}
	return speed;
}

