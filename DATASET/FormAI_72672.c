//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXERCISES 10

typedef struct Exercise{
    char name[20];
    int sets;
    int reps;
} Exercise;

typedef struct FitnessTracker {
    int daysEntered;
    Exercise exercises[MAX_EXERCISES];
} FitnessTracker;

FitnessTracker initTracker();
int addExercise(FitnessTracker*, Exercise);
void displayTracker(FitnessTracker);

int main() {
    FitnessTracker tracker = initTracker();

    printf("Welcome to the Fitness Tracker!\n");
    printf("-----------------------------\n");

    int choice = 0;
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an exercise\n2. Display your tracker\n3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clears the newline character from the buffer

        switch(choice) {
            case 1: {
                Exercise newExercise;
                printf("\nEnter the name of the exercise: ");
                fgets(newExercise.name, sizeof(newExercise.name), stdin);
                newExercise.name[strcspn(newExercise.name, "\n")] = '\0'; // removes newline character from input
                printf("Enter the number of sets: ");
                scanf("%d", &newExercise.sets);
                printf("Enter the number of reps per set: ");
                scanf("%d", &newExercise.reps);

                int result = addExercise(&tracker, newExercise);
                if(result == -1) {
                    printf("Unable to add exercise. Tracker is full.\n");
                } else {
                    printf("Exercise added successfully.\n");
                }
                break;
            }
            case 2:
                displayTracker(tracker);
                break;
            case 3:
                printf("\nGoodbye!");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(choice != 3);

    return 0;
}

FitnessTracker initTracker() {
    FitnessTracker newTracker;
    newTracker.daysEntered = 0;

    for(int i = 0; i < MAX_EXERCISES; i++) {
        Exercise emptyExercise = {"", 0, 0};
        newTracker.exercises[i] = emptyExercise;
    }

    return newTracker;
}

int addExercise(FitnessTracker* tracker, Exercise newExercise) {
    if(tracker->daysEntered < MAX_EXERCISES) {
        tracker->exercises[tracker->daysEntered] = newExercise;
        tracker->daysEntered++;
        return 1;
    } else {
        return -1;
    }
}

void displayTracker(FitnessTracker tracker) {
    printf("\nFitness Tracker\n");
    printf("----------------\n");

    if(tracker.daysEntered == 0) {
        printf("No exercises entered yet.\n");
    } else {
        for(int i = 0; i < tracker.daysEntered; i++) {
            Exercise currentExercise = tracker.exercises[i];
            printf("%d. %s (%d sets of %d reps)\n", i+1, currentExercise.name, currentExercise.sets, currentExercise.reps);
        }
    }
}