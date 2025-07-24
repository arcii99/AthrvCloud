//FormAI DATASET v1.0 Category: Movie Rating System ; Style: thoughtful
#include <stdio.h>

int main() {
    int rating;

    printf("Welcome to the Unique C Movie Rating System!\n");
    printf("Please enter your rating from 1-10: ");
    scanf("%d", &rating);

    if (rating >= 1 && rating <= 3) {
        printf("Sorry, you rated the movie as Poor.\n");
    }
    else if (rating >= 4 && rating <= 6) {
        printf("The movie was average.\n");
    }
    else if (rating >= 7 && rating <= 9) {
        printf("You thought the movie was great!\n");
    }
    else if (rating == 10) {
        printf("You gave the movie a perfect 10!\n");
    }
    else {
        printf("Invalid rating entered.\n");
        return 1;
    }

    return 0;
}