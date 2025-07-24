//FormAI DATASET v1.0 Category: Movie Rating System ; Style: ultraprecise
#include <stdio.h>

int main() {
    // declare variables
    float movie_length, rating, weighted_rating;
    int num_ratings;

    // prompt user for movie length
    printf("Enter the length of the movie (in minutes): ");
    scanf("%f", &movie_length);

    // prompt user for number of ratings
    printf("Enter the number of user ratings for this movie: ");
    scanf("%d", &num_ratings);

    // prompt user for rating values
    float total_rating = 0;
    for (int i = 1; i <= num_ratings; i++) {
        printf("Enter rating %d (out of 10): ", i);
        float current_rating;
        scanf("%f", &current_rating);
        total_rating += current_rating;
    }

    // calculate weighted rating
    rating = total_rating / num_ratings;
    weighted_rating = (rating * (10 - movie_length/10)) / 2;

    // output results
    printf("The average rating for this movie is: %.2f\n", rating);
    printf("The weighted rating for this movie is: %.2f\n", weighted_rating);

    return 0;
}