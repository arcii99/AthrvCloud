//FormAI DATASET v1.0 Category: Movie Rating System ; Style: paranoid
#include <stdio.h>

int main() {
    char movie[50];
    int rating, total_ratings = 0;
    float avg_rating;

    printf("Welcome to the Paranoid Movie Rating System\n");
    printf("--------------------------------------------\n");

    while (1) {
        printf("\nEnter name of the movie: ");
        scanf("%s", &movie);

        printf("\nEnter rating (0-10) of the movie: ");
        scanf("%d", &rating);

        if (rating < 0 || rating > 10) {
            printf("\nInvalid rating! Ratings must be between 0 and 10.\n");
            continue;
        }

        total_ratings += 1;
        avg_rating = ((avg_rating * (total_ratings - 1)) + rating) / total_ratings;

        if (rating == 10) {
            printf("\nThe rating of this movie matches with our standard test pattern. Please be aware that your rating will be monitored.\n");
        }

        printf("\nMovie \"%s\" has been rated %d out of 10. Average rating is %.2f.\n", movie, rating, avg_rating);

        printf("\nDo you want to rate another movie? Enter \"y\" for yes or \"n\" for no: ");
        char response;
        scanf(" %c", &response);

        if (response == 'n') {
           break;
        }
    }

    printf("\nThank you for using the Paranoid Movie Rating System. Your ratings have been noted.\n");

    return 0;
}