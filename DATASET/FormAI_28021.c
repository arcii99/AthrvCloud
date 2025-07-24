//FormAI DATASET v1.0 Category: Movie Rating System ; Style: unmistakable
#include <stdio.h>

// Function to print the movie rating based on user input
void printRating(int rating) {
    if(rating < 0 || rating > 10) {
        printf("Invalid rating!\n");
        return;
    }
    
    if(rating >= 8) {
        printf("Excellent!\n");
    }
    else if(rating >= 6) {
        printf("Good\n");
    }
    else if(rating >= 4) {
        printf("Fair\n");
    }
    else {
        printf("Poor\n");
    }
}

int main() {
    int rating;
    printf("Please enter the movie rating (0-10): ");
    scanf("%d", &rating);
    
    printRating(rating);
    
    return 0;
}