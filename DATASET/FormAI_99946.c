//FormAI DATASET v1.0 Category: Movie Rating System ; Style: careful
#include <stdio.h>

int main() {
    int rating;

    printf("Welcome to our unique Movie Rating System!\n");
    printf("Please rate the movie on a scale of 1-5, where 1 is the worst and 5 is the best.\n");

    scanf("%d", &rating);

    if (rating < 1 || rating > 5) {
        printf("Invalid rating value. Please enter a value between 1 and 5.\n");
        return 1;
    }

    printf("Your rating for the movie is %d\n", rating);

    switch (rating) {
        case 1:
            printf("Unfortunately, this movie wasn't very good.\n");
            break;
        case 2:
            printf("This movie was okay, but nothing special.\n");
            break;
        case 3:
            printf("This movie was pretty good. Would recommend.\n");
            break;
        case 4:
            printf("This movie was great! Highly recommend!\n");
            break;
        case 5:
            printf("This movie was a masterpiece! You need to see this!\n");
            break;
        default:
            printf("Invalid rating value. Please enter a value between 1 and 5.\n");
            return 1;
    }

    return 0;
}