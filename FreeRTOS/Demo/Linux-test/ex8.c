/* Standard includes. */
#include <stdio.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

xTaskHandle xTask1_ex8Handle;
xTaskHandle xTask2_ex8Handle;

void vTask1_ex8(void *pvParameters);
void vTask2_ex8(void *pvParameters);

void main_ex8(void)
{
	xTaskCreate(vTask1_ex8, "Task1", 1000, NULL, 2, &xTask1_ex8Handle);
	printf("Task 1 Created!\r\n\n");

	xTaskCreate(vTask2_ex8, "Task2", 1000, NULL, 1, &xTask2_ex8Handle);
	printf("Task 2 Created!\r\n\n");

	printf("Scheduler Started!\r\n\n");
	vTaskStartScheduler();

	while (1);
}


void vTask1_ex8(void *pvParameters)
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
			printf("\nRising Task2 priority!!!\r\n\n");

			vTaskPrioritySet(xTask2_ex8Handle, (uxPriority + 1));
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

void vTask2_ex8(void *pvParameters)
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