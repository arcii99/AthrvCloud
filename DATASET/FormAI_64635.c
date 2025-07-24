//FormAI DATASET v1.0 Category: Temperature monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tempC, i;
    srand(time(NULL)); //Seed random number generator with current time

    printf("Temperature Monitor\n");

    for (i = 0; i < 10; i++) {
        tempC = rand() % 31; //Generate a random number between 0 and 30
        printf("Current Temp: %dC\n", tempC);

        if (tempC < 10) {
            printf("The temperature is too cold.\n");
        } else if (tempC >= 10 && tempC < 20) {
            printf("The temperature is comfortable.\n");
        } else if (tempC >= 20 && tempC < 30) {
            printf("The temperature is warm.\n");
        } else {
            printf("The temperature is too hot.\n");
        }

        printf("\n");
    }

    return 0;
}