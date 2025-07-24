//FormAI DATASET v1.0 Category: Movie Rating System ; Style: cheerful
#include <stdio.h>

int main() {
    int rating;
    printf("Welcome to the Unique C Movie Rating System!\n");
    printf("Please enter your rating for the movie (from 1 to 10): ");
    scanf("%d", &rating);
    printf("\n");
    
    if (rating > 10 || rating < 1) {
        printf("Oops, that's an invalid rating. Please enter a rating between 1 and 10.\n");
    } else if (rating >= 8) {
        printf("Wow, you really loved the movie! We're so glad you enjoyed it.\n");
    } else if (rating >= 5) {
        printf("Looks like you thought it was an okay movie. Thanks for checking it out!\n");
    } else {
        printf("Sorry to hear you didn't enjoy the movie. We hope you'll give us another chance in the future!\n");
    }

    printf("\nThanks for using our rating system. We appreciate your feedback!\n");
    return 0;
}