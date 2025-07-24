//FormAI DATASET v1.0 Category: Movie Rating System ; Style: inquisitive
#include <stdio.h>

// Function to get the movie rating from user
int getRating() {
    int rating;
    printf("Please rate the movie on scale of 1 to 10: ");
    scanf("%d", &rating);
    if (rating < 1) {
        rating = 1;
    } else if (rating > 10) {
        rating = 10;
    }
    return rating;
}

// Function to display the movie rating
void displayRating(int rating) {
    printf("The movie rating is %d\n", rating);
}

// Main function
int main() {
    int rating = getRating();
    displayRating(rating);

    char comment[100];
    printf("Do you have any comment about the movie (max 100 characters)? ");
    scanf("\n%[^\n]", comment);
    printf("Your comment: %s\n", comment);

    if (rating >= 8) {
        printf("This is an excellent movie!\n");
    } else if (rating >= 6) {
        printf("This is a good movie.\n");
    } else if (rating >= 4) {
        printf("This is an average movie.\n");
    } else if (rating >= 2) {
        printf("This is a bad movie.\n");
    } else {
        printf("This is a terrible movie!\n");
    }

    return 0;
}