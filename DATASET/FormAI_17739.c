//FormAI DATASET v1.0 Category: Movie Rating System ; Style: configurable
#include <stdio.h>

// Rating System Configuration
#define MIN_RATING 1
#define MAX_RATING 10
#define DEFAULT_RATING 5

// Functions for Rating System
void getRating(int *rating) {
    printf("Enter movie rating (%d-%d): ", MIN_RATING, MAX_RATING);
    scanf("%d", rating);
    if (*rating < MIN_RATING || *rating > MAX_RATING) {
        printf("Invalid rating. Set to default value of %d.\n", DEFAULT_RATING);
        *rating = DEFAULT_RATING;
    }
}

void printRating(int rating) {
    printf("Movie rating: %d\n", rating);
}

int main() {
    int rating = DEFAULT_RATING;
    getRating(&rating);
    printRating(rating);
    return 0;
}