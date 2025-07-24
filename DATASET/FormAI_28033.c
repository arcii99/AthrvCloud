//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: standalone
#include <stdio.h>

int main() {
    int year, choice;
    
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please enter the year you would like to travel to: ");
    scanf("%d", &year);
    
    printf("You have traveled back to the year %d!\n", year);
    
    printf("What would you like to learn about?\n");
    printf("1. Popular events in %d\n", year);
    printf("2. Inventions from %d\n", year);
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Popular events in %d:\n", year);
            // code to display popular events
            break;
        case 2:
            printf("Inventions from %d:\n", year);
            // code to display inventions
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    
    printf("Thank you for using the Time Travel Simulator!\n");
    
    return 0;
}