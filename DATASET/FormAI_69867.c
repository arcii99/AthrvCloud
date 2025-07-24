//FormAI DATASET v1.0 Category: Movie Rating System ; Style: expert-level
#include <stdio.h>

// Defining a struct to hold movie information
struct Movie {
    char title[50];
    char director[50];
    int releaseYear;
    double rating;
};

// Function to print out the details of a movie
void printMovie(struct Movie *movie) {
    printf("Title: %s\nDirector: %s\nRelease Year: %d\nRating: %.1f\n\n",
           movie->title, movie->director, movie->releaseYear, movie->rating);
}

int main() {
    // Initializing an array of Movie structs
    struct Movie movies[5] = {
        {"The Godfather", "Francis Ford Coppola", 1972, 9.2},
        {"The Shawshank Redemption", "Frank Darabont", 1994, 9.3},
        {"The Dark Knight", "Christopher Nolan", 2008, 9.0},
        {"Pulp Fiction", "Quentin Tarantino", 1994, 8.9},
        {"Fight Club", "David Fincher", 1999, 8.8}
    };

    // Printing out the initial list of movie details
    printf("Initial Ratings:\n");
    for (int i = 0; i < 5; i++) {
        printMovie(&movies[i]);
    }

    // Taking user input to update movie ratings
    for (int i = 0; i < 5; i++) {
        printf("Please rate '%s' on a scale of 0.0 to 10.0: ", movies[i].title);
        scanf("%lf", &movies[i].rating);
    }

    // Printing out the updated list of movie details
    printf("\nUpdated Ratings:\n");
    for (int i = 0; i < 5; i++) {
        printMovie(&movies[i]);
    }

    return 0;
}