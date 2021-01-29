/* Standard includes. */
#include <stdio.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include <time.h>



void filosofo(void *pvParameters);


SemaphoreHandle_t garfo[5];

int maxLen = 1000000;

int main_t2(void)
{
	int i;
	for (i = 0; i < 5; i++) {
		garfo[i] = xSemaphoreCreateMutex();
	}

	xTaskCreate(filosofo, "F0", 1000, (void *)0, 1, NULL);
	xTaskCreate(filosofo, "F1", 1000, (void *)1, 1, NULL);
    xTaskCreate(filosofo, "F2", 1000, (void *)2, 1, NULL);
    xTaskCreate(filosofo, "F3", 1000, (void *)3, 1, NULL);
    xTaskCreate(filosofo, "F4", 1000, (void *)4, 1, NULL);
	
	vTaskStartScheduler();
	
	for (;; );
}


void filosofo(void *pvParameters){

    int idInt = (int) pvParameters;

    for(;;) {

        unsigned int ui;
	    unsigned long ul;
      
        printf("Filosofo %d  COM FOME\n", idInt);
        if (idInt == 4) {
            xSemaphoreTake(garfo[(0)], portMAX_DELAY);
            xSemaphoreTake(garfo[(idInt)], portMAX_DELAY);
        } else {
            xSemaphoreTake(garfo[(idInt)], portMAX_DELAY);
            xSemaphoreTake(garfo[(idInt+1)], portMAX_DELAY);
        }

        

        printf("Filosofo %d   COMENDO\n", idInt);

        srand(time(NULL)); 
        int randVezes = rand(); 

        for (ui = 0; ui < randVezes%5000; ui++)
        {
            for (ul = 0; ul < maxLen; ul++)
            {

            }
        }

        if (idInt == 4) {
            xSemaphoreGive(garfo[0]);
            xSemaphoreGive(garfo[(idInt)]);
        } else {
            xSemaphoreGive(garfo[(idInt)]);
            xSemaphoreGive(garfo[(idInt+1)]);
        }	
        printf("\n");
        printf("Filosofo %d  PENSANDO\n\n", idInt);
        srand(time(NULL)); 
        int dd = rand(); 
        vTaskDelay((dd%5000) / portTICK_RATE_MS);
    }


}

