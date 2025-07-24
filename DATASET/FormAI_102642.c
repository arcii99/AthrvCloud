//FormAI DATASET v1.0 Category: Temperature monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum and minimum temperatures
#define MAX_TEMP 50
#define MIN_TEMP -20

// Function declarations
float generateTemperature();
void printTemperature(float temp);

int main() {
    printf("Welcome to the Temperature Monitor\n\n");

    while (1) {
        float temp = generateTemperature();
        printTemperature(temp);

        // wait for 10 seconds before generating the next temperature
        sleep(10);
    }

    return 0;
}

// Function to generate a random temperature between MIN_TEMP and MAX_TEMP
float generateTemperature() {
    srand(time(NULL));
    float temp = (float)rand()/(float)(RAND_MAX/ (MAX_TEMP-MIN_TEMP)) + MIN_TEMP;
    return temp;
}

// Function to print the temperature and the corresponding message
void printTemperature(float temp) {
    printf("The current temperature is %.2f degrees Celsius\n", temp);

    if (temp < 0) {
        printf("It's freezing outside!\n");
    } else if (temp >= 0 && temp < 10) {
        printf("It's very cold outside\n");
    } else if (temp >= 10 && temp < 20) {
        printf("It's chilly outside\n");
    } else if (temp >= 20 && temp < 30) {
        printf("It's quite warm outside\n");
    } else if (temp >= 30 && temp < 40) {
        printf("It's hot outside\n");
    } else if (temp >= 40) {
        printf("It's very hot outside!\n");
    }
}