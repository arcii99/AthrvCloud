//FormAI DATASET v1.0 Category: Weather simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator
    int currentTemp = rand() % 101 - 25;
    int desiredTemp;
    int coolingSystemOn = 0;
    int timeToCool = 0;
    int currentTime = 0;

    printf("Welcome to the Weather Simulation Program\n\n");
    printf("Please enter a desired temperature between -25 and 75 degrees Fahrenheit: ");
    scanf("%d", &desiredTemp);

    while (currentTemp != desiredTemp) {
        printf("\nCurrent Time: %d\n", currentTime);
        printf("Current Temperature: %d\n", currentTemp);
        if (currentTemp < desiredTemp) {
            if (coolingSystemOn) {
                printf("Cooling system is still running, time left: %d\n", timeToCool - currentTime);
                if (currentTime >= timeToCool) {
                    coolingSystemOn = 0;
                    printf("Cooling system turned off\n");
                }
            } else {
                coolingSystemOn = 1;
                timeToCool = currentTime + rand() % 6 + 5; // cooling system takes 5-10 minutes to cool down
                printf("Cooling system started, time left: %d\n", timeToCool - currentTime);
            }
            currentTemp++;
        } else {
            coolingSystemOn = 0;
            currentTemp--;
        }
        currentTime++;
    }

    printf("\nDesired temperature reached!\n");
    printf("Final Temperature: %d\n", currentTemp);
    printf("Total Time: %d minutes\n", currentTime);

    return 0;
}