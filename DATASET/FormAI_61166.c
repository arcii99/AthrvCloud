//FormAI DATASET v1.0 Category: Weather simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wait(int seconds) {
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < endwait) {}
}

int main() {
    int temperature = 25;
    int humidity = 80;
    srand(time(NULL));
    int lightning = 0;

    printf("The weather today is partly cloudy.\n");
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Humidity: %d%%\n\n", humidity);

    while (1) {
        wait(1);
        temperature += rand() % 3 - 1;
        humidity += rand() % 3 - 1;
        if (temperature < 10) {
            printf("It's getting very cold!\n");
        } else if (temperature > 35) {
            printf("It's getting very hot!\n");
        }
        if (humidity < 30) {
            printf("It's getting very dry!\n");
        } else if (humidity > 70) {
            printf("It's getting very humid!\n");
        }
        if (temperature > 25 && humidity > 60 && lightning == 0) {
            printf("\nThunderstorm approaching!!\n\n");
            lightning = 1;
        }
        if (temperature < 25 || humidity < 60) {
            lightning = 0;
        }
        if (lightning == 1) {
            printf("LIGHTNING\n");
        }
        printf("Temperature: %d degrees Celsius\n", temperature);
        printf("Humidity: %d%%\n\n", humidity);
    }
}