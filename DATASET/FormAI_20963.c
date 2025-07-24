//FormAI DATASET v1.0 Category: Movie Rating System ; Style: inquisitive
#include <stdio.h>

int main() {
    int rating;
    char movie[50], answer;

    printf("What movie would you like to rate?\n");
    scanf("%s", movie);

    printf("How would you rate %s on a scale of 1 to 10?\n", movie);
    scanf("%d", &rating);

    if (rating >= 1 && rating <= 10) {
        printf("Thank you for rating %s a %d!\n", movie, rating);
    } else if (rating == 0) {
        printf("You didn't rate %s. Would you like to try again? (y/n)\n", movie);
        scanf(" %c", &answer);

        if (answer == 'y') {
            printf("How would you rate %s on a scale of 1 to 10?\n", movie);
            scanf("%d", &rating);
            
            if (rating >= 1 && rating <= 10) {
                printf("Thank you for rating %s a %d!\n", movie, rating);
            } else {
                printf("Sorry, your rating is invalid.\n");
            }
        } else {
            printf("Thank you for your time!\n");
        }
    } else {
        printf("Sorry, your rating is invalid.\n");
    }

    return 0;
}