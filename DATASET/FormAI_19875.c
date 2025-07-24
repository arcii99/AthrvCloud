//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Ken Thompson
#include <stdio.h>

// C Movie Rating System
struct Movie {
    char title[50];
    char director[50];
    int year;
    double rating;
};

int main() {
    int num_movies;
    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);
    
    struct Movie movies[num_movies];
    
    for(int i = 0; i < num_movies; i++) {
        printf("\nMovie %d\n", i+1);
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Director: ");
        scanf("%s", movies[i].director);
        printf("Year: ");
        scanf("%d", &movies[i].year);
        printf("Rating (out of 10): ");
        scanf("%lf", &movies[i].rating);
    }
    
    // Display Movies Sorted by Rating
    for(double i = 10.0; i >= 0.5; i -= 0.5) {
        printf("\nMovies with a rating of %.1lf:\n", i);
        for(int j = 0; j < num_movies; j++) {
            if(movies[j].rating == i) {
                printf("%d. %s (%d) - Directed By: %s\n", j+1, movies[j].title, movies[j].year, movies[j].director);
            }
        }
    }
    
    return 0;
}