//FormAI DATASET v1.0 Category: Movie Rating System ; Style: interoperable
#include <stdio.h>

// function to display the rating stars for a given rating
void displayRating(int rating) {
    printf("Rating: ");
    for (int i = 0; i < rating; i++) {
        printf("*");
    }
    printf("\n");
}

int main() {
    int rating;
    printf("Welcome to C Movie Rating System\n");
    
    do {
        printf("\nEnter your rating for the movie out of 10 (0 to exit):");
        scanf("%d", &rating);
        
        if (rating >= 1 && rating <= 10) {
            displayRating(rating);
            if (rating <= 4) {
                printf("We're sorry to hear that you didn't enjoy the movie.\n");
            } else if (rating >= 5 && rating <= 7) {
                printf("We're glad to hear that you enjoyed the movie.\n");
            } else {
                printf("Wow! You really loved the movie.\n");
            }
        } else if (rating == 0) {
            printf("Thank you for using C Movie Rating System.\n");
        } else {
            printf("Invalid input. Rating should be between 1-10 or 0 to exit.\n");
        }
    } while (rating != 0);
    
    return 0;
}