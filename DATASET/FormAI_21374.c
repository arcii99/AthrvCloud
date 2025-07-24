//FormAI DATASET v1.0 Category: Weather simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for temperature range
#define MIN_TEMP 10
#define MAX_TEMP 40

// Constants for precipitation range
#define MIN_PREC 0
#define MAX_PREC 20

// Function to generate random float between given range
float randFloat(float min, float max) {
    float range = (max - min);
    float div = RAND_MAX / range;
    return min + (rand() / div);
}

// Function to generate random integer between given range
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to get string representation of weather condition
char* getWeatherCondition(float temp, float prec) {
    char* condition;
    if (temp > 30 && prec < 10) {
        condition = "hot and dry";
    } else if (temp > 30 && prec >= 10) {
        condition = "hot and rainy";
    } else if (temp <= 30 && temp >= 20 && prec >= 10) {
        condition = "warm and rainy";
    } else if (temp <= 30 && temp >= 20 && prec < 10) {
        condition = "warm and dry";
    } else if (temp < 20 && temp >= 10 && prec >= 10) {
        condition = "cool and rainy";
    } else {
        condition = "cool and dry";
    }
    return condition;
}

// Main function to simulate weather conditions for a week
int main() {
    int days = 7; // Number of days to simulate for
    float temp, prec; // Temperature and precipitation
    srand(time(NULL)); // Seed random number generator
    
    // Generate weather data for each day of the week
    for (int i=1; i<=days; i++) {
        printf("Weather for Day %d\n", i);
        printf("-----------------\n");
        temp = randFloat(MIN_TEMP, MAX_TEMP);
        prec = randFloat(MIN_PREC, MAX_PREC);
        printf("Temperature: %.1f\n", temp);
        printf("Precipitation: %.1f\n", prec);
        printf("Condition: %s\n\n", getWeatherCondition(temp, prec));
    }

    return 0;
}