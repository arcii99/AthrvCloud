//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the C Movie Rating System!\n");

    int numMovies;
    printf("How many movies would you like to rate? ");
    scanf("%d", &numMovies);

    int *movieRatings = malloc(numMovies * sizeof(int));
    if (movieRatings == NULL) {
        printf("Error: not enough memory available\n");
        exit(1);
    }

    printf("Please rate each movie on a scale from 1 to 10:\n");

    for (int i = 0; i < numMovies; i++) {
        printf("Movie %d: ", i + 1);
        scanf("%d", &movieRatings[i]);
        while (movieRatings[i] < 1 || movieRatings[i] > 10) {
            printf("Invalid rating - please enter a number between 1 and 10: ");
            scanf("%d", &movieRatings[i]);
        }
    }

    int sum = 0;
    for (int i = 0; i < numMovies; i++) {
        sum += movieRatings[i];
    }
    double average = (double)sum / numMovies;

    printf("The average rating for these movies is: %.2f\n", average);

    printf("Here is the list of movies and their ratings:\n");
    for (int i = 0; i < numMovies; i++) {
        printf("Movie %d: %d\n", i + 1, movieRatings[i]);
    }

    free(movieRatings);
    return 0;
}