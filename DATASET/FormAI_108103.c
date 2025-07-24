//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: genious
#include <stdio.h>

int main() {
    int heartRate = 0;
    int steps = 0;

    printf("Welcome to the C Fitness Tracker!\n");

    while(1) {
        printf("\nPlease enter your current heart rate (in beats per minute): ");
        scanf("%d", &heartRate);

        printf("Please enter the number of steps you've taken today: ");
        scanf("%d", &steps);

        printf("\n---------------------------------------------\n");
        printf("|        C FITNESS TRACKER - SUMMARY         |\n");
        printf("---------------------------------------------\n");
        printf("|  Heart Rate: %d bpm                        |\n", heartRate);
        printf("|  Steps Taken: %d                           |\n", steps);
        printf("|                                             |\n");

        if(heartRate >= 60 && heartRate <= 100) {
            printf("|  Heart Rate Status: NORMAL                 |\n");
        } else if (heartRate < 60) {
            printf("|  Heart Rate Status: LOW                    |\n");
        } else {
            printf("|  Heart Rate Status: HIGH                   |\n");
        }

        if(steps > 10000) {
            printf("|  Steps Status: EXCELLENT                    |\n");
        } else if (steps > 5000) {
            printf("|  Steps Status: GOOD                         |\n");
        } else {
            printf("|  Steps Status: POOR                         |\n");
        }

        printf("---------------------------------------------\n");

    }
    return 0;
}