//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Ken Thompson
#include <stdio.h>

// Function to display the movie rating
void display_rating(char movie_title[], int rating) {
    printf("%s has a rating of %d\n", movie_title, rating);
}

int main() {
    // Declare variables
    char movie_title[30];
    int rating;

    // Get user input for movie title and rating
    printf("Enter the movie title: ");
    scanf("%s", movie_title);
    printf("Enter the movie rating (out of 10): ");
    scanf("%d", &rating);

    // Display the movie rating
    display_rating(movie_title, rating);

    // Set the movie rating label based on the rating value
    char rating_label[10];
    if (rating >= 8) {
        sprintf(rating_label, "Excellent");
    } else if (rating >= 6) {
        sprintf(rating_label, "Good");
    } else if (rating >= 4) {
        sprintf(rating_label, "Average");
    } else {
        sprintf(rating_label, "Poor");
    }

    // Display the movie rating label
    printf("This movie is rated as %s\n", rating_label);

    return 0;
}