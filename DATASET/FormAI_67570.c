//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: medieval
#include <stdio.h>

// Function to calculate calories burned
int calculateCaloriesBurned(int steps) {
    return steps * 0.03;
}

// Function to calculate distance travelled
float calculateDistanceTravelled(int steps) {
    return steps * 0.2;
}

int main() {
    // Declare variables
    int steps = 0;
    char response;

    // Opening statement
    printf("Greetings traveler! Welcome to the medieval fitness tracker.\n");

    // Loop until user chooses to exit
    while (response != 'q') {
        printf("How many steps have you taken on this journey? ");
        scanf("%d", &steps);
        
        // Calculate and display calories burned and distance travelled
        printf("You have burned %d calories and travelled %.1f miles on this journey.\n", calculateCaloriesBurned(steps), calculateDistanceTravelled(steps));
        
        // Ask if user wants to continue or quit
        printf("Do you wish to continue tracking your fitness journey? Press q to quit or any other key to continue.\n");
        scanf(" %c", &response);
    }
    
    // Exit message
    printf("Thank you for using the medieval fitness tracker. Farewell traveller!\n");
    return 0;
}