//FormAI DATASET v1.0 Category: Movie Rating System ; Style: shocked
#include <stdio.h>

int main() {
    int rating;
    printf("Welcome to the unique C Movie Rating System!\n");
    printf("Please rate the movie on a scale of 1-10:\n");
    scanf("%d", &rating);
    
    if (rating <= 5) {
        printf("Oh my gosh, this is shocking! This movie is trash.\n");
    } else if(rating <= 7) {
        printf("Hmm, it seems like this movie is just okay.\n");
    } else if(rating <= 9) {
        printf("Wow, this movie is amazing! You have great taste.\n");
    } else {
        printf("Unbelievable, this movie is one of the best ever made!\n");
    }
    
    printf("Thank you for using the C Movie Rating System. Goodbye!\n");
    
    return 0;
}