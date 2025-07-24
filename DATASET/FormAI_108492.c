//FormAI DATASET v1.0 Category: Weather simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printWeather(int temperature) {
    if (temperature >= 30) {
        printf("It's scorching hot today with a temperature of %d degrees Celsius!\n", temperature);
    } else if (temperature >= 20 && temperature < 30) {
        printf("The weather is warm and pleasant today with a temperature of %d degrees Celsius.\n", temperature);
    } else if (temperature >= 10 && temperature < 20) {
        printf("It's a bit chilly outside with a temperature of %d degrees Celsius.\n", temperature);
    } else {
        printf("It's freezing cold today with a temperature of %d degrees Celsius!\n", temperature);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator with current time

    int temperature = rand() % 50 - 10; // Random temperature between -10 and 40 degrees Celsius

    printWeather(temperature);

    return 0;
}