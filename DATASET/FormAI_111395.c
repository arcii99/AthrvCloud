//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Fitness tracker data structure
struct fitness_tracker {
    char username[20];
    int age;
    float weight;
    float height;
    float bmi;
    int steps;
    int calories_burned;
    int water_intake;
    int workouts_completed;
};

// Function to calculate BMI
float calculate_bmi(float w, float h) {
    return w / (h * h);
}

// Function to update user data
void update_data(struct fitness_tracker* user) {
    int choice;
    float new_weight, new_height;
    printf("\nEnter your choice:\n");
    printf("1. Update weight\n");
    printf("2. Update height\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("Enter new weight (kg): ");
            scanf("%f", &new_weight);
            user->weight = new_weight;
            user->bmi = calculate_bmi(user->weight, user->height);
            break;
        case 2:
            printf("Enter new height (m): ");
            scanf("%f", &new_height);
            user->height = new_height;
            user->bmi = calculate_bmi(user->weight, user->height);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

int main() {
    struct fitness_tracker user;

    // Get user details
    printf("Enter your username: ");
    scanf("%s", user.username);
    printf("Enter your age: ");
    scanf("%d", &user.age);
    printf("Enter your weight (kg): ");
    scanf("%f", &user.weight);
    printf("Enter your height (m): ");
    scanf("%f", &user.height);

    // Calculate bmi
    user.bmi = calculate_bmi(user.weight, user.height);

    // Set initial values for other parameters
    user.steps = 0;
    user.calories_burned = 0;
    user.water_intake = 0;
    user.workouts_completed = 0;

    // Start fitness tracking loop
    while(true) {
        int choice;
        printf("\n%s fitness tracker:\n", user.username);
        printf("BMI: %.2f\n", user.bmi);
        printf("Steps: %d\n", user.steps);
        printf("Calories burned: %d\n", user.calories_burned);
        printf("Water intake: %d ml\n", user.water_intake);
        printf("Workouts completed: %d\n\n", user.workouts_completed);

        printf("Enter your choice:\n");
        printf("1. Update weight/height\n");
        printf("2. Record steps\n");
        printf("3. Record water intake\n");
        printf("4. Record workout\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        // Update user data based on user's choice
        switch(choice) {
            case 1:
                update_data(&user);
                break;
            case 2:
                int steps;
                printf("Enter number of steps recorded: ");
                scanf("%d", &steps);
                user.steps += steps;
                user.calories_burned += (steps * 0.05);
                break;
            case 3:
                int water;
                printf("Enter amount of water consumed (ml): ");
                scanf("%d", &water);
                user.water_intake += water;
                break;
            case 4:
                user.workouts_completed++;
                user.calories_burned += 100;
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}