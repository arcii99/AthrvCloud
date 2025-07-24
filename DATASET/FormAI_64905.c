//FormAI DATASET v1.0 Category: Movie Rating System ; Style: authentic
#include <stdio.h>

// function to calculate the movie rating based on user inputs
int calculate_movie_rating(int genre, int duration, int cast, int story, int direction) {
    int total_score = genre + duration + cast + story + direction;
    int rating;
    // assigning the rating based on the total score
    if (total_score >= 40) {
        rating = 10;
    } else if (total_score >= 35 && total_score < 40) {
        rating = 9;
    } else if (total_score >= 30 && total_score < 35) {
        rating = 8;
    } else if (total_score >= 25 && total_score < 30) {
        rating = 7;
    } else if (total_score >= 20 && total_score < 25) {
        rating = 6;
    } else if (total_score >= 15 && total_score < 20) {
        rating = 5;
    } else if (total_score >= 10 && total_score < 15) {
        rating = 4;
    } else {
        rating = 3;
    }
    return rating;
}

// main function to get user inputs and invoke the rating calculation function
int main() {
    int genre, duration, cast, story, direction;
    printf("Enter the genre score out of 10: ");
    scanf("%d", &genre);
    printf("Enter the duration score out of 10: ");
    scanf("%d", &duration);
    printf("Enter the cast score out of 10: ");
    scanf("%d", &cast);
    printf("Enter the story score out of 10: ");
    scanf("%d", &story);
    printf("Enter the direction score out of 10: ");
    scanf("%d", &direction);
    int rating = calculate_movie_rating(genre, duration, cast, story, direction);
    printf("The movie rating is: %d\n", rating);
    return 0;
}