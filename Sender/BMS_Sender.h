#include <stdio.h>

#define SOC_MIN 20
#define SOC_MAX 80
#define TEMP_MIN 5
#define TEMP_MAX 45
/*
#define SENSOR1 1
#define SENSOR2 2

#define SENSOR_FILE1 "sensor1.csv"
#define SENSOR_FILE2 "sensor2.csv"
#define SENSOR_PATH(sensor_id) SENSOR_FILE ## sensor_id 
*/
#define MAX_STREAMING_RANGE 50

typedef struct BMSData
{
	int temp;
	int soc;
}BMSData;


int getSensorData(const char* sensor_path, BMSData* BMS_Data);
void PrintBMSData(int sensor_id, BMSData* BMS_Data, int readings);
void PrintToConsole(char* buffer);


