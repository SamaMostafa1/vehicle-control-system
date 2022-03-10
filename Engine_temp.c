/*
 * Engine_temp.c
 *
 *  Created on: Sep 9, 2021
 *      Author: Sama Mostafa
 */
#define WITH_ENGINE_TEMP_CONTROLLER 1

float engine(int *temp, int *speed, unsigned *temp_control) { //function control engine temperature
	float eng_temp;
#if( WITH_ENGINE_TEMP_CONTROLLER==1)

	if (((*temp) < 100) || ((*temp) > 150)) {
		*temp_control = 1;
		eng_temp = 125;
	} else {
		*temp_control = 0;
		eng_temp = (float) (*temp);
	}
#endif
	return eng_temp;
}

