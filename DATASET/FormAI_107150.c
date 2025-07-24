//FormAI DATASET v1.0 Category: Weather simulation ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    srand(time(NULL));  // Seed the random number generator with current time
    int rain_chance = rand() % 100 + 1;  // Random number between 1 to 100
    int temp = rand() % 40 + 1;  // Random temperature between 1 to 40 Celsius
    char* sky = (char*) malloc(sizeof(char) * 20);  // Allocate memory for sky variable

    // Check rain_chance value and set sky variable accordingly
    if (rain_chance > 75) {
        sprintf(sky, "Rainy");
    } else if (rain_chance > 50) {
        sprintf(sky, "Cloudy");
    } else {
        sprintf(sky, "Sunny");
    }

    // Display weather simulation
    printf("Today's weather simulation: \n");
    printf("Temperature: %d Celsius\n", temp);
    printf("Sky: %s\n", sky);

    free(sky);  // Free the dynamically allocated memory for sky variable

    return 0;
}