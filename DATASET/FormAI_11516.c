//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORKOUTS 100
#define MAX_NAME_LENGTH 20

struct workout {
    char name[MAX_NAME_LENGTH];
    int duration;
    int calories_burned;
};

int main() {
    struct workout workouts[MAX_WORKOUTS];
    int num_workouts = 0;
    int total_calories_burned = 0;
    char secret_code[10];

    // Generate a secret code
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        secret_code[i] = rand() % 26 + 'A';
    }

    printf("Welcome to your paranoid C Fitness Tracker!\n");
    printf("Enter the secret code to access the program:\n");

    // Get user input for secret code
    char input_code[10];
    fgets(input_code, 10, stdin);

    // Check if secret code is correct
    if (strcmp(input_code, secret_code) == 0) {
        printf("Access granted.\n");
        printf("Enter a workout name, duration, and calories burned.\n");
        printf("Type 'quit' to exit program.\n");

        // Get user input for workouts
        char name[MAX_NAME_LENGTH];
        int duration;
        int calories_burned;

        do {
            printf("Workout name: ");
            fgets(name, MAX_NAME_LENGTH, stdin);

            if (strcmp(name, "quit\n") == 0) {
                break;
            }

            printf("Duration (in minutes): ");
            scanf("%d", &duration);

            printf("Calories burned: ");
            scanf("%d", &calories_burned);

            // Add the workout to the array
            struct workout new_workout;
            strcpy(new_workout.name, name);
            new_workout.duration = duration;
            new_workout.calories_burned = calories_burned;

            workouts[num_workouts] = new_workout;
            num_workouts++;
            total_calories_burned += calories_burned;

            // Clear input buffer
            char c;
            while ((c = getchar()) != '\n' && c != EOF);

            printf("Workout added!\n");

        } while (num_workouts < MAX_WORKOUTS);

        printf("Maximum number of workouts reached.\n");

    } else {
        printf("Incorrect secret code. Program terminated.\n");
        exit(EXIT_FAILURE);
    }

    printf("Program terminated.\n");
    return 0;
}