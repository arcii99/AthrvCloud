//FormAI DATASET v1.0 Category: Movie Rating System ; Style: systematic
#include <stdio.h>

// Function to display the rating system options
void displayOptions() {
    printf("Choose a rating:\n");
    printf("1 - Excellent\n");
    printf("2 - Good\n");
    printf("3 - Average\n");
    printf("4 - Poor\n");
}

int main() {
    int rating;

    // Display options and get user input
    displayOptions();
    scanf("%d", &rating);

    // Evaluate rating and display appropriate message
    switch (rating) {
        case 1:
            printf("You rated this movie as Excellent.\n");
            break;
        case 2:
            printf("You rated this movie as Good.\n");
            break;
        case 3:
            printf("You rated this movie as Average.\n");
            break;
        case 4:
            printf("You rated this movie as Poor.\n");
            break;
        default:
            printf("Invalid rating choice.\n");
            break;
    }

    return 0;
}