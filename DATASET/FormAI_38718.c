//FormAI DATASET v1.0 Category: Weather simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // Initialize random seed
    int temperature = 20 + rand() % 15; // Generate random temperature between 20 to 35 degree Celsius
    int humidity = rand() % 100; // Generate random humidity between 0 to 100 percent

    printf("Today's temperature is %d degree celsius and humidity is %d percent.\n", temperature, humidity);

    if(temperature >= 30 && humidity >= 60) { // If temperature is greater than or equal to 30 degree Celsius and humidity is greater than or equal to 60 percent
        printf("It's a hot and humid day, please stay hydrated and avoid staying outdoor for long.\n");
    }

    else if(temperature >= 30 && humidity < 60) { // If temperature is greater than or equal to 30 degree Celsius and humidity is less than 60 percent
        printf("It's a hot day, please stay hydrated and avoid staying outdoor for long.\n");
    }

    else if(temperature < 30 && humidity >= 60) { // If temperature is less than 30 degree Celsius and humidity is greater than or equal to 60 percent
        printf("It's a humid day, please stay hydrated and avoid staying outdoor for long.\n");
    }

    else { // If temperature is less than 30 degree Celsius and humidity is less than 60 percent
        printf("It's a pleasant day, you can enjoy outdoor activities without any worries.\n");
    }

    return 0;
}