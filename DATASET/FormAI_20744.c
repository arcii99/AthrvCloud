//FormAI DATASET v1.0 Category: Temperature monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temp = 0;
    srand(time(NULL));

    printf("--- Welcome to the Post-Apocalyptic Temperature Monitor ---\n");

    while(1) { // Continuous monitoring
       temp = (rand() % 101) - 50; // Random temperature between -50 C and 50 C
       printf("The current temperature is %d C.\n", temp);
       
       if(temp < -10) { // Dangerously low temperature
            printf("ALERT: The temperature is dangerously low. Seek shelter immediately!\n");
       } else if(temp > 40) { // Dangerously high temperature
            printf("ALERT: The temperature is dangerously high. Seek shelter immediately!\n");
       } else if(temp > 30) { // High temperature
            printf("WARNING: The temperature is high. Drink plenty of fluids and stay in the shade.\n");
       } else if(temp < 0) { // Freezing temperature
            printf("WARNING: The temperature is freezing. Wear warm clothes and cover exposed skin.\n");
       }
       
       sleep(5); // Wait for 5 seconds before checking the temperature again
    }

    return 0;
}