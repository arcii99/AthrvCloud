//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Alan Touring
#include <stdio.h>

int main() {
    int rating;

    printf("Welcome to the Unique C Movie Rating System!\n");
    printf("Please rate the movie on a scale of 1 to 10: ");
    scanf("%d", &rating);

    if (rating < 1 || rating > 10) {
        printf("Invalid rating! Please rate the movie on a scale of 1 to 10.\n");
        return 1;
    }

    printf("Thank you for your rating of %d!\n", rating);

    // Interpret the rating
    switch (rating) {
        case 1:
            printf("This movie was terrible!\n");
            break;
        case 2:
            printf("This movie was very bad.\n");
            break;
        case 3:
            printf("This movie was bad.\n");
            break;
        case 4:
            printf("This movie was below average.\n");
            break;
        case 5:
            printf("This movie was average.\n");
            break;
        case 6:
            printf("This movie was above average.\n");
            break;
        case 7:
            printf("This movie was good.\n");
            break;
        case 8:
            printf("This movie was very good.\n");
            break;
        case 9:
            printf("This movie was great!\n");
            break;
        case 10:
            printf("This movie was excellent!\n");
            break;
        default:
            printf("Something went wrong. Please try again.\n");
            break;
    }

    return 0;
}