//FormAI DATASET v1.0 Category: Movie Rating System ; Style: complete
#include <stdio.h>

/* Declare function to get user's movie rating */
int get_rating() {
    int rating;
    printf("Please enter your rating (1-10): ");
    scanf("%d", &rating);
    while (rating < 1 || rating > 10) {
        printf("Invalid rating. Please enter a number between 1 and 10: ");
        scanf("%d", &rating);
    }
    return rating;
}

int main() {
    int rating = get_rating();

    /* Deciding the value of ratings */
    if (rating >= 9) {
        printf("Excellent! This movie is a must-watch.\n");
    } else if (rating >= 7) {
        printf("Good! This movie is definitely worth a watch.\n");
    } else if (rating >= 5) {
        printf("Okay. This movie may be worth checking out.\n");
    } else {
        printf("Not great. It might be best to skip this movie.\n");
    }

    return 0;
}