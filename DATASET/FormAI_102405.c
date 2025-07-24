//FormAI DATASET v1.0 Category: Weather simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // initialize random number generator with seed value of current time
    
    float temperature = 0;
    float humidity = 0;
    char sky_condition[15];
    
    // generate temperature between -10 to 40 Celsius
    temperature = (rand() % 51) - 10;
    
    // generate humidity between 0 to 100%
    humidity = rand() % 101;
    
    // generate sky condition
    int random_number = rand() % 3;
    switch (random_number) {
        case 0:
            sprintf(sky_condition, "Sunny");
            break;
        case 1:
            sprintf(sky_condition, "Rainy");
            break;
        case 2:
            sprintf(sky_condition, "Cloudy");
            break;
        default:
            sprintf(sky_condition, "Unknown");
    }
    
    printf("Temperature: %.1f Celsius\n", temperature);
    printf("Humidity: %.1f%%\n", humidity);
    printf("Sky Condition: %s\n", sky_condition);
    
    return 0;
}