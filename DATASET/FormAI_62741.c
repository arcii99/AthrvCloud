//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the max length of the username and password
#define MAX_LENGTH 20

// Define the max length of the activity name
#define MAX_ACTIVITY_LENGTH 50

// Define the max number of activities that can be logged
#define MAX_ACTIVITIES 100

// Define each activity
struct Activity {
    char name[MAX_ACTIVITY_LENGTH];
    int duration;
    int calories_burned;
};

// Define the user
struct User {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    int total_calories_burned;
    int num_activities;
    struct Activity activities[MAX_ACTIVITIES];
};

// Function prototypes
void login(struct User* user);
void register_user(struct User* user);
void add_activity(struct User* user);
void view_activities(struct User* user);

int main() {
    // Print a welcome message
    printf("Welcome to the C Fitness Tracker!\n");
    
    // Declare a user
    struct User user;
    
    // Prompt the user to login or register
    printf("Please enter 'l' to login or 'r' to register: ");
    char input[2];
    fgets(input, sizeof(input), stdin);
    
    // Handle input
    if (input[0] == 'l') {
        login(&user);
    } else if (input[0] == 'r') {
        register_user(&user);
    } else {
        printf("Invalid input. Please try again.\n");
        return 1;
    }
    
    // Prompt the user for the next action
    while (1) {
        printf("Please enter 'a' to add an activity, 'v' to view your activities, or 'q' to quit: ");
        fgets(input, sizeof(input), stdin);
        
        // Handle input
        if (input[0] == 'a') {
            add_activity(&user);
        } else if (input[0] == 'v') {
            view_activities(&user);
        } else if (input[0] == 'q') {
            printf("Thank you for using the C Fitness Tracker! Goodbye!\n");
            return 0;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }
}

// Login function
void login(struct User* user) {
    // Prompt the user for their username
    printf("Please enter your username: ");
    fgets(user->username, sizeof(user->username), stdin);
    strtok(user->username, "\n"); // Remove trailing newline
    
    // Prompt the user for their password
    printf("Please enter your password: ");
    fgets(user->password, sizeof(user->password), stdin);
    strtok(user->password, "\n"); // Remove trailing newline
    
    // Authenticate the user
    printf("Logging in...\n");
    // ... code to authenticate the user would go here ...
    printf("Login successful!\n");
    
    // Initialize the user's total calories burned and number of activities
    user->total_calories_burned = 0;
    user->num_activities = 0;
}

// Register function
void register_user(struct User* user) {
    // Prompt the user to create a username
    printf("Please create a username: ");
    fgets(user->username, sizeof(user->username), stdin);
    strtok(user->username, "\n"); // Remove trailing newline
    
    // Prompt the user to create a password
    printf("Please create a password: ");
    fgets(user->password, sizeof(user->password), stdin);
    strtok(user->password, "\n"); // Remove trailing newline
    
    printf("Registration successful! Logging in...\n");
    // ... code to authenticate the user would go here ...
    printf("Login successful!\n");
    
    // Initialize the user's total calories burned and number of activities
    user->total_calories_burned = 0;
    user->num_activities = 0;
}

// Add activity function
void add_activity(struct User* user) {
    // Prompt the user for the activity name
    printf("Please enter the name of your activity: ");
    struct Activity activity;
    fgets(activity.name, sizeof(activity.name), stdin);
    strtok(activity.name, "\n"); // Remove trailing newline
    
    // Prompt the user for the activity duration
    printf("Please enter the duration of your activity in minutes: ");
    char duration_input[MAX_LENGTH];
    fgets(duration_input, sizeof(duration_input), stdin);
    activity.duration = atoi(duration_input);
    
    // Calculate the calories burned
    activity.calories_burned = activity.duration * 10;
    
    // Add the activity to the user's list of activities and update their totals
    user->activities[user->num_activities] = activity;
    user->total_calories_burned += activity.calories_burned;
    user->num_activities++;
    
    printf("Activity added successfully!\n");
}

// View activities function
void view_activities(struct User* user) {
    printf("Here are your logged activities:\n");
    for (int i = 0; i < user->num_activities; i++) {
        struct Activity activity = user->activities[i];
        printf("%d. \"%s\" (%d minutes) - %d calories burned\n", i+1, activity.name, activity.duration, activity.calories_burned);
    }
    printf("Total calories burned: %d\n", user->total_calories_burned);
}