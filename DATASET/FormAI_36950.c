//FormAI DATASET v1.0 Category: Movie Rating System ; Style: minimalist
#include <stdio.h>

int main()
{
    int user_rating, total_rating = 0, count = 0;
    float average_rating;

    printf("Welcome to the C Movie Rating System!\n\n");

    printf("Please rate the movie out of 10. Enter -1 to exit.\n");

    do {
        printf("Enter rating: ");
        scanf("%d", &user_rating);

        if (user_rating == -1) {
            break;
        }

        total_rating += user_rating;
        count++;

    } while (user_rating != -1);

    if (count == 0) {
        printf("\nNo ratings given. Exiting...\n");
        return 0;
    }

    average_rating = total_rating / (float)count;

    printf("\nThank you for rating!\n");
    printf("Total ratings: %d\n", count);
    printf("Average rating: %.1f/10\n", average_rating);

    return 0;
}