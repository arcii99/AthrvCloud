//FormAI DATASET v1.0 Category: Movie Rating System ; Style: ephemeral
#include <stdio.h>

// Struct to store movie information
struct Movie {
    char title[50];
    int year;
    float rating;
};

// Function to rate the movie
void rateMovie(struct Movie *movie) {
    float rating;
    printf("\nEnter your rating for %s: ", movie->title);
    scanf("%f", &rating);
    movie->rating = rating;
    printf("Thank you for rating %s!\n\n", movie->title);
}

int main() {
    // Array of 5 movie structs
    struct Movie movies[5] = {
        {"The Dark Knight", 2008, 0},
        {"Inception", 2010, 0},
        {"Pulp Fiction", 1994, 0},
        {"The Shawshank Redemption", 1994, 0},
        {"Fight Club", 1999, 0}
    };

    printf("Welcome to the Unique C Movie Rating System!\n\n");

    // Loop through each movie and allow user to rate
    for (int i = 0; i < 5; i++) {
        printf("Movie %d: %s (%d)\n", i+1, movies[i].title, movies[i].year);
        rateMovie(&movies[i]);
    }

    // Calculate average rating of all movies
    float totalRating = 0;
    for (int i = 0; i < 5; i++) {
        totalRating += movies[i].rating;
    }
    float averageRating = totalRating / 5;

    printf("Thank you for rating all the movies!\n");
    printf("The average rating of all the movies is: %.2f\n", averageRating);

    return 0;
}