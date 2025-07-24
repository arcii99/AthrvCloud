//FormAI DATASET v1.0 Category: Movie Rating System ; Style: curious
#include <stdio.h>

int main() {

    int rating;

    printf("Welcome to the Curious Movie Rating System\n");
    printf("Please rate the movie you recently saw out of 10: ");
    scanf("%d", &rating);

    if (rating < 0 || rating > 10) {
        printf("Oops! Looks like you entered an invalid rating. Please rate the movie out of 10 only.\n");
    } else {
        printf("Thanks for rating the movie. Here's our curious analysis:\n");

        if (rating >= 0 && rating <= 4) {
            printf("Hmm, seems like you didn't like the movie at all. We suggest watching a different genre next time.\n");
        } else if (rating >= 5 && rating <= 7) {
            printf("Well, you somewhat liked the movie. We suggest trying out some director's cut versions next time.\n");
        } else {
            printf("Wow, you really enjoyed the movie! We suggest checking out some more movies from the same director.\n");
        }
    }

    printf("Thanks for using the Curious Movie Rating System!\n");

    return 0;
}