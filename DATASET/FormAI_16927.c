//FormAI DATASET v1.0 Category: Movie Rating System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define constants for the minimum and maximum movie ratings
#define MIN_RATING 0
#define MAX_RATING 10

// Define the Movie struct
typedef struct {
    char title[100];
    char genre[50];
    int rating;
} Movie;

// Declare functions
void addMovie(Movie *movies, int *movieCount);
void rateMovie(Movie *movies, int movieCount);
void displayMovies(Movie *movies, int movieCount);

int main() {
    // Declare variables
    char choice;
    int movieCount = 0;
    Movie *movies = (Movie*) malloc(sizeof(Movie));
    
    printf("Welcome to the C Movie Rating System!\n\n");

    // Loop through program until user chooses to exit
    do {
        printf("Enter your choice:\n");
        printf("a) Add a movie\n");
        printf("b) Rate a movie\n");
        printf("c) Display all movies\n");
        printf("x) Exit\n");
        scanf(" %c", &choice);

        switch(choice) {
            case 'a':
                addMovie(movies, &movieCount);
                printf("Movie added successfully!\n\n");
                break;
            case 'b':
                rateMovie(movies, movieCount);
                break;
            case 'c':
                displayMovies(movies, movieCount);
                break;
            case 'x':
                printf("Thank you for using the C Movie Rating System! Goodbye.\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    } while(choice != 'x');

    // Free allocated memory
    free(movies);

    return 0;
}

void addMovie(Movie *movies, int *movieCount) {
    // Prompt user for movie information
    printf("Enter the movie title (max 100 characters): ");
    scanf("%99s", movies[*movieCount].title);
    printf("Enter the movie genre (max 50 characters): ");
    scanf("%49s", movies[*movieCount].genre);
    movies[*movieCount].rating = -1; // initialize rating to invalid value

    // Increase movie count
    (*movieCount)++;
    
    // Reallocate memory for movies array
    movies = (Movie*) realloc(movies, (*movieCount + 1) * sizeof(Movie));
}

void rateMovie(Movie *movies, int movieCount) {
    // Prompt user for movie title
    char title[100];
    printf("Enter the title of the movie you would like to rate: ");
    scanf("%99s", title);

    // Search for movie by title
    int found = 0;
    for(int i = 0; i < movieCount; i++) {
        if(strcmp(movies[i].title, title) == 0) {
            found = 1;
            // Prompt user for movie rating
            int rating;
            do {
                printf("Enter a rating from %d to %d: ", MIN_RATING, MAX_RATING);
                scanf("%d", &rating);
                if(rating < MIN_RATING || rating > MAX_RATING)
                    printf("Invalid rating. Please try again.\n");
            } while(rating < MIN_RATING || rating > MAX_RATING);
            // Set movie rating
            movies[i].rating = rating;
            printf("Movie rating updated successfully!\n\n");
            break;
        }
    }
    if(!found)
        printf("Movie not found.\n\n");
}

void displayMovies(Movie *movies, int movieCount) {
    if(movieCount == 0) {
        printf("No movies found.\n\n");
        return;
    }
    printf("Movies:\n");
    for(int i = 0; i < movieCount; i++) {
        printf("%d. %s: %s", i+1, movies[i].title, movies[i].genre);
        if(movies[i].rating >= 0)
            printf(" (rating: %d)\n", movies[i].rating);
        else
            printf(" (not rated)\n");
    }
    printf("\n");
}