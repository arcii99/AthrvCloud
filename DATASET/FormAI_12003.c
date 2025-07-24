//FormAI DATASET v1.0 Category: Temperature monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Temperature Monitor Program\n");
    printf("==========================================\n\n");

    int temp[5]; //to store temperatures of 5 locations
    int sum = 0, avg = 0, max_temp = 0, min_temp = 100; //initialize max and min values

    // generate random temperatures for 5 locations
    srand(time(NULL));
    printf("Generating random temperatures...\n");

    for (int i = 0; i < 5; i++) {
        temp[i] = rand() % 50 + 10; //random temperature between 10°C and 60°C
        printf("Location %d temperature: %d°C\n", i + 1, temp[i]);
        sum += temp[i];
        if (temp[i] > max_temp) {
            max_temp = temp[i];
        }
        if (temp[i] < min_temp) {
            min_temp = temp[i];
        }
    }

    avg = sum / 5;

    printf("\n");
    printf("Average temperature: %d°C\n", avg);
    printf("Maximum temperature: %d°C\n", max_temp);
    printf("Minimum temperature: %d°C\n", min_temp);

    // check if temperature is within range
    printf("\n");
    printf("Checking if temperature is within range...\n");

    for (int i = 0; i < 5; i++) {
        if (temp[i] < 20) {
            printf("Location %d has low temperature\n", i + 1);
        }
        if (temp[i] > 40) {
            printf("Location %d has high temperature\n", i + 1);
        }
    }

    printf("\n");
    printf("End of program\n");

    return 0;
}