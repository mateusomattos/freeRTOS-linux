/* Standard includes. */
#include <stdio.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

void vTask1_ex1(void *pvParameters);
void vTask2_ex1(void *pvParameters);

void main_ex1(void)
{
	xTaskCreate(vTask1_ex1, "Task1", 1000, NULL, 1, NULL);
	printf("Task 1 Created!\r\n\n");

	xTaskCreate(vTask2_ex1, "Task2", 1000, NULL, 1, NULL);
	printf("Task 2 Created!\r\n\n");

	printf("Scheduler Started!\r\n\n");
	vTaskStartScheduler();

	while (1);
}

void vTask1_ex1(void *pvParameters)
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
				
			}
		}	
	}
}


void vTask2_ex1(void *pvParameters)
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

			}
		}
	}
}