#include <stdio.h>

#define SOC_MIN 20
#define SOC_MAX 80
#define TEMP_MIN 5
#define TEMP_MAX 45

#define MAX_STREAMING_RANGE 50

typedef struct BMSData
{
	int temp;
	int soc;
}BMSData;


void getRandomSensorData(BMSData* BMS_Data);
void PrintBMSData(int sensor_id, BMSData* BMS_Data, int readings);
void PrintToConsole(char* buffer);
