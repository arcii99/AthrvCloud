//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate time travel
void time_travel(int year) {
    if (year < 0) {
        printf("You have traveled back to a time before the Common Era.\n");
    } else if (year >= 1000) {
        printf("You have traveled forward to a time in the future.\n");
    } else {
        printf("You have traveled to the year %d.\n", year);
    }
}

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Generate random year between -1000 and 3000
    int year = rand() % 4001 - 1000;
    
    // Print current year and prompt for time travel
    printf("Welcome to the Medieval Time Travel Simulator.\n");
    printf("The current year is 1200.\n");
    printf("Would you like to travel to a different year?\n");
    printf("Enter '1' for Yes or '0' for No: ");
    
    // Get user input for time travel
    int choice;
    scanf("%d", &choice);
    
    // If user selects Yes, prompt for year
    if (choice == 1) {
        printf("Enter a year between -1000 and 3000: ");
        scanf("%d", &year);
    }
    
    // Simulate time travel and print result
    time_travel(year);
    
    return 0;
}