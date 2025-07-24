//FormAI DATASET v1.0 Category: Temperature monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float temp = 0.0;
    int i;

    printf("Temperature Monitor Program\n");
    printf("--------------------------\n\n");

    srand(time(NULL));

    for(i = 1; i <= 50; i++) {
        temp = (rand() % 50) + 10; //Generate a random temperature between 10 and 60 degrees Celsius

        if(temp > 30.0) {
            printf("Warning! Temperature is %.2fC, above the ideal range.\n", temp);
        } else {
            printf("Current temperature is %.2fC.\n", temp);
        }

        printf("--------------------------\n");
    }

    printf("\nProgram ended.\n");
    return 0;
}