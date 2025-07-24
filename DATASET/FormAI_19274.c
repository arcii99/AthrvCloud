//FormAI DATASET v1.0 Category: Movie Rating System ; Style: recursive
#include<stdio.h>

/* Recursive function to rate movies */
int rateMovie(int movieChoice) {
    int rating;
    printf("Rate movie %d out of 10: ", movieChoice);
    scanf("%d", &rating);
    if(rating < 0 || rating > 10) { 
        printf("Invalid rating. Please enter a rating between 0 and 10.\n");
        return rateMovie(movieChoice); /* Recursive call to rateMovie() */
    }
    printf("Thank you for rating movie %d.\n", movieChoice);
    return rating;
}

int main() {
    int movie1Rating = rateMovie(1);
    int movie2Rating = rateMovie(2);
    int totalRating = movie1Rating + movie2Rating;
    printf("Combined rating for both movies is %d/20.\n", totalRating);
    return 0;
}