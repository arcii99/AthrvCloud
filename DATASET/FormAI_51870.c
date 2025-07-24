//FormAI DATASET v1.0 Category: Temperature monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(){
    srand(time(NULL));
    float temperature = 21.0;
    int count = 0;
    bool running = true;
    while(running){
        int deviation = rand() % 5; //generates random number between 0-4
        float newTemp = temperature + ((rand() % 2 == 0) ? deviation * 0.1 : deviation * -0.1); //adds or subtracts deviation based on random number
        printf("Current temperature: %.1f C\n", newTemp);
        if(newTemp > 30 || newTemp < 0){ //if temperature goes below 0 or above 30 stop the program
            printf("Temperature is out of range, stopping program.\n");
            running = false;
        }
        temperature = newTemp;
        count++;
        if(count == 10){ //prints a warning message every 10 iterations
            printf("WARNING: Temperature has been fluctuating frequently.\n");
            count = 0;
        }
        sleep(1); //pauses for 1 second to simulate real-time monitoring
    }
    return 0;
}