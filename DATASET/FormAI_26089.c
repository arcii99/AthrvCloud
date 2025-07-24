//FormAI DATASET v1.0 Category: Temperature monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float getTemperature() {
    return (float)(rand() % 100 - 20);
}

int main() {
    srand(time(NULL));

    printf("The temperature monitor is booting up.\n");
    printf("Please wait while the sensors calibrate and synchronize...\n");

    float temperature = getTemperature();
    float previousTemperature = temperature;
    int count = 0;
    
    printf("The temperature monitor is now active.\n");

    while(1) {
        temperature = getTemperature();
        printf("Current temperature: %f C\n", temperature);

        if (temperature > previousTemperature + 5) {
            printf("Warning! The temperature has spiked more than 5 degrees Celsius in the last measurement.\n");
        } else if (temperature < previousTemperature - 5) {
            printf("Warning! The temperature has dropped more than 5 degrees Celsius in the last measurement.\n");
        }

        if (count % 10 == 0) {
            printf("Averaged temperature over the last 10 measurements: %f C\n", (temperature + previousTemperature * 9) / 10);
        }

        previousTemperature = temperature;
        count++;

        printf("\n");
        // Sleep for one second
        int i;
        for(i = 0; i < 1000000000; i++);
    }

    return 0;
}