//FormAI DATASET v1.0 Category: Movie Rating System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

typedef struct movie {
    char title[50];
    int rating;
} movie;

int main() {
    int n, i, j;
    printf("How many movies do you want to rate? ");
    scanf("%d", &n);
    movie *movies = (movie*)malloc(n * sizeof(movie));
    if (movies == NULL) {
        printf("Error allocating memory!");
        return 1;
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("Enter the name of movie #%d: ", i+1);
        scanf("%s", movies[i].title);
        printf("Enter your rating for %s (out of 10): ", movies[i].title);
        scanf("%d", &movies[i].rating);
        printf("\n");
    }
    printf("Here are your ratings:\n");
    for (i = 0; i < n; i++) {
        printf("%s - ", movies[i].title);
        for (j = 0; j < movies[i].rating; j++)
            printf("*");
        printf("\n");
    }
    free(movies);
    return 0;
}