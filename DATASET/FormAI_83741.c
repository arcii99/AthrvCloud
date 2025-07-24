//FormAI DATASET v1.0 Category: Movie Rating System ; Style: excited
#include <stdio.h>

int main() {
    int rating;

    printf("Welcome to the C Movie Rating System!\n");
    printf("Please rate the movie on a scale of 1 to 10:\n");

    scanf("%d", &rating);

    printf("\n");

    if (rating >= 1 && rating <= 10) {
        printf("You have rated the movie a %d!\n", rating);
        printf("\n");

        if (rating >= 1 && rating <= 3) {
            printf("That's a terrible rating! Did you even watch the movie?\n");
        } else if (rating >= 4 && rating <= 6) {
            printf("That's an average rating. The movie must have been okay.\n");
        } else if (rating >= 7 && rating <= 9) {
            printf("That's a great rating! You must have really enjoyed the movie.\n");
        } else {
            printf("Wow! A perfect rating! You must have really loved the movie!\n");
        }
    } else {
        printf("Invalid rating! Please rate the movie on a scale of 1 to 10.\n");
    }

    return 0;
}