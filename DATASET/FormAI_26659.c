//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME 5000

struct TimeMachine {
    int powerLevel;
    int currentYear;
} timeMachine;

int getRandomYear(int minYear, int maxYear) {
    return minYear + rand() % (maxYear - minYear + 1);
}

void timeTravel(int years) {
    timeMachine.currentYear += years;
    printf("Traveled %d years into the future. Current year: %d\n", years, timeMachine.currentYear);
}

void recharge() {
    printf("Recharging energy...\n");
    int rechargeAmount = rand() % 501;
    timeMachine.powerLevel += rechargeAmount;
    printf("Energy recharged by %d units.\n", rechargeAmount);
}

void activateTimeMachine(int startingYear) {
    timeMachine.powerLevel = 1000;
    timeMachine.currentYear = startingYear;
    printf("Time machine activated. Starting year: %d\n", timeMachine.currentYear);

    while (timeMachine.powerLevel > 0) {
        int yearsToTravel = rand() % 101;
        timeTravel(yearsToTravel);

        if (timeMachine.currentYear > 3000) {
            printf("Time travel successful. End year: %d\n", timeMachine.currentYear);
            printf("Thank you for using the time machine!\n");
            return;
        }

        int randNum = rand() % 100;
        if (randNum < 10) { // 10% chance of time paradox
            printf("WARNING: Time paradox detected. Attempting to fix...\n");
            int yearsToGoBack = rand() % 100;
            timeTravel(-yearsToGoBack);
        }

        timeMachine.powerLevel -= 100;
        if (timeMachine.powerLevel <= 0) {
            printf("Power level depleted. Time machine shutting down...\n");
            return;
        }

        if (timeMachine.powerLevel < 500) {
            recharge();
        }
    }
}

int main() {
    srand(time(NULL));

    int startingYear = getRandomYear(-1000, 2021);
    printf("Welcome to the Time Travel Simulator.\n");
    printf("Your adventure begins in the year %d.\n", startingYear);

    activateTimeMachine(startingYear);
    
    return 0;
}