//FormAI DATASET v1.0 Category: Movie Rating System ; Style: lively
#include <stdio.h>

int main() {
    int rating;

    printf("Welcome to our unique C Movie Rating System!\n");
    printf("Please rate the movie you watched from 1 to 5:\n");
    scanf("%d", &rating);

    switch (rating) {
        case 1:
            printf("Oh no! That movie was terrible!\n");
            break;
        case 2:
            printf("That movie was below average. Definitely not worth watching again.\n");
            break;
        case 3:
            printf("That movie was okay. It had some good parts, but could have been better.\n");
            break;
        case 4:
            printf("That was a pretty good movie! I would definitely watch it again.\n");
            break;
        case 5:
            printf("Wow, that movie was amazing! I'm already planning to watch it again soon.\n");
            break;
        default:
            printf("Invalid rating. Please rate the movie on a scale of 1 to 5.\n");
            break;
    }

    printf("Thank you for rating the movie. We hope to see you again soon!\n");

    return 0;
}