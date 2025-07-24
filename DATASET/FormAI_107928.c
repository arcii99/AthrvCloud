//FormAI DATASET v1.0 Category: Movie Rating System ; Style: introspective
#include <stdio.h>

// Declare a struct to hold movie information
struct Movie {
    char title[50];
    int year;
    float rating;
};

int main() {
    int num_movies;
    printf("How many movies would you like to rate? ");
    scanf("%d", &num_movies);

    // Create an array of movie structs with size equal to num_movies
    struct Movie movies[num_movies];
    
    // Loop through each movie and get input from user for title, year, and rating
    for (int i = 0; i < num_movies; i++) {
        printf("Enter movie title: ");
        scanf("%s", movies[i].title);
        
        printf("Enter year released (yyyy): ");
        scanf("%d", &movies[i].year);
        
        printf("Enter movie rating (out of 10): ");
        scanf("%f", &movies[i].rating);
    }
    
    printf("\n");

    //Loop through each movie and print out their title, year of release, and rating
    for (int i = 0; i < num_movies; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Year released: %d\n", movies[i].year);
        printf("Rating: %.1f/10\n\n", movies[i].rating);
    }

    return 0;
}