//FormAI DATASET v1.0 Category: Movie Rating System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main() {
    int total_movies;
    int i;

    printf("Enter the total number of movies: ");
    scanf("%d", &total_movies);

    float ratings[total_movies];

    for(i=0; i<total_movies; i++) {
        printf("\nEnter the rating for movie %d (out of 10): ", i+1);
        scanf("%f", &ratings[i]);
    }

    float ratings_sum = 0;
    for(i=0; i<total_movies; i++) {
        ratings_sum += ratings[i];
    }

    float avg_rating = ratings_sum / total_movies;
    printf("\nAverage rating of all movies: %.2f", avg_rating);

    float variance_sum = 0;
    for(i=0; i<total_movies; i++) {
        variance_sum += (ratings[i] - avg_rating) * (ratings[i] - avg_rating);
    }

    float variance = variance_sum / total_movies;
    printf("\nVariance of all movies: %.2f", variance);

    float std_deviation = sqrt(variance);
    printf("\nStandard deviation of all movies: %.2f", std_deviation);

    return 0;
}