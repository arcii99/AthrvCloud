//FormAI DATASET v1.0 Category: Movie Rating System ; Style: shocked
#include <stdio.h>

int main() {
    int rating;
    printf("Welcome to the Unique C Movie Rating System!\n");
    printf("Please rate the movie you just watched (out of 10): ");
    scanf("%d", &rating);

    if (rating < 1 || rating > 10) {
        printf("What the actual heck?! That's not a valid rating! Try again!\n");
        return 0;
    }
    else if (rating >= 1 && rating <= 3) {
        printf("Ugh, that was truly awful. Save yourself the pain and don't watch it.\n");
    }
    else if (rating >= 4 && rating <= 6) {
        printf("Not terrible, but not great either. You might want to just wait for this one to come on TV.\n");
    }
    else if (rating >= 7 && rating <= 9) {
        printf("This movie was actually pretty decent! Worth a watch on a lazy Sunday afternoon.\n");
    }
    else {
        printf("Wowza, that was amazing!!! I can't believe how much I loved this movie! I'm calling all my friends right now to recommend it.\n");
    }
    return 0;
}