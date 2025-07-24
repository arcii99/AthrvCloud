//FormAI DATASET v1.0 Category: Movie Rating System ; Style: relaxed
#include <stdio.h>

int main() {
    int rating;
    printf("Welcome to the Unique C Movie Rating System\n");
    printf("Please rate the movie you just watched out of 10: ");
    scanf("%d", &rating);

    if(rating <= 0 || rating >= 11) {
        printf("Invalid rating! Please rate the movie out of 10\n");
    }
    
    else if(rating >= 1 && rating <= 3) {
        printf("Oh no! You didn't like the movie\n");
    }

    else if(rating >= 4 && rating <= 6) {
        printf("Hmm! Looks like you thought it was an average movie\n");
    }
    
    else if(rating >= 7 && rating <= 9) {
        printf("Great! You really enjoyed the movie\n");
    }

    else if(rating == 10) {
        printf("Wow! A perfect 10, that's awesome!\n");
    }
    
    return 0;
}