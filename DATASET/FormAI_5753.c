//FormAI DATASET v1.0 Category: Movie Rating System ; Style: minimalist
#include <stdio.h>

/* Define a struct for movie */
struct Movie {
    char title[50];
    int rating;
};

int main() {
    int num_movies;
    
    printf("How many movies would you like to rate? ");
    scanf("%d", &num_movies);
    
    /* Dynamically allocate memory for an array of Movie structs */
    struct Movie *movies = malloc(num_movies * sizeof(struct Movie));
    
    /* Get user input for movie titles and ratings */
    for (int i = 0; i < num_movies; i++) {
        printf("Enter the title of movie #%d: ", i+1);
        scanf(" %[^\n]s", movies[i].title);
        
        printf("Enter the rating of movie #%d (1-10): ", i+1);
        scanf("%d", &movies[i].rating);
        
        /* Error check user input */
        if (movies[i].rating < 1 || movies[i].rating > 10) {
            printf("Invalid rating. Please enter a number between 1 and 10.\n");
            i--; /* Decrement i to try again for this movie */
        }
    }
    
    /* Display movie ratings */
    printf("\nMovie Ratings:\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%s: %d/10\n", movies[i].title, movies[i].rating);
    }
    
    /* Free dynamically allocated memory */
    free(movies);
    
    return 0;
}