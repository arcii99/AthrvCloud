//FormAI DATASET v1.0 Category: Movie Rating System ; Style: grateful
#include <stdio.h>

// function to calculate the movie rating
int calculate_movie_rating(int critics_rating, int audience_rating) {
    int movie_rating = ((critics_rating + audience_rating) / 2);
    return movie_rating;
}

// function to display the movie rating
void display_movie_rating(int movie_rating) {
    if(movie_rating >= 9) {
        printf("Movie rating: A+\n");
    } else if(movie_rating >= 8) {
        printf("Movie rating: A\n");
    } else if(movie_rating >= 7) {
        printf("Movie rating: B\n");
    } else if(movie_rating >= 6) {
        printf("Movie rating: C\n");
    } else if(movie_rating >= 5) {
        printf("Movie rating: D\n");
    } else {
        printf("Movie rating: F\n");
    }
}

int main() {
    int critics_rating, audience_rating, movie_rating;
    printf("Enter the critics rating of the movie (out of 10):\n");
    scanf("%d", &critics_rating);
    printf("Enter the audience rating of the movie (out of 10):\n");
    scanf("%d", &audience_rating);
    movie_rating = calculate_movie_rating(critics_rating, audience_rating);
    display_movie_rating(movie_rating);
    return 0;
}