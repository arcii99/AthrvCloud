//FormAI DATASET v1.0 Category: Movie Rating System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main() {
    char movie_name[100];
    int rating;
    char another_movie;

    do {
        printf("Enter the movie name: ");
        scanf("%[^\n]%*c", movie_name);
        printf("Enter the rating for the movie (out of 10): ");
        scanf("%d", &rating);

        printf("\nThank you for rating the movie!\n\n");
        printf("Movie Name: %s\n", movie_name);
        printf("Rating: %d\n\n", rating);

        if (rating >= 8) {
            printf("Wow, that's a great rating!\n");
        } else if (rating >= 5) {
            printf("That's a decent rating.\n");
        } else {
            printf("Could have been better.\n");
        }

        printf("Do you want to rate another movie? (y/n) ");
        scanf(" %c", &another_movie);
    } while (another_movie == 'y' || another_movie == 'Y');

    printf("\nThank you for using the C Movie Rating System!\n");

    return 0;
}