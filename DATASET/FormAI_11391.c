//FormAI DATASET v1.0 Category: Movie Rating System ; Style: curious
#include <stdio.h>

int main(){
    
    int movieRating;

    printf("Welcome to the C Movie Rating System!\n");
    printf("Please enter a rating for the movie you just watched, on a scale of 1-10: ");

    scanf("%d", &movieRating);

    if (movieRating < 1 || movieRating > 10){
        printf("Invalid rating. Please enter a number between 1 and 10.\n");
        return 0;
    }

    printf("Thank you for your rating of %d!\n", movieRating);

    if (movieRating == 10){
        printf("Wow! That's an incredible rating! You must have loved the movie.\n");
    }
    else if (movieRating >= 7){
        printf("Great rating! It sounds like you really enjoyed the film.\n");
    }
    else if (movieRating >= 5){
        printf("Not a bad rating, but it seems like you weren't too impressed with the movie.\n");
    }
    else{
        printf("Sorry to hear that you didn't enjoy the movie. Better luck next time!\n");
    }

    return 0;
}