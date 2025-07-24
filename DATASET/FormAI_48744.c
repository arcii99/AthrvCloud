//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Linus Torvalds
#include <stdio.h>

// Function to rate the movie
int rate_movie(char movie_title[], int year, int rating) {
    printf("You have rated the movie %s released in %d, %d out of 10\n", movie_title, year, rating);
    if (rating >= 8) {
        printf("Excellent movie! You should definitely watch it again!\n");
    } else if (rating >= 5 && rating < 8) {
        printf("Not bad, but not great either. Watch it if you have time.\n");
    } else {
        printf("Sorry, this movie is not worth watching.\n");
    }
}

int main() {
    char movie_title[50];
    int year, rating;

    printf("Please enter the movie title: ");
    scanf("%s", movie_title);

    printf("Please enter the release year: ");
    scanf("%d", &year);

    printf("Please rate the movie (out of 10): ");
    scanf("%d", &rating);

    rate_movie(movie_title, year, rating);

    return 0;
}