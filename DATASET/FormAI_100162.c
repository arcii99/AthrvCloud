//FormAI DATASET v1.0 Category: Movie Rating System ; Style: romantic
#include <stdio.h>

int main() {
    int rating;
    printf("Welcome to the Romantic Movie Rating System!\n");
    printf("Please rate the movie on a scale of 1 to 10:\n");
    scanf("%d", &rating);
    printf("You have rated the movie %d out of 10.\n", rating);
    if (rating >= 8) {
        printf("Wow! You must have a heart made of gold. This movie is definitely a classic.\n");
    } else if (rating >= 6) {
        printf("Not bad! It seems like this movie has some potential.\n");
    } else {
        printf("Oh, dear. I'm sorry to hear that you didn't enjoy the movie.\n");
    }
    return 0;
}