//FormAI DATASET v1.0 Category: Weather simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#define MAX_WEEK 7

typedef struct Week {
    float temperature[MAX_WEEK];    // Temperature of each day of the week
    char conditions[MAX_WEEK][10];  // Weather conditions of each day of the week
} Week;

// Function to simulate weather conditions based on temperature
char *get_conditions(float temp) {
    if (temp >= 30.0) {
        return "Sunny";
    } else if (temp >= 20.0 && temp < 30.0) {
        return "Partly Cloudy";
    } else if (temp >= 10.0 && temp < 20.0) {
        return "Cloudy";
    } else {
        return "Rainy";
    }
}

// Function to generate random temperature
float get_temperature() {
    float temp = (rand() % 25) + 10;  // Generate a temperature between 10 to 35 degree Celsius
    return temp;
}

int main() {
    Week week; 
    // Generate random temperature and weather conditions for each day of the week
    for (int i = 0; i < MAX_WEEK; i++) {
        week.temperature[i] = get_temperature();
        strcpy(week.conditions[i], get_conditions(week.temperature[i]));
    }

    // Display the weather forecast for the week
    printf("Weather Forecast for the week:\n");
    printf("-------------------------------\n");
    for (int i = 0; i < MAX_WEEK; i++) {
        printf("Day %d: Temperature = %.2f degree Celsius, Conditions = %s\n", i+1, week.temperature[i], week.conditions[i]);
    }

    return 0;
}