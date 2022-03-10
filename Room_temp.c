/*
 * Room_temp.c
 *
 *  Created on: Sep 9, 2021
 *      Author: Sama Mostafa
 */

float Room(int temp, int *speed, unsigned *AC_room) { //function control room temperature

	float room_temp;
	*AC_room = 0;
	if (temp < 10 || temp > 30) {
		*AC_room = 1;
		room_temp = 20;
	} else {
		*AC_room = 0;
		room_temp = (float) temp;
	}
	return room_temp;
}
