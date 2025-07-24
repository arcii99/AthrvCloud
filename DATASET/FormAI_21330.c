//FormAI DATASET v1.0 Category: Movie Rating System ; Style: portable
#include <stdio.h>

int main() {

    char movieName[50];
    int userRating;
    int totalRating = 0;
    int numRatings = 0;
    float averageRating;

    printf("Welcome to the C Movie Rating System!\n");
    printf("Please enter the name of the movie you would like to rate: ");
    scanf("%s", movieName);

    while (1) {

        printf("Please enter your rating for %s (0-10): ", movieName);
        scanf("%d", &userRating);

        if (userRating >= 0 && userRating <= 10) {
            totalRating += userRating;
            numRatings++;
            averageRating = (float) totalRating / numRatings;
            printf("Thank you for your rating!\n");
            printf("The current average rating for %s is: %.2f\n", movieName, averageRating);
        }
        else {
            printf("Invalid rating input. Please enter a number between 0-10.\n");
        }

        char continueRating;
        printf("Would you like to continue rating %s? (y/n): ", movieName);
        scanf(" %c", &continueRating);

        if (continueRating == 'n' || continueRating == 'N') {
            break;
        }

    }

    printf("\nThe final average rating for %s is: %.2f\n", movieName, averageRating);
    printf("Thank you for using the C Movie Rating System!");

    return 0;
}