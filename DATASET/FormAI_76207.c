//FormAI DATASET v1.0 Category: Movie Rating System ; Style: lively
#include <stdio.h>

// initialize rating variables for each category
int plot_rating = 0;
int acting_rating = 0;
int cinematography_rating = 0;
int soundtrack_rating = 0;

int main() {
    // welcome message
    printf("Welcome to the C Movie Rating System!\n");

    // prompt user to enter ratings for each category
    printf("Please rate the plot on a scale of 1-10: ");
    scanf("%d", &plot_rating);

    printf("Please rate the acting on a scale of 1-10: ");
    scanf("%d", &acting_rating);

    printf("Please rate the cinematography on a scale of 1-10: ");
    scanf("%d", &cinematography_rating);

    printf("Please rate the soundtrack on a scale of 1-10: ");
    scanf("%d", &soundtrack_rating);

    // calculate total rating and percentage
    int total_rating = plot_rating + acting_rating + cinematography_rating + soundtrack_rating;
    double percentage = ((double) total_rating / 40) * 100;

    // print out results
    printf("\nThank you for rating the movie!\n");
    printf("Plot: %d/10\n", plot_rating);
    printf("Acting: %d/10\n", acting_rating);
    printf("Cinematography: %d/10\n", cinematography_rating);
    printf("Soundtrack: %d/10\n", soundtrack_rating);
    printf("Total Rating: %d/40\n", total_rating);
    printf("Percentage: %.2f%%\n", percentage);

    // give recommendation based on total rating
    if (total_rating >= 35) {
        printf("Wow! You really loved this movie. Definitely go see it if you haven't already!\n");
    } else if (total_rating >= 25) {
        printf("You enjoyed this movie but maybe it wasn't your favorite. Still worth a watch!\n");
    } else {
        printf("Hmm, it sounds like this movie wasn't really your cup of tea. Perhaps try a different genre next time!\n");
    }

    return 0;
}