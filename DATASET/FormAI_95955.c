//FormAI DATASET v1.0 Category: Movie Rating System ; Style: standalone
#include <stdio.h>

int main() {
    int rating; // user input rating
    float total_score = 0; // total score of all ratings
    int count = 0; // number of ratings given
    float average_rating; // average rating of all ratings
    char choice; // choice to continue or exit loop

    printf("Welcome to the Unique C Movie Rating System!\n\n");

    do {
        printf("What rating would you give this movie? (1-10)\n");
        scanf("%d", &rating);

        // check if rating is between 1-10 inclusive
        if (rating >= 1 && rating <= 10) {
            total_score += rating;
            count++;
        } else {
            printf("Invalid rating! Please enter a rating between 1-10.\n");
            continue;
        }

        printf("Would you like to rate another movie? (y/n)\n");
        scanf(" %c", &choice);

        // check if choice is either y or n
        while (choice != 'y' && choice != 'n') {
            printf("Invalid choice! Please enter either y or n.\n");
            printf("Would you like to rate another movie? (y/n)\n");
            scanf(" %c", &choice);
        }
    } while (choice != 'n');

    // calculate average rating if any ratings were given
    if (count > 0) {
        average_rating = total_score / count;
        printf("\nThe average rating for all movies is %.2f\n", average_rating);
        printf("Thank you for using the Unique C Movie Rating System!\n");
    } else {
        printf("\nNo ratings were given.\n");
        printf("Thank you for using the Unique C Movie Rating System!\n");
    }

    return 0;
}