//FormAI DATASET v1.0 Category: Movie Rating System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold movie details
struct Movie {
    char title[50];
    char director[50];
    int year;
    float rating; // Rating is out of 10
};

// Function to create a new movie
struct Movie createMovie(char title[50], char director[50], int year, float rating) {
    struct Movie newMovie;
    strcpy(newMovie.title, title);
    strcpy(newMovie.director, director);
    newMovie.year = year;
    newMovie.rating = rating;
    return newMovie;
}

// Function to print a movie's details
void printMovie(struct Movie movie) {
    printf("Title: %s\n", movie.title);
    printf("Director: %s\n", movie.director);
    printf("Year: %d\n", movie.year);
    printf("Rating: %.1f\n", movie.rating);
    printf("\n");
}

// Function to rate a movie
void rateMovie(struct Movie *moviePtr, float newRating) {
    moviePtr->rating = newRating;
}

int main() {
    // Create a few movies
    struct Movie movie1 = createMovie("The Dark Knight", "Christopher Nolan", 2008, 9.0);
    struct Movie movie2 = createMovie("Pulp Fiction", "Quentin Tarantino", 1994, 8.9);
    struct Movie movie3 = createMovie("The Godfather", "Francis Ford Coppola", 1972, 9.2);

    // Print initial movie details
    printMovie(movie1);
    printMovie(movie2);
    printMovie(movie3);

    // Rate a movie
    rateMovie(&movie2, 9.5);

    // Print updated movie details
    printf("After update:\n");
    printMovie(movie1);
    printMovie(movie2);
    printMovie(movie3);

    return 0;
}