//FormAI DATASET v1.0 Category: Movie Rating System ; Style: complex
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define variables
    int rating, totalRatings = 0;
    double averageRating = 0.0;
    char movieTitle[50], choice;

    // Create a loop for multiple movie ratings
    do {
        // Get movie title from user
        printf("Enter movie title: ");
        scanf("%s", movieTitle);

        // Get movie rating from user
        printf("Enter movie rating (1-10): ");
        scanf("%d", &rating);

        // Check if rating is valid
        if (rating < 1 || rating > 10) {
            printf("Invalid rating. Please enter a rating between 1 and 10.\n");
            continue;
        }

        // Add rating to total and increment total number of ratings
        totalRatings += rating;
        averageRating = (double) totalRatings / (double) ++averageRating;

        // Ask user if they want to rate another movie
        printf("Do you want to rate another movie? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    // Display average rating
    printf("The average rating for %s is %.2f.\n", movieTitle, averageRating);

    return 0;
}