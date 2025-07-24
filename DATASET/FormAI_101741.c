//FormAI DATASET v1.0 Category: Movie Rating System ; Style: statistical
#include <stdio.h>

int main() {
    int ratings[5][10] = {{8, 6, 7, 5, 8, 10, 9, 4, 7, 6},
                          {10, 9, 6, 8, 7, 8, 6, 8, 7, 5},
                          {7, 8, 6, 5, 8, 9, 5, 7, 8, 6},
                          {9, 6, 7, 8, 7, 6, 8, 9, 7, 5},
                          {8, 7, 9, 10, 7, 6, 8, 7, 9, 6}};
    float avgRatings[5];
    int i,j;

    // Calculate average rating for each movie
    for(i = 0; i < 5; i++) {
        float sum = 0;
        for(j = 0; j < 10; j++) {
            sum += ratings[i][j];
        }
        avgRatings[i] = sum / 10.0;
    }

    //Print Average Ratings for each movie
    printf("Movie\t\t\t\t\tRatings\n");
    printf("--------------------------------------------------------\n");
    for(i = 0; i < 5; i++) {
        printf("Movie %d:\t\t\t\t%.2f\n", (i+1), avgRatings[i]);
    }

    //Calculate overall average rating
    float overallAvgRating = 0;
    for(i = 0; i < 5; i++) {
        overallAvgRating += avgRatings[i];
    }
    overallAvgRating /= 5.0;

    //Print the overall rating 
    printf("\nOverall Movie Rating: %.2f\n", overallAvgRating);
    return 0;
}