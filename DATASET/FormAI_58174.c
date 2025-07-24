//FormAI DATASET v1.0 Category: Weather simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize variables for temperature and condition
    int temp = rand() % 60 - 10; // Random temperature between -10 and 50 degrees Celsius
    int condition = rand() % 3; // Random condition: 0 for sunny, 1 for cloudy, 2 for rainy

    // Print the starting weather conditions
    printf("The current temperature is %d degrees Celsius.\n", temp);
    if (condition == 0) {
        printf("It is currently sunny.\n");
    } else if (condition == 1) {
        printf("It is currently cloudy.\n");
    } else {
        printf("It is currently raining.\n");
    }

    // Randomly change the weather conditions
    int change = rand() % 3 - 1; // Random change: -1 for decrease, 0 for no change, 1 for increase
    temp += change;
    condition = rand() % 3;

    // Print the updated weather conditions
    printf("The temperature has changed by %d degrees Celsius.\n", change);
    printf("The current temperature is now %d degrees Celsius.\n", temp);
    if (condition == 0) {
        printf("It is now sunny.\n");
    } else if (condition == 1) {
        printf("It is now cloudy.\n");
    } else {
        printf("It is now raining.\n");
    }

    return 0;
}