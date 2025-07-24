//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Alan Touring
#include <stdio.h>

// function to get user input for movie rating
float getRating() {
    float rating;
    printf("Please rate the movie on a scale of 1.0 to 10.0:\n");
    scanf("%f", &rating);
    return rating;
}

// function to display movie rating
void displayRating(float rating) {
    printf("The movie is rated %.1f out of 10.0.\n", rating);
    if (rating >= 8.0) {
        printf("Wow! That's a great score!\n");
    } else if (rating >= 6.0) {
        printf("Not bad, but could have been better.\n");
    } else {
        printf("Sorry to hear that. We will try to improve!\n");
    }
}

// main function to get user input and display movie rating
int main() {
    float rating = getRating();
    displayRating(rating);
    return 0;
}