//FormAI DATASET v1.0 Category: Movie Rating System ; Style: ultraprecise
#include <stdio.h>

int main() {
    int rating;
    int total_ratings = 0;
    double average_rating = 0;

    printf("Welcome to the Unique C Movie Rating System!\n");

    do {
        printf("Please rate the movie on a scale of 1 to 10: ");
        scanf("%d", &rating);
        if ( rating > 10 || rating < 1 ) {
            printf("Invalid rating. Please enter a rating between 1 and 10.\n");
            continue;
        }
        total_ratings++;
        average_rating = ( average_rating * ( total_ratings - 1 ) + rating ) / total_ratings;
        printf("Thank you for submitting your rating!\n");
    } while ( total_ratings < 10 );

    printf("All 10 ratings have been submitted. The average rating for the movie is %.2f.\n", average_rating);

    return 0;
}