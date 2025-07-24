//FormAI DATASET v1.0 Category: Movie Rating System ; Style: brave
#include <stdio.h>
#include <stdlib.h>

/* C Movie Rating System */

int main()
{
    int userRating = 0, totalRating = 0, count = 0;
    float avgRating = 0;

    printf("Welcome to the C Movie Rating System!\n\n");

    do {
        printf("Please rate the movie (1-10, or 0 to exit): ");
        scanf("%d", &userRating);

        if (userRating > 0 && userRating < 11) {
            totalRating += userRating;
            count++;
            avgRating = (float)totalRating / count;
            printf("Thank you for rating the movie!\n\n");
        } else if (userRating == 0) {
            printf("Thank you for using the C Movie Rating System!\n\n");
        } else {
            printf("Invalid rating, please try again.\n\n");
        }
    } while (userRating != 0);

    printf("Total ratings received: %d\n", count);
    printf("Average rating: %.2f\n", avgRating);

    // Adding bonus features

    if (avgRating > 9) {
        printf("This movie is a masterpiece of cinematography!\n");
    } else if (avgRating > 7) {
        printf("This movie is definitely worth watching!\n");
    } else if (avgRating > 5) {
        printf("This movie is okay, but not a must-watch.\n");
    } else {
        printf("This movie is not really worth your time.\n");
    }

    return 0;
}