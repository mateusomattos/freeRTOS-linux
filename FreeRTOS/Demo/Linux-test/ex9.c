/* Standard includes. */
#include <stdio.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

xTaskHandle xTask1_ex9Handle;
xTaskHandle xTask2_ex9Handle;

void vTask1_ex9(void *pvParameters);
void vTask2_ex9(void *pvParameters);

void main_ex9(void)
{
	xTaskCreate(vTask1_ex9, "Task1", 1000, NULL, 3, &xTask1_ex9Handle);
	printf("Task 1 Created!\r\n\n");

	xTaskCreate(vTask2_ex9, "Task2", 1000, NULL, 2, &xTask2_ex9Handle);
	printf("Task 2 Created!\r\n\n");

	printf("Scheduler Started!\r\n\n");
	vTaskStartScheduler();

	while (1);
}


void vTask1_ex9(void *pvParameters)
{

	unsigned int ui;
	unsigned long ul;

	int count = 0;
	unsigned portBASE_TYPE uxPriority;

	printf("Task 1 first time!\r\n\n");

	uxPriority = uxTaskPriorityGet(NULL);

	for (;;)
	{
		printf("Task 1 is running\r\n");

		if (++count == 5)
		{
			printf("\nLowering Task1 priority!!!\r\n\n");

			vTaskPrioritySet(NULL, (uxPriority - 1));
		}

		if (count == 10)
		{
			printf("\nLowering Task1 priority!!!\r\n\n");

			vTaskPrioritySet(NULL, (uxPriority - 2));
		}

		for (ui = 0; ui < 3; ui++)
		{
			for (ul = 0; ul < 10000000; ul++)
			{
				/////
			}
		}
	}
}

void vTask2_ex9(void *pvParameters)
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