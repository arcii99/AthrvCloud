//FormAI DATASET v1.0 Category: Weather simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void weatherSimulator(int hour) {
    char* weather;
    int temperature;
    srand(time(NULL)); // set random seed

    if (hour < 6 || hour > 20) { // night time
        weather = "Clear";
        temperature = rand() % 11 - 10; // temperature range: -10 to 0 Celsius
    }
    else { // day time
        int random = rand() % 100 + 1;
        if (random <= 30) { // 30% chance of rain
            weather = "Rainy";
            temperature = rand() % 11 + 10; // temperature range: 10 to 20 Celsius
        }
        else if (random <= 60) { // 30% chance of cloudy
            weather = "Cloudy";
            temperature = rand() % 11 + 20; // temperature range: 20 to 30 Celsius
        }
        else { // 40% chance of clear
            weather = "Clear";
            temperature = rand() % 11 + 30; // temperature range: 30 to 40 Celsius
        }
    }

    printf("At %d:00, the weather is %s with a temperature of %d Celsius.\n", hour, weather, temperature);
}

int main() {
    for (int hour = 0; hour <= 23; hour++) {
        weatherSimulator(hour);
    }

    return 0;
}