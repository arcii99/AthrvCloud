//FormAI DATASET v1.0 Category: Movie Rating System ; Style: portable
#include <stdio.h>

int main() {
    char movie[50];
    int rating, total_ratings, sum_of_ratings, average_rating;

    // Get the name of the movie
    printf("Enter the name of the movie: ");
    scanf("%49s", movie);

    // Get the total number of ratings for the movie
    printf("Enter the total number of ratings for %s: ", movie);
    scanf("%d", &total_ratings);

    // Get the individual ratings and calculate the total sum of ratings
    sum_of_ratings = 0;
    for (int i = 1; i <= total_ratings; i++) {
        printf("Enter the rating for rating %d of %d: ", i, total_ratings);
        scanf("%d", &rating);
        sum_of_ratings += rating;
    }

    // Calculate the average rating
    average_rating = sum_of_ratings / total_ratings;

    // Display the results
    printf("\n");
    printf("Movie: %s\n", movie);
    printf("Average Rating: %d\n", average_rating);

    printf("Rating: ");
    for (int i = 1; i <= average_rating; i++) {
        printf("*");
    }

    printf("\n");

    return 0;
}