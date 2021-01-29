/* Standard includes. */
#include <stdio.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

void vTask_ex3(void *pvParameters);

void main_ex3(void)
{
	xTaskCreate(vTask_ex3, "Task1", 1000, "Task 1", 1, NULL);
	printf("Task 1 Created!\r\n\n");

	xTaskCreate(vTask_ex3, "Task2", 1000, "Task 2", 1, NULL);
	printf("Task 2 Created!\r\n\n");

	printf("Scheduler Started!\r\n\n");
	vTaskStartScheduler();

	while (1);
}

void vTask_ex3(void *pvParameters)
{
	unsigned int ui;
	unsigned long ul;

	char *pcTaskName;

	pcTaskName = (char *)pvParameters;

	printf("%s first time!\r\n\n", pcTaskName);

	for (;;)
	{
		printf("%s is running\r\n", pcTaskName);

		for (ui = 0; ui < 3; ui++)
		{
			for (ul = 0; ul < 10000000; ul++)
			{
				/////
			}
		}
	}
}