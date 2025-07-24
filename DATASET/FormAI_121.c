//FormAI DATASET v1.0 Category: Database querying ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a movie
typedef struct {
    char title[50];
    char director[50];
    int year;
} Movie;

// Define a function to display a movie's information
void display_movie(Movie movie) {
    printf("Title: %s\n", movie.title);
    printf("Director: %s\n", movie.director);
    printf("Year: %d\n", movie.year);
}

int main() {
    // Define an array of movies
    Movie movies[5];
    strcpy(movies[0].title, "The Godfather");
    strcpy(movies[0].director, "Francis Ford Coppola");
    movies[0].year = 1972;
    strcpy(movies[1].title, "Pulp Fiction");
    strcpy(movies[1].director, "Quentin Tarantino");
    movies[1].year = 1994;
    strcpy(movies[2].title, "The Dark Knight");
    strcpy(movies[2].director, "Christopher Nolan");
    movies[2].year = 2008;
    strcpy(movies[3].title, "Inception");
    strcpy(movies[3].director, "Christopher Nolan");
    movies[3].year = 2010;
    strcpy(movies[4].title, "Jaws");
    strcpy(movies[4].director, "Steven Spielberg");
    movies[4].year = 1975;

    // Allow the user to search for movies
    printf("Search for movies by:\n");
    printf("1. Title\n");
    printf("2. Director\n");
    printf("3. Release Year\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    // Get the search term from the user
    char term[50];
    printf("Enter search term: ");
    scanf("%s", term);

    switch (choice) {
        case 1:
            // Search by title
            for (int i = 0; i < 5; i++) {
                if (strcmp(movies[i].title, term) == 0) {
                    display_movie(movies[i]);
                }
            }
            break;
        case 2:
            // Search by director
            for (int i = 0; i < 5; i++) {
                if (strcmp(movies[i].director, term) == 0) {
                    display_movie(movies[i]);
                }
            }
            break;
        case 3:
            // Search by release year
            for (int i = 0; i < 5; i++) {
                if (movies[i].year == atoi(term)) {
                    display_movie(movies[i]);
                }
            }
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}