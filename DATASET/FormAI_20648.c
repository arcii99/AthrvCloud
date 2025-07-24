//FormAI DATASET v1.0 Category: Movie Rating System ; Style: all-encompassing
#include <stdio.h>

int main() {
    // Initialize variables
    int numMovies = 0;
    float totalRatings = 0;
    float averageRating = 0;
    char movieTitle[50];
    float movieRating = 0;
    
    // Get number of movies from user
    printf("How many movies would you like to rate? ");
    scanf("%d", &numMovies);
    
    // Get movie ratings from user and calculate average
    for (int i = 0; i < numMovies; i++) {
        printf("Enter the title of movie %d: ", i+1);
        scanf("%s", &movieTitle);
        printf("Enter your rating (out of 10) for %s: ", movieTitle);
        scanf("%f", &movieRating);
        
        while (movieRating < 0 || movieRating > 10) {
            printf("Invalid rating, please enter a rating between 0 and 10: ");
            scanf("%f", &movieRating);
        }
        
        totalRatings += movieRating;
    }
    
    averageRating = totalRatings / numMovies;
    
    // Display rating and recommendation
    printf("\nThe average rating for the %d movies is %.2f out of 10.", numMovies, averageRating);
    
    if (averageRating >= 8) {
        printf(" We highly recommend watching these movies!");
    } else if (averageRating >= 5) {
        printf(" These movies are worth a watch!");
    } else {
        printf(" These movies may not be worth your time.");
    }
    
    // End program
    return 0;
}