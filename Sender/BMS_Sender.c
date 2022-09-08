#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "BMS_Sender.h"

int getSensorData(const char* sensor_path, BMSData* BMS_Data)
{
	char row[12];
	char* value;
	int readings;

	FILE* fp = fopen(sensor_path, "r");

	if (!fp)
	{
		printf("Unable to open file\n");
		assert(0);
	}

	for(readings = 0; (fgets(row,12, fp)) && (readings < MAX_STREAMING_RANGE); readings++)
	{
			value = strtok(row, ",");
			BMS_Data[readings].temp = atoi(value);
			value = strtok(NULL, ", ");
			BMS_Data[readings].soc = atoi(value);
	}

	fclose(fp);
	return readings;

}

void PrintBMSData(int sensor_id, BMSData* BMS_Data, int readings)
{
	char buffer[350] = {0};
	char* next_addr = buffer;
	int count;

	for(count = 0; count < readings; count++)
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

/*int main()
{
	struct BMSData BMS_Data[50];
	int readingCount;
	int sensor_id=1;
	const char* sensor1_path = "sensor1.csv";

	readingCount = getSensorData(sensor1_path, BMS_Data);
	PrintBMSData(sensor_id, BMS_Data, readingCount);
}
*/
