#include <stdio.h>
#include <assert.h>
#include "BMS_Sender.h"

void test_getSensorData(void)
{
	struct BMSData BMS_Data[50];

	getRandomSensorData(BMS_Data);

	assert(BMS_Data[10].temp <= TEMP_MAX);
	assert(BMS_Data[5].temp  >= TEMP_MIN);
	assert(BMS_Data[45].soc  <= SOC_MAX);
	assert(BMS_Data[1].soc   >= SOC_MIN);
}

int main()
{
	test_getSensorData();
}


