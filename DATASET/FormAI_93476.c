//FormAI DATASET v1.0 Category: Movie Rating System ; Style: light-weight
#include <stdio.h>

// Function to calculate the movie rating
float getRating(int audienceScore, int criticsScore) {
    float rating = 0.0;
    
    if(audienceScore < 0 || audienceScore > 100 || criticsScore < 0 || criticsScore > 100) {
        // Error: Invalid score input
        printf("Invalid score input!\n");
    }
    else {
        // Calculate the average rating
        rating = (audienceScore + criticsScore) / 2.0;
        
        if(rating >= 0.0 && rating < 40.0) {
            printf("Rating: F\n");
        }
        else if(rating >= 40.0 && rating < 60.0) {
            printf("Rating: D\n");
        }
        else if(rating >= 60.0 && rating < 70.0) {
            printf("Rating: C\n");
        }
        else if(rating >= 70.0 && rating < 80.0) {
            printf("Rating: B\n");
        }
        else if(rating >= 80.0 && rating <= 100.0) {
            printf("Rating: A\n");
        }
    }
    
    return rating;
}

int main() {
    int audienceScore, criticsScore;
    
    printf("Enter the audience score (out of 100): ");
    scanf("%d", &audienceScore);
    
    printf("Enter the critics score (out of 100): ");
    scanf("%d", &criticsScore);
    
    float rating = getRating(audienceScore, criticsScore);
    printf("The movie rating is %.2f\n", rating);
    
    return 0;
}