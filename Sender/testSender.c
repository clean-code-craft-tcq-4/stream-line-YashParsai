#include <stdio.h>
#include <assert.h>
#include "BMS_Sender.h"

void test_getSensorData(void)
{
	const char* testsensor_path = "testSensor.csv";
	struct BMSData BMS_Data[50];
	int readingCount;
	int i;

	getRandomSensorData(BMS_Data);

	assert(BMS_Data.temp[10] <= TEMP_MAX);
	assert(BMS_Data.temp[5]  >= TEMP_MIN);
	assert(BMS_Data.soc[45]  <= SOC_MAX);
	assert(BMS_Data.soc[1]  >= SOC_MIN);
}

int main()
{
	test_getSensorData();
}


