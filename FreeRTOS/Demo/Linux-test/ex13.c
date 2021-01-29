/* Standard includes. */
#include <stdio.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

void vTask1_ex13(void *pvParameters);
void vTask2_ex13(void *pvParameters);

xSemaphoreHandle xBinarySemaphore;

void main_ex13(void)
{
	vSemaphoreCreateBinary(xBinarySemaphore);

	xSemaphoreTake(xBinarySemaphore, 0); // Como o semaforo e inicializado como desbloqueado.

	if (xBinarySemaphore != NULL)
	{
		xTaskCreate(vTask1_ex13, "Task1", 1000, NULL, 3, NULL);
		printf("Handler Task Created!\r\n\n");

		xTaskCreate(vTask2_ex13, "Task2", 1000, NULL, 1, NULL);
		printf("Periodic Task Created!\r\n\n");
	}

	
	printf("Scheduler Started!\r\n\n");
	vTaskStartScheduler();

	while (1);
}

void vTask1_ex13(void *pvParameters)
{
	for (;;)
	{		
		printf("Handler task is running!.\r\n");

		xSemaphoreTake(xBinarySemaphore, portMAX_DELAY);

		printf("Handler task - Processing event.\r\n\n");
	}
}


void vTask2_ex13(void *pvParameters)
{
	for (;;)
	{
		printf("Periodic task is running!.\r\n");

		vTaskDelay(500 / portTICK_RATE_MS);

		printf("Periodic task - Giving Semaphore.\r\n");
		xSemaphoreGive(xBinarySemaphore);		

	}
}