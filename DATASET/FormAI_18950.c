//FormAI DATASET v1.0 Category: Temperature monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temperatures[24]; // array to store 24 hourly temperatures
    srand(time(NULL)); // seed the random number generator with the current time

    printf("Welcome to the peaceful temperature monitor!\n");
    printf("We will monitor the temperature each hour for the next 24 hours.\n");

    // generate random temperatures for the next 24 hours between 0 and 100 degrees Celsius
    for (int i = 0; i < 24; i++) {
        temperatures[i] = rand() % 101;
        printf("Hour %d temperature: %d degrees Celsius.\n", i + 1, temperatures[i]);
    }

    // find the maximum temperature and the hour it occurred
    int max_temp = temperatures[0];
    int max_temp_hour = 1;
    for (int i = 1; i < 24; i++) {
        if (temperatures[i] > max_temp) {
            max_temp = temperatures[i];
            max_temp_hour = i + 1;
        }
    }

    // find the minimum temperature and the hour it occurred
    int min_temp = temperatures[0];
    int min_temp_hour = 1;
    for (int i = 1; i < 24; i++) {
        if (temperatures[i] < min_temp) {
            min_temp = temperatures[i];
            min_temp_hour = i + 1;
        }
    }

    printf("The highest temperature was %d degrees Celsius and occurred during hour %d.\n", max_temp, max_temp_hour);
    printf("The lowest temperature was %d degrees Celsius and occurred during hour %d.\n", min_temp, min_temp_hour);

    return 0;
}