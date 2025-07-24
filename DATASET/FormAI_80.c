//FormAI DATASET v1.0 Category: Movie Rating System ; Style: beginner-friendly
#include <stdio.h>

int main() {
    int rating;

    printf("Welcome to the Unique C Movie Rating System!\n\n");
    printf("Please rate the movie you just watched from 1 to 10, with 10 being the best:\n");

    // get the rating from user
    scanf("%d", &rating);

    // evaluate the rating and give appropriate feedback
    if (rating >= 1 && rating <= 3) {
        printf("\nSorry, you didn't like the movie! We'll try to recommend a better one next time.\n");
    } else if (rating >= 4 && rating <= 6) {
        printf("\nThe movie was decent, you might like some of our other recommendations.\n");
    } else if (rating >= 7 && rating <= 9) {
        printf("\nGlad to hear you enjoyed the movie! We'll make sure to recommend similar ones in the future.\n");
    } else if (rating == 10) {
        printf("\nWow, you really loved the movie! We'll make sure to recommend similar ones in the future.\n");
    } else {
        printf("\nInvalid rating entered. Please enter a number from 1 to 10.\n");
    }

    return 0;
}