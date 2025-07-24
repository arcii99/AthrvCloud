//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct to store individual activities and their duration
typedef struct Activity {
    char name[50];
    int duration;
} Activity;

// Struct to represent a fitness tracker user
typedef struct User {
    char name[50];
    int age;
    float weight;
    float height;
    Activity activities[50];
    int num_of_activities;
} User;

// Function to add a new activity to a user's list of activities
void addActivity(User *user) {
    char name[50];
    int duration;

    printf("Enter the name of the activity: ");
    scanf("%s", name);
    printf("Enter the duration of the activity (in minutes): ");
    scanf("%d", &duration);

    // Create new activity struct and add to user's activities
    Activity new_activity;
    strcpy(new_activity.name, name);
    new_activity.duration = duration;
    user->activities[user->num_of_activities++] = new_activity;

    printf("Activity added successfully!\n");
}

// Function to print out all activities for a user
void printActivities(User *user) {
    printf("Activities for user %s:\n", user->name);
    for(int i = 0; i < user->num_of_activities; i++) {
        printf("%s - %d minutes\n", user->activities[i].name, user->activities[i].duration);
    }
}

// Function to calculate a user's body mass index (BMI)
float calculateBMI(User *user) {
    return user->weight / ((user->height / 100) * (user->height / 100));
}

// Function to print out a user's BMI and range
void printBMI(User *user) {
    printf("BMI for user %s: %.2f\n", user->name, calculateBMI(user));

    float lower_range = (18.5 * ((user->height / 100) * (user->height / 100)));
    float upper_range = (24.9 * ((user->height / 100) * (user->height / 100)));

    printf("Healthy BMI range for user %s: %.2f - %.2f\n", user->name, lower_range, upper_range);
}

// Function to get current date as a string
char* getCurrentDate() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char *date = asctime(tm);
    date[strlen(date)-1] = '\0'; // remove newline character from end of string
    return date;
}

int main() {
    // Initialize user struct with default values
    User user;
    strcpy(user.name, "John Doe");
    user.age = 30;
    user.weight = 70.5;
    user.height = 175.0;
    user.num_of_activities = 0;

    int choice = 0;

    while(choice != 4) {
        printf("\nWelcome to Fitness Tracker - %s\n", getCurrentDate());
        printf("1. Add an activity\n");
        printf("2. View all activities\n");
        printf("3. Check BMI\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addActivity(&user);
                break;
            case 2:
                printActivities(&user);
                break;
            case 3:
                printBMI(&user);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}