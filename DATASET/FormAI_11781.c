//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare structs for user and workout data
struct User {
    char name[20];
    int age;
    float height;
    float weight;
};

struct Workout {
    char name[20];
    int sets;
    int reps;
    float weight;
};

// Declare function to add new user
void addUser(struct User *users, int *userCount) {
    printf("Enter name: ");
    scanf("%s", users[*userCount].name);
    printf("Enter age: ");
    scanf("%d", &users[*userCount].age);
    printf("Enter height (m): ");
    scanf("%f", &users[*userCount].height);
    printf("Enter weight (kg): ");
    scanf("%f", &users[*userCount].weight);
    (*userCount)++;
}

// Declare function to add new workout
void addWorkout(struct User user, struct Workout *workouts, int *workoutCount) {
    printf("Enter workout name: ");
    scanf("%s", workouts[*workoutCount].name);
    printf("Enter sets: ");
    scanf("%d", &workouts[*workoutCount].sets);
    printf("Enter reps: ");
    scanf("%d", &workouts[*workoutCount].reps);
    printf("Enter weight (kg): ");
    scanf("%f", &workouts[*workoutCount].weight);

    // Calculate calories burned during workout
    float caloriesBurned = user.weight * workouts[*workoutCount].sets * workouts[*workoutCount].reps * workouts[*workoutCount].weight;
    printf("You burned %.2f calories!\n", caloriesBurned);

    (*workoutCount)++;
}

// Declare function to display user profile
void displayUser(struct User user) {
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Height: %.2fm\n", user.height);
    printf("Weight: %.2fkg\n", user.weight);
}

// Declare function to display workout history
void displayWorkouts(struct Workout *workouts, int workoutCount) {
    printf("Workout History:\n");
    for (int i = 0; i < workoutCount; i++) {
        printf("%s - Sets: %d, Reps: %d, Weight: %.2fkg\n", workouts[i].name, workouts[i].sets, workouts[i].reps, workouts[i].weight);
    }
}

int main() {
    struct User users[10];
    struct Workout workouts[50];
    int userCount = 0;
    int workoutCount = 0;

    // Display menu options
    while (1) {
        printf("Menu:\n");
        printf("1. Add user\n");
        printf("2. Add workout\n");
        printf("3. Display user profile\n");
        printf("4. Display workout history\n");
        printf("0. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser(users, &userCount);
                break;
            case 2:
                if (userCount == 0) {
                    printf("Error: No users found. Please add a user first.\n");
                } else {
                    addWorkout(users[userCount-1], workouts, &workoutCount);
                }
                break;
            case 3:
                if (userCount == 0) {
                    printf("Error: No users found. Please add a user first.\n");
                } else {
                    displayUser(users[userCount-1]);
                }
                break;
            case 4:
                if (workoutCount == 0) {
                    printf("No workouts found.\n");
                } else {
                    displayWorkouts(workouts, workoutCount);
                }
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}