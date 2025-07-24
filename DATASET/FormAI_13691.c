//FormAI DATASET v1.0 Category: Movie Rating System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rating;
    printf("Welcome to the Romantic Movie Rating System!\n");
    printf("Please rate the movie you watched on a scale of 1 to 10:\n");
    scanf("%d", &rating);
    if (rating >= 9) {
        printf("Wow! That's a high rating, this movie must be amazing!\n");
    } else if (rating >= 7) {
        printf("Sounds like a good movie! I'll have to check it out!\n");
    } else if (rating >= 5) {
        printf("Hmm, it sounds like an average movie. Thanks for letting me know!\n");
    } else {
        printf("Yikes, that's a low rating. Maybe I'll skip that one...\n");
    }
    return 0;
}