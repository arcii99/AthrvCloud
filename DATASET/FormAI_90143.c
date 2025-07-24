//FormAI DATASET v1.0 Category: Movie Rating System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct movie {
    char title[50];
    int rating;
};

int main() {
    int num_movies;
    printf("How many movies would you like to rate? ");
    scanf("%d", &num_movies);

    // Dynamically allocate memory for an array of movies
    struct movie* movies = malloc(num_movies * sizeof(struct movie));

    // Prompt user for movie titles and ratings
    for (int i = 0; i < num_movies; i++) {
        printf("Enter the title and rating of movie #%d: ", i+1);
        scanf("%s %d", movies[i].title, &movies[i].rating);
    }

    // Sort movies by rating using bubble sort
    for (int i = 0; i < num_movies - 1; i++) {
        for (int j = 0; j < num_movies - i - 1; j++) {
            if (movies[j].rating < movies[j+1].rating) {
                struct movie temp = movies[j];
                movies[j] = movies[j+1];
                movies[j+1] = temp;
            }
        }
    }

    // Print out movies in decreasing order of rating
    printf("Your movie ratings, from highest to lowest:\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%d. %s - %d\n", i+1, movies[i].title, movies[i].rating);
    }

    // Free dynamically allocated memory
    free(movies);

    return 0;
}