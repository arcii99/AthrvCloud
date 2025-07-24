//FormAI DATASET v1.0 Category: Movie Rating System ; Style: excited
#include <stdio.h>

int main() {

    int rating;
    printf("Welcome to the C Movie Rating System!\n");

    printf("Please enter your movie rating (out of 10): ");
    scanf("%d", &rating);

    if (rating >= 9) {
        printf("Wow! You really enjoyed the movie!\n");
    } else if (rating >= 7) {
        printf("Great! Looks like it was a good movie!\n");
    } else if (rating >= 5) {
        printf("Looks like it was an okay movie.\n");
    } else if (rating >= 3) {
        printf("That doesn't sound too good...\n");
    } else {
        printf("Yikes, that movie was a complete disaster!\n");
    }

    return 0;
}