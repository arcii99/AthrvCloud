//FormAI DATASET v1.0 Category: Temperature monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int currentTemp = 0;
    int maxTemp = 30;
    int minTemp = -10;
    int countOver = 0;
    int countUnder = 0;
    int countMatch = 0;

    srand(time(0)); 

    printf("Starting temperature monitor...\n\n");

    for (int i = 0; i < 100; i++) {
        
        int randomTemp = rand() % (maxTemp - minTemp + 1) + minTemp;
        currentTemp += randomTemp;

        if (currentTemp > maxTemp) {
            printf("WARNING: Temperature has exceeded maximum limit!\n");
            countOver++;
        } else if (currentTemp < minTemp) {
            printf("WARNING: Temperature has dropped below minimum limit!\n");
            countUnder++;
        } else {
            printf("Temperature is within safe range.\n");
            countMatch++;
        }

        printf("Current temperature is: %d\n\n", currentTemp);

        // simulate a pause of 1 second
        for (int j = 0; j < 100000000; j++);

    }

    printf("Temperature monitor stopped.\n");
    printf("Total number of times temperature exceeded maximum: %d\n", countOver);
    printf("Total number of times temperature dropped below minimum: %d\n", countUnder);
    printf("Total number of times temperature was within safe range: %d\n", countMatch);

    return 0;
}