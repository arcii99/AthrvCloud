//FormAI DATASET v1.0 Category: Movie Rating System ; Style: futuristic
#include <stdio.h>

//Function to calculate the movie rating
float calculateRating(float reviews, float duration) {
    float rating = reviews/duration;
    return rating;
}

int main() {

    //Movie Details
    char name[50] = "The Chronicles of AI";
    int duration = 137;
    int year = 2050;
    char director[50] = "RoboDirector90";

    //User Ratings
    float criticReviews = 50.0;
    float audienceReviews = 1000.0;

    //Calculate Movie Rating
    float movieRating = calculateRating((criticReviews+audienceReviews), duration);

    //Display Movie Details and Rating
    printf("Movie Name: %s\n", name);
    printf("Director: %s\n", director);
    printf("Year: %d\n", year);
    printf("Duration: %d minutes\n", duration);
    printf("Critic Reviews: %.0f\n", criticReviews);
    printf("Audience Reviews: %.0f\n", audienceReviews);
    printf("Movie Rating: %.2f\n", movieRating);

    //Movie Rating Classification
    if (movieRating >= 9.0) {
        printf("Movie Classification: Future Classic\n");
    } else if (movieRating >= 8.0 && movieRating < 9.0) {
        printf("Movie Classification: Masterpiece\n");
    } else if (movieRating >= 7.0 && movieRating < 8.0) {
        printf("Movie Classification: Must See\n");
    } else if (movieRating >= 6.0 && movieRating < 7.0) {
        printf("Movie Classification: Decent\n");
    } else {
        printf("Movie Classification: Mediocre\n");
    }

    return 0;
}