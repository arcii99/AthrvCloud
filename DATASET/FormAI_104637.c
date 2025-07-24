//FormAI DATASET v1.0 Category: Temperature monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_TEMPERATURE 50

int main() {
    int temperature = 0;
    while(1) {
        temperature = (rand() % MAX_TEMPERATURE) + 1;
        printf("Current temperature is %d degrees Celsius\n", temperature);
        if(temperature > 40) {
            printf("Warning: Temperature is too high!\n");
        }
        sleep(5); // wait for 5 seconds before checking temperature again
    }
    return 0;
}