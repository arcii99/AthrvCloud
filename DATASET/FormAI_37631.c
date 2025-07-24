//FormAI DATASET v1.0 Category: Movie Rating System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rating;
    printf("Welcome to the Unique C Movie Rating System!\n");
    printf("Please rate the movie you recently watched out of 10: ");
    scanf("%d", &rating);

    if (rating < 0 || rating > 10) {
        printf("Invalid rating! Please rate the movie out of 10.\n");
        return 1; // return error code
    }

    printf("You rated the movie a %d out of 10.\n", rating);

    switch (rating) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            printf("Sorry, the movie did not meet your expectations.\n");
            break;

        case 5:
        case 6:
            printf("The movie was okay, but could have been better.\n");
            break;

        case 7:
        case 8:
            printf("The movie was good, and definitely worth watching!\n");
            break;

        default:
            printf("Wow! You really loved the movie, didn't you?\n");
            break;
    }

    return 0; // return success code
}