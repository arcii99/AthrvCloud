//FormAI DATASET v1.0 Category: Movie Rating System ; Style: complete
#include <stdio.h>

// Function to get the user's input rating
int getRating() {
    int rating;
    printf("Please rate the movie on a scale from 1 to 10: ");
    scanf("%d", &rating);
    return rating;
}

// Function to display the movie rating based on the user's input
void displayRating(int rating) {
    printf("Your rating for the movie is: ");
    if (rating == 1) {
        printf("Terrible\n");
    } else if (rating == 2 || rating == 3) {
        printf("Poor\n");
    } else if (rating == 4 || rating == 5) {
        printf("Average\n");
    } else if (rating == 6 || rating == 7) {
        printf("Good\n");
    } else if (rating == 8 || rating == 9) {
        printf("Excellent\n");
    } else if (rating == 10) {
        printf("Outstanding\n");
    } else {
        printf("Invalid rating\n");
    }
}

int main() {
    int rating;

    // Get user's input rating
    rating = getRating();

    // Display the movie rating
    displayRating(rating);

    return 0;
}