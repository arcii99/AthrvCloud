//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_LEN 100 // Maximum length of user input.

struct Exercise {
    char name[20];
    int sets;
    int reps;
    float weight;
} currentExercise; // Structure for holding the user's current exercise.

int main() {
    char input[MAX_INPUT_LEN]; // User input.
    bool tracking = true; // Whether the program is still tracking the user's exercises.

    printf("\nWelcome to the C Fitness Tracker!\n\n");

    while (tracking) {
        printf("Enter the name of the exercise you completed (or 'quit' to exit):\n");
        fgets(input, MAX_INPUT_LEN, stdin); // Get user input.

        if (strcmp(input, "quit\n") == 0) {
            printf("\nThanks for using the C Fitness Tracker! Your progress has been saved.\n");
            tracking = false; // Exit loop.
        } else {
            strncpy(currentExercise.name, input, strlen(input)-1); // Copy name to struct, removing newline.
            printf("Enter the number of sets you completed:\n");
            fgets(input, MAX_INPUT_LEN, stdin);
            currentExercise.sets = atoi(input); // Convert input to int and store in struct.
            printf("Enter the number of reps per set:\n");
            fgets(input, MAX_INPUT_LEN, stdin);
            currentExercise.reps = atoi(input);
            printf("Enter the weight used (in pounds):\n");
            fgets(input, MAX_INPUT_LEN, stdin);
            currentExercise.weight = strtof(input, NULL); // Convert input to float and store in struct.

            // Print out the user's current exercise info.
            printf("\nExercise: %s\n", currentExercise.name);
            printf("Sets: %d\n", currentExercise.sets);
            printf("Reps per set: %d\n", currentExercise.reps);
            printf("Weight used: %.2f lbs.\n\n", currentExercise.weight);
        }
    }

    return 0;
}