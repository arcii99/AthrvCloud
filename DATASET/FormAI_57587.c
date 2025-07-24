//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 1000
#define MAX_WORKOUTS_PER_USER 100

// Struct to hold workout information
typedef struct {
    char name[50];
    int duration;
    int caloriesBurned;
} Workout;

// Struct to hold user information including their workouts
typedef struct {
    char username[50];
    char password[50];
    Workout workouts[MAX_WORKOUTS_PER_USER];
    int numWorkouts;
    int totalDuration;
    int totalCaloriesBurned;
} User;

// Global array to hold all users
User users[MAX_USERS];
int numUsers = 0;

// Function to add a user to the system
void addUser(char username[], char password[]) {
    // Check if the user already exists
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Error: User already exists\n");
            return;
        }
    }

    // Create the new user and add it to the array
    User newUser;
    strcpy(newUser.username, username);
    strcpy(newUser.password, password);
    newUser.numWorkouts = 0;
    newUser.totalDuration = 0;
    newUser.totalCaloriesBurned = 0;

    users[numUsers++] = newUser;
}

// Function to login a user and return their index in the users array
int login(char username[], char password[]) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return i;
        }
    }

    printf("Error: Invalid username or password\n");
    return -1;
}

// Function to add a workout for a user
void addWorkout(int userIndex, char workoutName[], int duration, int caloriesBurned) {
    // Make sure the userIndex is valid
    if (userIndex < 0 || userIndex >= numUsers) {
        printf("Error: Invalid user index\n");
        return;
    }

    // Check if the user has reached the max number of workouts per user
    if (users[userIndex].numWorkouts == MAX_WORKOUTS_PER_USER) {
        printf("Error: Max number of workouts reached for user %s\n", users[userIndex].username);
        return;
    }

    // Add the workout to the user's workouts array
    Workout newWorkout;
    strcpy(newWorkout.name, workoutName);
    newWorkout.duration = duration;
    newWorkout.caloriesBurned = caloriesBurned;

    users[userIndex].workouts[users[userIndex].numWorkouts++] = newWorkout;
    users[userIndex].totalDuration += duration;
    users[userIndex].totalCaloriesBurned += caloriesBurned;

    printf("Workout added for user %s\n", users[userIndex].username);
}

// Function to display all of a user's workouts
void displayWorkouts(int userIndex) {
    // Make sure the userIndex is valid
    if (userIndex < 0 || userIndex >= numUsers) {
        printf("Error: Invalid user index\n");
        return;
    }

    printf("Workouts for user %s:\n", users[userIndex].username);
    printf("Name\tDuration\tCalories Burned\n");

    for (int i = 0; i < users[userIndex].numWorkouts; i++) {
        printf("%s\t%d\t\t%d\n", users[userIndex].workouts[i].name, users[userIndex].workouts[i].duration, users[userIndex].workouts[i].caloriesBurned);
    }

    printf("Total Duration: %d minutes\n", users[userIndex].totalDuration);
    printf("Total Calories Burned: %d calories\n", users[userIndex].totalCaloriesBurned);
}

// Main function
int main() {
    int choice, userIndex;
    char username[50], password[50], workoutName[50];
    int duration, caloriesBurned;

    // Loop until the user chooses to exit
    do {
        printf("\n1. Add user\n");
        printf("2. Login\n");
        printf("3. Add workout\n");
        printf("4. Display workouts\n");
        printf("0. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);

                addUser(username, password);
                break;

            case 2:
                printf("\nEnter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);

                userIndex = login(username, password);
                break;

            case 3:
                if (userIndex == -1) {
                    printf("Error: Not logged in\n");
                    break;
                }

                printf("\nEnter workout name: ");
                scanf("%s", workoutName);
                printf("Enter duration in minutes: ");
                scanf("%d", &duration);
                printf("Enter calories burned: ");
                scanf("%d", &caloriesBurned);

                addWorkout(userIndex, workoutName, duration, caloriesBurned);
                break;

            case 4:
                if (userIndex == -1) {
                    printf("Error: Not logged in\n");
                    break;
                }

                displayWorkouts(userIndex);
                break;

            case 0:
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nInvalid choice\n");
        }
    } while (choice != 0);

    return 0;
}