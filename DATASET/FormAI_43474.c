//FormAI DATASET v1.0 Category: Movie Rating System ; Style: all-encompassing
#include <stdio.h>

// Declare variables
int rating, total = 0, counter = 0;
float average;

// Main function
int main() {
    
    printf("Welcome to the Movie Rating System!\n\n");

    // Do while loop to input ratings until user enters -1
    do {
        
        // Prompt user to enter a rating
        printf("Please enter a rating between 0 and 10 (enter -1 to exit): ");
        scanf("%d", &rating);

        // Check if rating is within range
        if (rating >= 0 && rating <= 10) {
            total += rating; // Add rating to total
            counter++; // Increment counter
        }

        // If rating is outside of range, give error message
        else if (rating != -1) {
            printf("Invalid rating. Please enter a rating between 0 and 10.\n");
        }

    } while (rating != -1);

    // Calculate average rating
    if (counter != 0) {
        average = ((float)total / counter);
        printf("\nNumber of ratings: %d\n", counter);
        printf("Average rating: %.2f\n", average);
    }
    
    // If there are no ratings, give error message
    else {
        printf("\nNo ratings entered. Please try again later.\n");
    }

    return 0;
}