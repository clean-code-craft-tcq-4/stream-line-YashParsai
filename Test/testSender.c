#include <stdio.h>
#include "../Sender/BMS_Sender.h"

int dummyTemp[5] = {5,6,7,8,9};
int dummySOC[5] = {20,21,22,23,24};

int main()
{
	test_getSensorData();
}

void test_getSensorData(void)
{
	const char* sensor_path = "testSensor.csv";
	struct BMSData BMS_Data[50];

	readingCount = getSensorData(sensor1_path, BMS_Data);

	for(i=0;i<5;i++ )
	{
		if(!((BMS_Data[i].temp == dummyTemp[i]) &&
		     (BMS_Data[i].soc  == dummySOC[i])  ))
		{
			assert(0);
		}
	}
}
