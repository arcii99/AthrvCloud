//FormAI DATASET v1.0 Category: Movie Rating System ; Style: careful
#include<stdio.h>

int main(){

    printf("Welcome to the Unique C Movie Rating System!\n\n");

    // Declaring variables
    char movie[50];
    int rating;
    char choice;

    do {
        // Getting input from user
        printf("Enter the name of the movie: ");
        scanf("%s", &movie);
        printf("Enter the rating of the movie (out of 10): ");
        scanf("%d", &rating);

        // Rating system
        if (rating >= 8){
            printf("***** %s is an excellent movie! *****\n\n", movie);
        } else if (rating >= 6){
            printf("*** %s is a good movie! ***\n\n", movie);
        } else if (rating >= 4){
            printf("** %s is an average movie! **\n\n", movie);
        } else {
            printf("* %s is a below average movie! *\n\n", movie);
        }

        // Asking user if they want to rate another movie
        printf("Do you want to rate another movie? (y/n): ");
        scanf(" %c", &choice);

    } while(choice == 'y' || choice == 'Y');

    printf("\nGoodbye! Thank you for using the Unique C Movie Rating System.");

    return 0;
}