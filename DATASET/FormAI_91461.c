//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Exercise {
    char name[20];
    int calories;
};

void addExercise(struct Exercise exercises[], int *numExercises) {
    printf("Enter exercise name: ");
    scanf("%s", exercises[*numExercises].name);
    printf("Enter calories burned per minute: ");
    scanf("%d", &exercises[*numExercises].calories);
    (*numExercises)++;
}

void logExercise(struct Exercise exercises[], int numExercises, int *caloriesBurned, int *totalTime) {
    char input[20];
    int time;
    printf("Enter exercise name: ");
    scanf("%s", input);

    for (int i = 0; i < numExercises; i++) {
        if (strcmp(exercises[i].name, input) == 0) {
            printf("Enter time (minutes): ");
            scanf("%d", &time);
            *caloriesBurned += exercises[i].calories * time;
            *totalTime += time;
            printf("Exercise logged!\n");
            return;
        }
    }
    printf("Exercise not found.\n");
}

int main() {
    struct Exercise exercises[10];
    int numExercises = 0;

    //Initial exercises
    strcpy(exercises[numExercises].name, "Running");
    exercises[numExercises].calories = 10;
    numExercises++;

    strcpy(exercises[numExercises].name, "Swimming");
    exercises[numExercises].calories = 8;
    numExercises++;

    int caloriesBurned = 0;
    int totalTime = 0;

    int choice;
    do {
        printf("--------------------\n");
        printf("Fitness Tracker Menu\n");
        printf("--------------------\n");
        printf("1. Add exercise\n");
        printf("2. Log exercise\n");
        printf("3. View stats\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExercise(exercises, &numExercises);
                break;
            case 2:
                logExercise(exercises, numExercises, &caloriesBurned, &totalTime);
                break;
            case 3:
                printf("Calories burned: %d\n", caloriesBurned);
                printf("Total time: %d minutes\n", totalTime);
                printf("Calories burned per minute: %.2f\n", (float)caloriesBurned/totalTime);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}