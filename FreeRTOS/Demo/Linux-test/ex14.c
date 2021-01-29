/* Standard includes. */
#include <stdio.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

void vTask1_ex14(void *pvParameters);
void vTask2_ex14(void *pvParameters);

xSemaphoreHandle xCountingSemaphore;

void main_ex14(void)
{
	xCountingSemaphore = xSemaphoreCreateCounting(10, 0);

	
	if (xCountingSemaphore != NULL)
	{
		xTaskCreate(vTask1_ex14, "Task1", 1000, NULL, 3, NULL);
		printf("Handler Task Created!\r\n\n");

		xTaskCreate(vTask2_ex14, "Task2", 1000, NULL, 1, NULL);
		printf("Periodic Task Created!\r\n\n");
	}

	printf("Scheduler Started!\r\n\n");
	vTaskStartScheduler();

	while (1);
}

void vTask1_ex14(void *pvParameters)
{
	for (;;)
	{
		printf("Handler task is running!.\r\n");

		xSemaphoreTake(xCountingSemaphore, portMAX_DELAY);

		printf("Handler task - Processing event.\r\n\n");
	}
}


void vTask2_ex14(void *pvParameters)
{
	for (;;)
	{
		printf("Periodic task is running!.\r\n");

		vTaskDelay(500 / portTICK_RATE_MS);

		printf("Periodic task - Giving Semaphore.\r\n\n");

		xSemaphoreGive(xCountingSemaphore);
		xSemaphoreGive(xCountingSemaphore);
		xSemaphoreGive(xCountingSemaphore);
	}
}