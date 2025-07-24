//FormAI DATASET v1.0 Category: Movie Rating System ; Style: minimalist
#include <stdio.h>

// function to get user's rating input
int getUserRating() {
    int score;
    printf("Enter your rating (1-10): ");
    scanf("%d", &score);
    return score;
}

// function to determine the movie's rating
char* getMovieRating(int score) {
    if (score < 1 || score > 10) { // input validation
        return "invalid";
    } else if (score >= 1 && score <= 3) {
        return "bad";
    } else if (score >= 4 && score <= 7) {
        return "average";
    } else {
        return "good";
    }
}

int main() {
    int userRating = getUserRating();
    char* movieRating = getMovieRating(userRating);
    printf("Your rating: %d\nMovie rating: %s\n", userRating, movieRating);
    return 0;
}