//FormAI DATASET v1.0 Category: Movie Rating System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MIN_RATING 0
#define MAX_RATING 10

int main() {
    float rating = -1;
    while (rating < MIN_RATING || rating > MAX_RATING) {
        printf("Please enter a rating between %d and %d: ", MIN_RATING, MAX_RATING);
        scanf("%f", &rating);

        if (rating < MIN_RATING || rating > MAX_RATING) {
            printf("Invalid rating.\n");
        }
    }

    if (rating < 5) {
        printf("This movie is not recommended.\n");
    } else if (rating >= 5 && rating < 7) {
        printf("This movie is average.\n");
    } else if (rating >= 7 && rating < 9) {
        printf("This movie is recommended.\n");
    } else {
        printf("This movie is outstanding!\n");
    }

    return 0;
}