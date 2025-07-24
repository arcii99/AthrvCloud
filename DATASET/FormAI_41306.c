//FormAI DATASET v1.0 Category: Movie Rating System ; Style: light-weight
#include <stdio.h>

int main() {
    int rating;

    printf("Welcome to the Unique Movie Rating System\n");
    printf("Please rate the movie you watched on a scale of 1 to 5:\n");
    scanf("%d", &rating);

    switch(rating) {
        case 1:
            printf("Ouch! That was a terrible movie.\n");
            break;

        case 2:
            printf("Hmm... could have been better.\n");
            break;

        case 3:
            printf("It was okay, not bad at all.\n");
            break;

        case 4:
            printf("Great! I really enjoyed that movie.\n");
            break;

        case 5:
            printf("Wow! That was an amazing movie.\n");
            break;

        default:
            printf("Invalid rating. Please enter a number between 1 and 5.\n");
    }

    return 0;
}