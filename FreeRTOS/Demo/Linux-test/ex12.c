/* Standard includes. */
#include <stdio.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

void vTask1_ex12(void *pvParameters); // Sender
void vTask2_ex12(void *pvParameters); // Receiver

xQueueHandle xQueue;

typedef struct
{
	unsigned char ucValue;
	unsigned char ucSource;
} xData;

/* Declare two variables of type xData that will be passed on the queue. */
static const xData xStructsToSend[2] =
{
	{ 100, 1 }, /* Used by Sender1. */
	{ 200, 2 } /* Used by Sender2. */
};

void main_ex12(void)
{
	xQueue = xQueueCreate(3, sizeof(xData)); // Cria a fila com tamanho 3 e com capacidade para variaveis do tipo long

	if (xQueue != NULL)
	{
		xTaskCreate(vTask1_ex12, "Sender1", 1000, &(xStructsToSend[0]), 2, NULL); // Cria uma instancia da task sender que enviara o parametro 100.
		printf("Sender 1 Created!\r\n\n");

		xTaskCreate(vTask1_ex12, "Sender2", 1000, &(xStructsToSend[1]), 2, NULL); // Cria uma instancia da task sender que enviara o parametro 200.
		printf("Sender 2 Created!\r\n\n");

		xTaskCreate(vTask2_ex12, "Receiver", 1000, NULL, 1, NULL); // Cria uma instancia da task receiver.
		printf("Receiver Created!\r\n\n");
	}
	else
	{
		printf("The queue could not be created.\r\n");
	}

	printf("Scheduler Started!\r\n\n");
	vTaskStartScheduler();

	while (1);
}

void vTask1_ex12(void *pvParameters)
{
	portBASE_TYPE xStatus;
	const portTickType xTicksToWait = 100 / portTICK_RATE_MS;

	for (;;)
	{
		xStatus = xQueueSendToBack(xQueue, pvParameters, xTicksToWait); // A opcao e por bloquear durante 100 ms

		if (xStatus != pdPASS)
		{
			printf("Could not send to the queue.\r\n");
		}

		taskYIELD(); // Forca o scheduler a trocar para outra task
	}
}


void vTask2_ex12(void *pvParameters)
{
	xData xReceivedStructure;
	portBASE_TYPE xStatus;
	
	for (;;)
	{
		// Testa se realmente existem tres mensagens na fila.

		if (uxQueueMessagesWaiting(xQueue) != 3)
		{
			printf("Queue should have been full!\r\n");
		}

		xStatus = xQueueReceive(xQueue, &xReceivedStructure, 0);

		if (xStatus == pdPASS)
		{
			if (xReceivedStructure.ucSource == 1)
			{
				printf("From Sender 1 = %d \r\n", xReceivedStructure.ucValue);
			}
			else
			{
				printf("From Sender 2 = %d \r\n", xReceivedStructure.ucValue);
			};
		}
		else
		{
			printf("Could not receive from the queue.\r\n");
		}
	}
}