//FormAI DATASET v1.0 Category: Movie Rating System ; Style: genious
#include <stdio.h>
#include <string.h>

struct Movie {
    char name[50];
    int rating;
};

int main() {
    int numMovies;
    printf("Enter the number of movies you want to rate: ");
    scanf("%d", &numMovies);

    struct Movie movies[numMovies];

    for (int i = 0; i < numMovies; i++) {
        printf("Enter the name of movie %d: ", i + 1);
        scanf("%s", movies[i].name);
        printf("Enter the rating for '%s' out of 10: ", movies[i].name);
        scanf("%d", &movies[i].rating);

        while (movies[i].rating < 0 || movies[i].rating > 10) {
            printf("Invalid rating! Please enter a rating between 0 and 10.\n");
            scanf("%d", &movies[i].rating);
        }
    }

    printf("Movie Ratings:\n");
    printf("---------------\n");

    for (int i = 0; i < numMovies; i++) {
        printf("%s: %d/10\n", movies[i].name, movies[i].rating);
    }

    int highestRating = 0;
    char highestRatedMovie[50];

    for (int i = 0; i < numMovies; i++) {
        if (movies[i].rating > highestRating) {
            highestRating = movies[i].rating;
            strcpy(highestRatedMovie, movies[i].name);
        }
    }

    printf("The highest rated movie was '%s' with a rating of %d/10.\n", highestRatedMovie, highestRating);

    return 0;
}