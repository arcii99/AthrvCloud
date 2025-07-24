//FormAI DATASET v1.0 Category: Movie Rating System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int rating;

    printf("Welcome to the C Movie Rating System!\n\n");
    printf("Please rate the movie you just watched on a scale of 1 to 10:\n");
    scanf("%d", &rating);

    if (rating >= 1 && rating <= 10) {
        printf("\nYour rating is: %d/10", rating);

        if (rating >= 9) {
            printf("\nWow, you really enjoyed the movie! We're glad you liked it.\n");
        } else if (rating >= 7) {
            printf("\nNot bad! We're happy to hear you enjoyed the movie.\n");
        } else if (rating >= 5) {
            printf("\nIt was just OK, huh? We'll have to try harder next time!\n");
        } else {
            printf("\nSorry to hear that you didn't enjoy the movie. We'll do better next time.\n");
        }
    } else {
        printf("\nInvalid rating. Please enter a number between 1 and 10.\n");
        exit(1);
    }

    return 0;
}