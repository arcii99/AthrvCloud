//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the structure to hold the user's fitness data
struct FitnessData {
    char date[15];
    int steps;
    int caloriesBurned;
    double distance;
    int pushups;
    int squats;
    double weight;
};

// Function to add new fitness data to the user's log
struct FitnessData addFitnessData() {
    struct FitnessData fitnessData;

    printf("\nEnter the date (dd/mm/yyyy): ");
    fgets(fitnessData.date, 15, stdin);
    printf("Enter the number of steps: ");
    scanf("%d", &fitnessData.steps);
    printf("Enter the calories burned: ");
    scanf("%d", &fitnessData.caloriesBurned);
    printf("Enter the distance (in km): ");
    scanf("%lf", &fitnessData.distance);
    printf("Enter the number of pushups: ");
    scanf("%d", &fitnessData.pushups);
    printf("Enter the number of squats: ");
    scanf("%d", &fitnessData.squats);
    printf("Enter your weight (in kg): ");
    scanf("%lf", &fitnessData.weight);

    return fitnessData;
}

// Function to display the user's fitness log for a specific date
void displayFitnessLog(struct FitnessData *fitnessLogs, int numOfLogs) {
    char date[15];
    int logFound = 0;  // to check if logs were found for the specified date

    printf("\nEnter the date to view the fitness log (dd/mm/yyyy): ");
    fgets(date, 15, stdin);

    for (int i = 0; i < numOfLogs; i++) {
        if (strcmp(date, fitnessLogs[i].date) == 0) {
            printf("\nDate: %s", fitnessLogs[i].date);
            printf("\nNumber of steps: %d", fitnessLogs[i].steps);
            printf("\nCalories burned: %d", fitnessLogs[i].caloriesBurned);
            printf("\nDistance: %.2f km", fitnessLogs[i].distance);
            printf("\nPushups: %d", fitnessLogs[i].pushups);
            printf("\nSquats: %d", fitnessLogs[i].squats);
            printf("\nWeight: %.1f kg\n", fitnessLogs[i].weight);
            logFound = 1;
            break;
        }
    }

    if (!logFound) {
        printf("\nNo logs found for the specified date.\n");
    }
}

int main() {
    int choice, numOfLogs = 0;
    struct FitnessData *fitnessLogs = NULL;

    do {
        printf("\n----- Fitness Tracker -----\n1. Add Fitness Data\n2. Display Fitness Log\n3. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                struct FitnessData newFitnessData = addFitnessData();
                if (numOfLogs == 0) {
                    fitnessLogs = (struct FitnessData *) malloc(sizeof(struct FitnessData));
                } else {
                    fitnessLogs = (struct FitnessData *) realloc(fitnessLogs, (numOfLogs + 1) * sizeof(struct FitnessData));
                }
                fitnessLogs[numOfLogs] = newFitnessData;
                numOfLogs++;
                printf("\nYour fitness data has been saved.\n");
                break;

            case 2:
                if (numOfLogs == 0) {
                    printf("\nNo logs found.\n");
                } else {
                    displayFitnessLog(fitnessLogs, numOfLogs);
                }
                break;

            case 3:
                printf("\nThank you for using the Fitness Tracker.\n");
                break;

            default:
                printf("\nInvalid choice.\n");
                break;
        }

        // Clearing input buffer
        while (getchar() != '\n');

    } while (choice != 3);

    // Freeing the allocated memory
    free(fitnessLogs);

    return 0;
}