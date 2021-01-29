/* Standard includes. */
#include <stdio.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

xTaskHandle xTask1_ex10Handle;
xTaskHandle xTask2_ex10Handle;

void vTask1_ex10(void *pvParameters);
void vTask2_ex10(void *pvParameters);

void main_ex10(void)
{
	xTaskCreate(vTask1_ex10, "Task1", 1000, NULL, 3, &xTask1_ex10Handle);
	printf("Task 1 Created!\r\n\n");

	xTaskCreate(vTask2_ex10, "Task2", 1000, NULL, 2, &xTask2_ex10Handle);
	printf("Task 2 Created!\r\n\n");

	printf("Scheduler Started!\r\n\n");
	vTaskStartScheduler();

	while (1);
}


void vTask1_ex10(void *pvParameters)
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
			printf("\nDeleting Task2!!!\r\n\n");

			vTaskDelete(xTask2_ex10Handle);
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

void vTask2_ex10(void *pvParameters)
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