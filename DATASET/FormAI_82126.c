//FormAI DATASET v1.0 Category: Movie Rating System ; Style: lively
#include <stdio.h>

// Function to display the message based on the rating
void displayMessage(int rating) {
    switch (rating) {
        case 1: printf("I am sorry but that movie was terrible.\n");
                break;
        case 2: printf("That movie was not great but it had its moments.\n");
                break;
        case 3: printf("It was a decent movie, worth watching.\n");
                break;
        case 4: printf("I loved that movie, it was amazing!\n");
                break;
        case 5: printf("That was the best movie I have ever seen!\n");
                break;
        default: printf("Invalid rating.\n");
    }
}

int main() {
    int rating;

    printf("Welcome to the Unique C Movie Rating System!\n");

    do {
        // Prompt the user to input a movie rating
        printf("Please input the movie rating (1-5): ");
        scanf("%d", &rating);

        // Display message based on the rating
        displayMessage(rating);

        // Check if the user wants to rate another movie
        printf("Do you want to rate another movie? (Y/N) ");
        char response;
        scanf("%s", &response);
        if (response == 'N' || response == 'n') {
            break;
        }
    } while (1);

    printf("Thank you for using the Unique C Movie Rating System!\n");

    return 0;
}