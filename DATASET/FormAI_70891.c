//FormAI DATASET v1.0 Category: Movie Rating System ; Style: accurate
#include <stdio.h>

int main() {
    int rating;

    // welcome message
    printf("Welcome to our Movie Rating System!\n");

    // prompt for user input
    printf("Please rate the movie (1-5): ");
    scanf("%d", &rating);

    // perform validation on user input
    while (rating < 1 || rating > 5) {
        printf("Invalid rating entered. Please enter a rating between 1 and 5: ");
        scanf("%d", &rating);
    }

    // display appropriate message based on rating
    switch(rating) {
        case 1:
            printf("We're sorry to hear you didn't enjoy the movie.\n");
            break;
        case 2:
            printf("We'll do better next time.\n");
            break;
        case 3:
            printf("Glad to hear you thought the movie was okay.\n");
            break;
        case 4:
            printf("Thanks for the positive feedback!\n");
            break;
        case 5:
            printf("We're thrilled to hear you loved the movie!\n");
            break;
    }

    return 0;
}