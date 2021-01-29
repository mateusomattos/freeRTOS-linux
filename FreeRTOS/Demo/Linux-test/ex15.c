/* Standard includes. */
#include <stdio.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

static void PrintTask(void* pvParameters);
static void PrintString(const char* pcString);

SemaphoreHandle_t xMutex;

int main_ex15(void)
{
	
	xMutex = xSemaphoreCreateMutex();
	if (xMutex != NULL)
	{
		
		xTaskCreate(PrintTask, "Print1", 1000, "1", 1, NULL);
		xTaskCreate(PrintTask, "Print2", 1000, "2", 2, NULL);
		
		vTaskStartScheduler();
	}
	
	for (;; );
}


static void PrintTask(void* pvParameters)
{
	char* StringToPrint;
	
	StringToPrint = (char*)pvParameters;
	for (;; )
	{
		
		PrintString(StringToPrint);
	
		vTaskDelay(10);
	}
}

static void PrintString(const char* pcString)
{
	unsigned int ui;
	unsigned long ul;

	//xSemaphoreTake(xMutex, portMAX_DELAY);
	for (ui = 0; ui < 100; ui++)
	{
		printf("%s", pcString);
		for (ul = 0; ul < 100000; ul++)
		{

		}
	}
	
	printf("\r\n\r\n\r\n");	
	//xSemaphoreGive(xMutex);
}