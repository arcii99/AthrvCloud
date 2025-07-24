//FormAI DATASET v1.0 Category: Movie Rating System ; Style: systematic
#include <stdio.h>

// Define constants
#define MIN_RATING 1
#define MAX_RATING 10
#define NUM_MOVIES 5

// Initialize an array of movie titles
char movieTitles[NUM_MOVIES][50] = {"The Godfather", "The Shawshank Redemption", "The Dark Knight", "Pulp Fiction", "The Matrix"};

// Initialize an array of movie ratings
int movieRatings[NUM_MOVIES];

// Function to get user input for a movie rating
int getMovieRating(char movieTitle[]) {
    int rating;
    printf("How would you rate the movie %s (1-10)? ", movieTitle);
    scanf("%d", &rating);
    while (rating < MIN_RATING || rating > MAX_RATING) {
        printf("Invalid rating. Please enter a rating between %d and %d: ", MIN_RATING, MAX_RATING);
        scanf("%d", &rating);
    }
    return rating;
}

int main() {
    // Get user input for each movie rating
    for (int i = 0; i < NUM_MOVIES; i++) {
        movieRatings[i] = getMovieRating(movieTitles[i]);
    }
    
    // Print out the movie ratings
    printf("\nMovie Ratings:\n");
    for (int i = 0; i < NUM_MOVIES; i++) {
        printf("%s: %d\n", movieTitles[i], movieRatings[i]);
    }
    
    return 0;
}