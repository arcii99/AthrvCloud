//FormAI DATASET v1.0 Category: Weather simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURE 50
#define MIN_TEMPERATURE -50
#define MAX_HUMIDITY 100
#define MIN_HUMIDITY 0

int main() {
    int temperature, humidity;
    srand(time(NULL)); // seed the random number generator with current time

    for(int i = 0; i < 5; i++) { // simulate weather for 5 days
        temperature = rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1) + MIN_TEMPERATURE; // generate random temperature
        humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY; // generate random humidity

        printf("Day %d\n", i + 1);
        printf("Temperature: %dC\n", temperature);
        printf("Humidity: %d%%\n", humidity);

        if(temperature > 30) { // if temperature is above 30C, it's hot
            printf("It's hot outside.\n");
        } else if(temperature < 10) { // if temperature is below 10C, it's cold
            printf("It's cold outside.\n");
        } else { // otherwise, it's moderate
            printf("It's moderate outside.\n");
        }

        if(humidity > 80) { // if humidity is above 80%, it's humid
            printf("It's humid outside.\n");
        } else if(humidity < 40) { // if humidity is below 40%, it's dry
            printf("It's dry outside.\n");
        } else { // otherwise, it's normal
            printf("It's normal outside.\n");
        }

        printf("\n");
    }

    return 0;
}