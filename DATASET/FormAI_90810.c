//FormAI DATASET v1.0 Category: Weather simulation ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Function to generate random temperatures */
int getTemperature() {
    int min = -20;
    int max = 40;
    return rand() % (max - min + 1) + min;
}

/* Function to check if it's raining */
int isRaining() {
    int isRainy = rand() % 2;
    return isRainy;
}

/* Function to check if it's snowing */
int isSnowing() {
    int isSnowy = rand() % 2;
    return isSnowy;
}

/* Function to check the wind speed */
int getWindSpeed() {
    int min = 0;
    int max = 50;
    return rand() % (max - min + 1) + min;
}

/* Function to simulate the weather */
void simulateWeather() {

    /* Initialize variables */
    int temperature = 0;
    int isRainy = 0;
    int isSnowy = 0;
    int windSpeed = 0;

    /* Generate random values */
    temperature = getTemperature();
    isRainy = isRaining();
    isSnowy = isSnowing();
    windSpeed = getWindSpeed();

    /* Print the simulation results */
    printf("The temperature today is %d°C\n", temperature);
    if(isRainy) {
        printf("It's raining today\n");
    }
    if(isSnowy) {
        printf("It's snowing today\n");
    }
    printf("The wind speed today is %d km/h\n", windSpeed);
}

/* Main function */
int main() {

    /* Seed the random number generator */
    srand(time(NULL));

    /* Simulate the weather */
    simulateWeather();
    
    return 0;
}