//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    int day = 0;
    int calories = 0;
    int steps = 0;
    int pushups = 0;
    int squats = 0;
    int situps = 0;
    char choice[10];
    srand(time(NULL)); // Seed rand

    printf("Welcome to the post-apocalyptic fitness tracker!\n");

    while (1) { // Loop until user decides to quit
        printf("\n--- Day %d ---\n", day+1);
        printf("Calories burned: %d\n", calories);
        printf("Steps taken: %d\n", steps);
        printf("Push-ups completed: %d\n", pushups);
        printf("Squats completed: %d\n", squats);
        printf("Sit-ups completed: %d\n\n", situps);
        printf("What would you like to do?\n");
        printf("1. Walk\n");
        printf("2. Run\n");
        printf("3. Do push-ups\n");
        printf("4. Do squats\n");
        printf("5. Do sit-ups\n");
        printf("6. Quit\n");
        printf("Enter choice: ");
        fgets(choice, 10, stdin);

        if (strcmp(choice, "1\n") == 0) {
            int distance = rand() % 5 + 1; // Generate random distance from 1-5
            printf("You walked %d miles!\n", distance);
            calories += (distance * 50); // Burn 50 calories per mile
            steps += (distance * 2000); // Walk 2000 steps per mile
        } else if (strcmp(choice, "2\n") == 0) {
            int distance = rand() % 5 + 1; // Generate random distance from 1-5
            printf("You ran %d miles!\n", distance);
            calories += (distance * 75); // Burn 75 calories per mile
            steps += (distance * 3000); // Run 3000 steps per mile
        } else if (strcmp(choice, "3\n") == 0) {
            int reps = rand() % 10 + 1; // Generate random number of reps from 1-10
            printf("You did %d push-ups!\n", reps);
            calories += (reps * 10); // Burn 10 calories per push-up
            pushups += reps;
        } else if (strcmp(choice, "4\n") == 0) {
            int reps = rand() % 10 + 1; // Generate random number of reps from 1-10
            printf("You did %d squats!\n", reps);
            calories += (reps * 8); // Burn 8 calories per squat
            squats += reps;
        } else if (strcmp(choice, "5\n") == 0) {
            int reps = rand() % 10 + 1; // Generate random number of reps from 1-10
            printf("You did %d sit-ups!\n", reps);
            calories += (reps * 7); // Burn 7 calories per sit-up
            situps += reps;
        } else if (strcmp(choice, "6\n") == 0) {
            printf("Thanks for using the post-apocalyptic fitness tracker!\n");
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }

        day++; // Increment day counter
    }

    return 0;
}