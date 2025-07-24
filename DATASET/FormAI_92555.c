//FormAI DATASET v1.0 Category: Movie Rating System ; Style: relaxed
#include <stdio.h>

int main() {
    int rating;
    printf("Welcome to the C Movie Rating System!\n");

    // Prompt user to select rating
    printf("Please select a rating between 1 and 5:\n");
    scanf("%d", &rating);

    // Validate user input
    if(rating < 1 || rating > 5) {
        printf("Invalid rating selected. Please try again.\n");
        return 0;
    }

    // Display rating and corresponding message
    switch(rating) {
        case 1:
            printf("We're sorry you didn't enjoy the movie.\n");
            break;
        case 2:
            printf("We're glad you found some enjoyment in the movie.\n");
            break;
        case 3:
            printf("Thank you for your neutral review of the movie.\n");
            break;
        case 4:
            printf("Thank you for your positive review of the movie!\n");
            break;
        case 5:
            printf("We're thrilled you loved the movie! Thanks for your great review.\n");
            break;
    }
    return 0;
}