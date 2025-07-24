//FormAI DATASET v1.0 Category: Movie Rating System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int rate_movie();

int main() {
    int rating = rate_movie();

    printf("The movie's rating is %d out of 10", rating);
    return 0;
}

int rate_movie() {
    int rating;

    printf("Please rate the movie out of 10:");
    scanf("%d", &rating);

    if (rating > 10 || rating < 1) {
        printf("Invalid rating. Please enter a rating between 1 and 10.\n");
        return rate_movie();
    }

    return rating;
}