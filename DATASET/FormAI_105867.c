//FormAI DATASET v1.0 Category: Movie Rating System ; Style: accurate
#include <stdio.h>

int main() {
    int rating;
    printf("Welcome to the Unique C Movie Rating System!\n");
    printf("Please rate the last movie you watched on a scale of 1 to 10: ");
    scanf("%d", &rating);
    if (rating < 1 || rating > 10) {
        printf("Invalid rating! Please enter a number between 1 and 10.\n");
        return 0;
    }
    printf("You rated the movie a %d out of 10.\n", rating);
    printf("Here is our analysis of your rating:\n");
    switch (rating) {
        case 1:
        case 2:
            printf("Ouch! That movie must have been really bad.\n");
            break;
        case 3:
        case 4:
            printf("Hmm, sounds like that movie was below average.\n");
            break;
        case 5:
            printf("Sounds like an average movie.\n");
            break;
        case 6:
        case 7:
            printf("Not bad, sounds like that movie was pretty good.\n");
            break;
        case 8:
        case 9:
            printf("Wow! That movie must have been really great.\n");
            break;
        case 10:
            printf("Perfect score, that movie must be a masterpiece!\n");
            break;
        default:
            break;
    }
    return 0;
}