//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: automated
#include <stdio.h>
#include <stdbool.h>

// Function to display available time periods
void displayAvailableTimePeriods(int availableYears[], int numOfPeriods) {
    printf("\nAvailable Time Periods:\n");
    for (int i = 0; i < numOfPeriods; i++) {
        printf("%d-%d\n", availableYears[i], availableYears[i] + 10);
    }
}

// Function to check if the chosen time period is available
bool isTimePeriodAvailable(int chosenYear, int availableYears[], int numOfPeriods) {
    for (int i = 0; i < numOfPeriods; i++) {
        if (chosenYear >= availableYears[i] && chosenYear <= availableYears[i] + 10) {
            return true;
        }
    }
    return false;
}

int main() {
    int availableYears[] = { 2000, 2010, 2020, 2030 };
    int numOfPeriods = 4;
    int chosenYear;

    // Display available time periods
    displayAvailableTimePeriods(availableYears, numOfPeriods);

    // Ask user to choose a time period
    printf("\nEnter a year to travel to: ");
    scanf("%d", &chosenYear);

    // Check if chosen time period is available
    if (!isTimePeriodAvailable(chosenYear, availableYears, numOfPeriods)) {
        printf("\nSorry, time travel to that year is not available.\n");
        return 0;
    }

    // Calculate time difference
    int timeDiff = chosenYear - 2021;

    // Travel to the chosen time period
    printf("\nTravelling to the year %d...\n", chosenYear);
    printf("You have travelled %d years into the future.\n", (timeDiff > 0) ? timeDiff : -(timeDiff));

    return 0;
}