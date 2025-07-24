//FormAI DATASET v1.0 Category: Weather simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed random number generator
    int weather = rand() % 4; // Generate random number between 0 and 3

    switch(weather) {
        case 0:
            printf("It is sunny today.\n");
            break;
        case 1:
            printf("It is raining today.\n");
            break;
        case 2:
            printf("It is cloudy today.\n");
            break;
        case 3:
            printf("It is snowing today.\n");
            break;
        default:
            printf("Something went wrong.\n");
            break;
    }

    return 0;
}