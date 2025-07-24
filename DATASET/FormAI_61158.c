//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN_TEMP -50.0
#define MAX_TEMP 150.0

int main(void) {

    bool is_valid_temp = false;
    double temp;

    printf("Welcome to the Temperature Monitor Program!\n\n");

    do {
        printf("Please enter a temperature between -50 and 150 degrees Celsius: ");
        if (scanf("%lf", &temp) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n');
        } else if (temp < MIN_TEMP || temp > MAX_TEMP) {
            printf("Invalid temperature! Must be between -50 and 150 degrees Celsius!\n");
        } else {
            is_valid_temp = true;
        }
    } while (!is_valid_temp);

    printf("Temperature is: %.2lf degrees Celsius\n", temp);

    return EXIT_SUCCESS;
}