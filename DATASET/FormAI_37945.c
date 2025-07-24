//FormAI DATASET v1.0 Category: Movie Rating System ; Style: future-proof
#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 1000

/* Struct for storing movie info */
typedef struct {
    char title[50];
    char director[50];
    int year;
    float rating;
} Movie;

/* Array of Movie structs */
Movie movies[MAX_MOVIES];

/* Number of movies in the array */
int num_movies = 0;

/* Function to add a new movie to the array */
void add_movie(char title[], char director[], int year, float rating) {
    /* Ensure there's room in the array */
    if (num_movies < MAX_MOVIES) {
        /* Copy input data into new Movie struct */
        Movie new_movie;
        strcpy(new_movie.title, title);
        strcpy(new_movie.director, director);
        new_movie.year = year;
        new_movie.rating = rating;
        /* Add the new movie to the array */
        movies[num_movies] = new_movie;
        num_movies++;
        printf("Movie added successfully.\n");
    } else {
        printf("Sorry, no more room for new movies.\n");
    }
}

/* Function to print a single movie */
void print_movie(Movie movie) {
    printf("%s\nDirector: %s\nYear: %d\nRating: %.1f/10\n\n", movie.title, movie.director, movie.year, movie.rating);
}

/* Function to print all movies in the array */
void print_all_movies() {
    if (num_movies == 0) {
        printf("No movies found.\n");
    } else {
        for (int i = 0; i < num_movies; i++) {
            printf("Movie %d:\n", i+1);
            print_movie(movies[i]);
        }
    }
}

int main() {
    /* Example usage */
    add_movie("The Shawshank Redemption", "Frank Darabont", 1994, 9.3);
    add_movie("The Godfather", "Francis Ford Coppola", 1972, 9.2);
    add_movie("The Dark Knight", "Christopher Nolan", 2008, 9.0);
    add_movie("12 Angry Men", "Sidney Lumet", 1957, 8.9);

    print_all_movies();

    return 0;
}