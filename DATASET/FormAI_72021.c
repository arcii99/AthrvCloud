//FormAI DATASET v1.0 Category: Movie Rating System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rating;
    printf("Welcome to the C Movie Rating System.\n\n");
    printf("Please rate the movie on a scale of 1 to 10:\n");
    scanf("%d", &rating);
    
    if (rating < 1 || rating > 10) {
        printf("\nInvalid rating entered. Please enter a number between 1 and 10.\n");
        return 0;
    }
    
    if (rating >= 1 && rating <= 3) {
        printf("\nYou rated the movie as Poor.\n");
    } else if (rating >= 4 && rating <= 6) {
        printf("\nYou rated the movie as Average.\n");
    } else if (rating >= 7 && rating <= 8) {
        printf("\nYou rated the movie as Good.\n");
    } else {
        printf("\nYou rated the movie as Excellent.\n");
    }
    
    printf("\nThank you for using the C Movie Rating System!\n");
    return 0;
}