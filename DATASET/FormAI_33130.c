//FormAI DATASET v1.0 Category: Temperature monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float temp;
    time_t t;

    srand((unsigned) time(&t)); 

    printf("*****************************************************\n");
    printf("Welcome to the Temperature Monitoring System\n");
    printf("*****************************************************\n");

    while(1) {
        printf("\n\nReading temperature...\n");
        temp = (float)rand()/(float)(RAND_MAX/100); // random temperature between 0 and 100

        printf("Current temperature: %.2f°C\n",temp);

        if(temp >= 90) {
            printf("WARNING! Temperature is too high.\n");
        }
        if(temp >= 70 && temp < 90) {
            printf("Temperature is high.\n");
        } 
        if(temp >= 35 && temp < 70) {
            printf("Temperature is normal.\n");
        }
        if(temp < 35) {
            printf("WARNING! Temperature is too low.\n");
        }

        sleep(5); // wait for 5 seconds before reading temperature again
    }

    return 0;
}