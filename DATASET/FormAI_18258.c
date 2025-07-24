//FormAI DATASET v1.0 Category: Weather simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int temperature = 10 + rand() % 25;

    printf("The current temperature is %d degrees Celsius.\n\n", temperature);

    if (temperature < 15) {
        printf("It's quite chilly outside, make sure to wear a jacket!\n");
    } else if (temperature < 20) {
        printf("It's a bit cool outside, you may want to grab a light sweater.\n");
    } else if (temperature < 25) {
        printf("It's a comfortable temperature outside, enjoy the pleasant weather!\n");
    } else if (temperature < 30) {
        printf("It's warm outside, you may want to dress for the heat.\n");
    } else {
        printf("It's quite hot outside, stay hydrated and avoid prolonged exposure to the sun.\n");
    }

    printf("\nHere's the five-day forecast for your area:\n");

    for (int i = 1; i <= 5; i++) {
        int dailyTemp = 10 + rand() % 25;

        printf("Day %d: %d degrees Celsius\n", i, dailyTemp);
    }

    return 0;
}