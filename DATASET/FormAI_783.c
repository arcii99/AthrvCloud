//FormAI DATASET v1.0 Category: Weather simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct weather {
    char* condition;
    int temperature;
};

void printWeather(struct weather today) {
    printf("The current weather condition is %s and the temperature is %d degrees Celsius\n", today.condition, today.temperature);
}

int main() {
    srand(time(NULL));
    struct weather today;
    char* conditions[] = {"sunny", "cloudy", "partly cloudy", "rainy", "stormy", "foggy"};
    int minTemp = -10;
    int maxTemp = 40;
    int randomIndex = rand() % 6;
    today.condition = conditions[randomIndex];
    today.temperature = rand() % (maxTemp - minTemp + 1) + minTemp;
    printWeather(today);
    return 0;
}