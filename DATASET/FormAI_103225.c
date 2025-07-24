//FormAI DATASET v1.0 Category: Movie Rating System ; Style: post-apocalyptic
#include <stdio.h>

int main() {
    int rating;
    printf("Please enter your movie rating (1-10): ");
    scanf("%d", &rating);

    if (rating == 10) {
        printf("Wow, you have great taste in movies!\n");
    } else if (rating >= 8) {
        printf("That's a really good rating! You must have enjoyed the movie.\n");
    } else if (rating >= 5) {
        printf("Your rating is average. The movie may have been decent.\n");
    } else if (rating >= 3) {
        printf("Rating this movie that low is a crime! Did you really dislike it that much?\n");
    } else {
        printf("This movie must have been terrible if you rated it that low...\n");
    }

    return 0;
}