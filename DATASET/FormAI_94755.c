//FormAI DATASET v1.0 Category: Movie Rating System ; Style: configurable
#include <stdio.h>

// Define struct for movie rating
typedef struct {
    char title[50];
    char director[50];
    char genre[20];
    float rating;
} Movie;

// Define function to display movie information
void displayMovie(Movie movie) {
    printf("Title: %s\n", movie.title);
    printf("Director: %s\n", movie.director);
    printf("Genre: %s\n", movie.genre);
    printf("Rating: %.1f\n", movie.rating);
    printf("\n");
}

int main() {
    // Define array of movies
    Movie movies[5] = {
        {"The Shawshank Redemption", "Frank Darabont", "Drama", 9.3},
        {"The Godfather", "Francis Ford Coppola", "Crime, Drama", 9.2},
        {"The Dark Knight", "Christopher Nolan", "Action, Crime, Drama", 9.0},
        {"12 Angry Men", "Sidney Lumet", "Drama", 8.9},
        {"Schindler's List", "Steven Spielberg", "Biography, Drama, History", 8.9}
    };
    
    // Display all movies in the array
    for (int i = 0; i < 5; i++) {
        displayMovie(movies[i]);
    }
    
    return 0;
}