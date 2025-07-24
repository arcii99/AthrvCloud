//FormAI DATASET v1.0 Category: Movie Rating System ; Style: puzzling
#include <stdio.h>

int main() {
    int rating;
    printf("Welcome to our Movie Rating System!\nPlease rate the movie you watched between 1-10:\n");
    scanf("%d", &rating);
    if (rating >= 1 && rating <= 10) {
        printf("You rated the movie %d out of 10.\n", rating);
        if (rating == 10) {
            printf("Wow! That's a perfect score!\n");
        }
        else if (rating >= 8) {
            printf("Great rating! You must have really enjoyed the movie.\n");
        }
        else if (rating >= 5) {
            printf("That's a fairly average score. Did you find the movie enjoyable?\n");
        }
        else {
            printf("Oh no! It seems like you didn't enjoy the movie that much.\n");
        }
    }
    else {
        printf("Invalid rating. Please enter a rating between 1-10.\n");
    }
    return 0;
}