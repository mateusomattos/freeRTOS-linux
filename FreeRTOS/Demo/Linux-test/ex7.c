/* Standard includes. */
#include <stdio.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

void vTask1_ex7(void *pvParameters);
void vTask2_ex7(void *pvParameters);
void vTask3_ex7(void *pvParameters);

void main_ex7(void)
{
	xTaskCreate(vTask1_ex7, "Task1", 100, NULL, 1, NULL);
	printf("Task 1 Created!\r\n\n");

	xTaskCreate(vTask2_ex7, "Task2", 100, NULL, 1, NULL);
	printf("Task 2 Created!\r\n\n");

	xTaskCreate(vTask3_ex7, "Task3", 100, NULL, 2, NULL);
	printf("Task 3 Created!\r\n\n");

	printf("Scheduler Started!\r\n\n");
	vTaskStartScheduler();

	while (1);
}

void vTask1_ex7(void *pvParameters)
{
	unsigned int ui;
	unsigned long ul;

	printf("Task 1 first time!\r\n\n");

	for (;;)
	{
		printf("Task 1 is running\r\n");
		for (ui = 0; ui < 3; ui++)
		{
			for (ul = 0; ul < 10000000; ul++)
			{
				/////
			}
		}
	}
}


void vTask2_ex7(void *pvParameters)
{
	unsigned int ui;
	unsigned long ul;

	printf("Task 2 first time!\r\n\n");

	for (;;)
	{
		printf("Task 2 is running\r\n");
		for (ui = 0; ui < 3; ui++)
		{
			for (ul = 0; ul < 10000000; ul++)
			{
				/////
			}
		}
	}
}

void vTask3_ex7(void *pvParameters)
{
	portTickType xLastWakeTime;

	printf("Task 3 first time!\r\n\n");

	xLastWakeTime = xTaskGetTickCount();

	for (;;)
	{
		printf("Task 3 is running\r\n");

		vTaskDelayUntil(&xLastWakeTime, (250/ portTICK_RATE_MS));

	}
}