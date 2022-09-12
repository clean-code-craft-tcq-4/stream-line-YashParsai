#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "BMS_Sender.h"

void getRandomSensorData(BMSData* BMS_Data)
{
	for(int index = 0; index < MAX_STREAMING_RANGE ; index++)
	{
		BMS_Data[index]->temp = (rand()%(TEMP_MAX - TEMP_MIN + 1)) + TEMP_MIN;
		BMS_Data[index]->soc = (rand()%(SOC_MAX - SOC_MIN + 1)) + SOC_MIN;
	}
}
void PrintBMSData(int sensor_id, BMSData* BMS_Data, int readings)
{
	char buffer[350] = {0};
	char* next_addr = buffer;
	int count;

	for(count = 0; count < readings ; count++)
	{
		sprintf(next_addr,"%d,%d,%d\n", sensor_id, BMS_Data[count].temp, BMS_Data[count].soc);
		next_addr = strchr(buffer,0);
	}

	PrintToConsole(buffer);
}

void PrintToConsole(char* buffer)
{
	printf("%s",buffer);
}
