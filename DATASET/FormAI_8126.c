//FormAI DATASET v1.0 Category: Movie Rating System ; Style: peaceful
#include <stdio.h>

// Function to calculate the movie rating
float calculateRating(float imdbScore, float metaScore, float audienceScore) {

    // Calculating the weighted average of the scores
    float rating = (imdbScore * 0.4) + (metaScore * 0.3) + (audienceScore * 0.3);

    return rating;
}

int main() {

    // Taking input from user
    float imdbScore, metaScore, audienceScore;

    printf("Enter the IMDb score: ");
    scanf("%f", &imdbScore);

    printf("Enter the Metacritic score: ");
    scanf("%f", &metaScore);

    printf("Enter the audience score: ");
    scanf("%f", &audienceScore);

    // Calculating the movie rating
    float rating = calculateRating(imdbScore, metaScore, audienceScore);

    printf("\n");

    // Displaying the final rating
    if(rating >= 8.5) {
        printf("The movie rating is: Excellent\n");
    }
    else if(rating >= 7) {
        printf("The movie rating is: Good\n");
    }
    else if(rating >= 5.5) {
        printf("The movie rating is: Average\n");
    }
    else if(rating >= 4) {
        printf("The movie rating is: Below Average\n");
    }
    else {
        printf("The movie rating is: Poor\n");
    }

    return 0;
}