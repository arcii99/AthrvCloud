//FormAI DATASET v1.0 Category: Temperature monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int currentTemp = 25;
    int prevTemp = 0;
    
    printf("== C RETRO TEMPERATURE MONITOR ==\n\n");
    printf("Current Temperature: %d degrees Celsius\n\n", currentTemp);
    
    while (1) {
        prevTemp = currentTemp;
        currentTemp = rand() % 21 + 10; // generate random temperature between 10 and 30 degrees Celsius
        
        printf("Current Temperature: %d degrees Celsius\n", currentTemp);
        
        if (currentTemp > prevTemp) {
            printf("Temperature is rising!\n\n");
        } else if (currentTemp < prevTemp) {
            printf("Temperature is dropping!\n\n");
        } else {
            printf("Temperature is stable.\n\n");
        }
        
        fflush(stdout); // flush output buffer
        sleep(2); // wait for 2 seconds
        system("cls || clear"); // clear console screen in Windows or Linux
    }
    
    return 0;
}