//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct Exercise {
    char name[50];
    double caloriesBurned;
} Exercise;

typedef struct Log {
    int day;
    int month;
    int year;
    int numExercises;
    Exercise exercises[MAX_SIZE];
} Log;

typedef struct FitnessTracker {
    char user[50];
    int numLogs;
    Log logs[MAX_SIZE];
} FitnessTracker;

int main() {

    FitnessTracker tracker;
    int choice;
    bool exit = false;

    printf("Welcome to Fitness Tracker!\n");
    printf("Please enter your name: ");
    scanf("%s", tracker.user);

    while(!exit) {
        printf("\nPlease select from the following options:\n");
        printf("1. Log new exercise\n");
        printf("2. View log history\n");
        printf("3. Exit program\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("\nEnter date of exercise (DD MM YYYY): ");
                int day, month, year;
                scanf("%d %d %d", &day, &month, &year);

                printf("Enter number of exercises: ");
                int numExercises;
                scanf("%d", &numExercises);

                Log newLog;
                newLog.day = day;
                newLog.month = month;
                newLog.year = year;
                newLog.numExercises = numExercises;

                for(int i = 0; i < numExercises; i++) {
                    printf("\nEnter name of exercise %d: ", i+1);
                    scanf("%s", newLog.exercises[i].name);

                    printf("Enter calories burned for exercise %d: ", i+1);
                    scanf("%lf", &newLog.exercises[i].caloriesBurned);
                }

                tracker.logs[tracker.numLogs++] = newLog;
                printf("\nLog added successfully!\n");
                break;

            case 2:
                printf("\nLog history for %s:\n", tracker.user);
                for(int i = 0; i < tracker.numLogs; i++) {
                    printf("\nLog %d:\nDate: %d/%d/%d\n", i+1, tracker.logs[i].day, tracker.logs[i].month, tracker.logs[i].year);
                    printf("Exercises:\n");

                    for(int j = 0; j < tracker.logs[i].numExercises; j++) {
                        printf("%s - Calories burned: %.2lf\n", tracker.logs[i].exercises[j].name, tracker.logs[i].exercises[j].caloriesBurned);

                    }

                }
                break;

            case 3:
                printf("\nThank you for using Fitness Tracker!\n");
                exit = true;
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");

        }

    }

    return 0;
}