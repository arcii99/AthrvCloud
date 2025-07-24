//FormAI DATASET v1.0 Category: Weather simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed

    // weather conditions variables
    int temperature, cloudiness, rain, wind_speed;
    char *sky;
    const char *SKY[3] = {"clear", "partly cloudy", "overcast"}; // sky conditions array

    // generate random weather conditions
    temperature = rand() % (100 - 50 + 1) + 50;
    cloudiness = rand() % (3 - 0 + 1);
    rain = rand() % (2);
    wind_speed = rand() % (20 - 1 + 1) + 1;

    // set sky according to cloudiness
    if (cloudiness > 1) {
        sky = "stormy";
    } else {
        sky = SKY[cloudiness];
    }

    // print out the weather conditions
    printf("Today's weather:\n");
    printf("Temperature: %dF\n", temperature);
    printf("Sky: %s\n", sky);
    printf("Rain: %s\n", (rain ? "yes" : "no"));
    printf("Wind speed: %dmph\n", wind_speed);

    // simulate the weather conditions
    if (rain) {
        printf("It's starting to rain!\n");
        if (temperature < 32) {
            printf("The rain has turned into snow.\n");
        }
    }
    
    if (wind_speed > 10) {
        printf("It's really windy today. Watch your hats!\n");
    }

    if (temperature > 90) {
        printf("It's very hot outside. Stay hydrated!\n");
    } else if (temperature < 32) {
        printf("It's freezing outside. Dress in warm layers!\n");
    }

    // exit program successfully
    return 0;
}