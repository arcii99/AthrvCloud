//FormAI DATASET v1.0 Category: Weather simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 50 // Maximum temperature in Celsius
#define MIN_TEMP -50 // Minimum temperature in Celsius

int main() {
    srand(time(NULL)); // Seed the random number generator with current time
    int temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP; // Generate a random temperature between MIN_TEMP and MAX_TEMP
    char weather[20]; // String variable to store the weather condition
    if (temperature >= 30) {
        strcpy(weather, "Hot and sunny"); // Set weather condition to hot and sunny when temperature is above or equal to 30 degrees Celsius
    } else if (temperature >= 20) {
        strcpy(weather, "Warm and cloudy"); // Set weather condition to warm and cloudy when temperature is between 20 and 29 degrees Celsius
    } else if (temperature >= 10) {
        strcpy(weather, "Cool and rainy"); // Set weather condition to cool and rainy when temperature is between 10 and 19 degrees Celsius
    } else {
        strcpy(weather, "Cold and snowy"); // Set weather condition to cold and snowy when temperature is below or equal to 9 degrees Celsius
    }
    printf("The temperature is %d degrees Celsius.\n", temperature); // Print the temperature
    printf("The weather condition is %s.\n", weather); // Print the weather condition
    return 0; // Exit the program
}