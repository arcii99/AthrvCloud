//FormAI DATASET v1.0 Category: Temperature monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float temp = 0;

    srand(time(0));

    for(int i = 0; i < 10; i++) {
        temp = ((float)rand()) / ((float)RAND_MAX) * 100;
        if(temp < 32) {
            printf("Warning! Temperature is too cold!");
        } else if(temp > 90) {
            printf("Warning! Temperature is too hot!");
        } else {
            printf("Temperature is within normal range.");
        }
        printf("\nCurrent temperature: %.2f degrees Celsius\n\n", temp);
        sleep(1);
    }

    return 0;
}