//FormAI DATASET v1.0 Category: Weather simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initializing the random number generator

    int temperature = rand() % 40 - 10; // Generating a random temperature (-10 to 30)
    int humidity = rand() % 101; // Generating a random humidity (0 to 100)
    int precipitation = rand() % 101; // Generating a random precipitation (0 to 100)

    printf("Current weather condition:\n");

    if (temperature < 0) printf("It's freezing outside! ");
    else if (temperature < 10) printf("It's quite cold outside. ");
    else if (temperature < 20) printf("It's a bit chilly outside. ");
    else if (temperature < 30) printf("It's warm outside. ");
    else printf("It's hot outside! ");

    if (humidity < 30) printf("The air is dry. ");
    else if (humidity < 70) printf("The air is moist. ");
    else printf("It's quite humid outside. ");

    if (precipitation < 30) printf("No rain in sight. ");
    else if (precipitation < 70) printf("It might rain soon. ");
    else printf("It's heavily raining outside. ");
    
    printf("\n");

    return 0;
}