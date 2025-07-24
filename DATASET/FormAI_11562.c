//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: optimized
#include <stdio.h>
#include <string.h>

// struct to hold fitness data
typedef struct {
    int steps;
    int calories;
    int distance;
} fitnessData;

int main() {
    // initialize fitness data struct
    fitnessData today = {0, 0, 0};
    
    // display menu and get user input
    int choice = 0;
    do {
        printf("Fitness Tracker\n");
        printf("1. Record Steps\n");
        printf("2. Record Calories\n");
        printf("3. Record Distance\n");
        printf("4. Display Today's Data\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        // process user input
        switch(choice) {
            case 1:
                // get number of steps from user and add to today's data
                int steps;
                printf("Enter number of steps: ");
                scanf("%d", &steps);
                today.steps += steps;
                break;
            case 2:
                // get number of calories from user and add to today's data
                int calories;
                printf("Enter number of calories: ");
                scanf("%d", &calories);
                today.calories += calories;
                break;
            case 3:
                // get distance from user and add to today's data
                int distance;
                printf("Enter distance: ");
                scanf("%d", &distance);
                today.distance += distance;
                break;
            case 4:
                // display today's fitness data
                printf("Today's Fitness Data\n");
                printf("Steps: %d\n", today.steps);
                printf("Calories: %d\n", today.calories);
                printf("Distance: %d\n", today.distance);
                break;
            case 5:
                // exit program
                break;
            default:
                // invalid option
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 5);
    
    return 0;
}