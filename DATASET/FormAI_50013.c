//FormAI DATASET v1.0 Category: Movie Rating System ; Style: mathematical
#include <stdio.h>

int main() { 
    int numReviews;
    float sumRating = 0.0;
    
    printf("How many reviews do you want to rate? ");
    scanf("%d", &numReviews);
    
    for (int i = 1; i <= numReviews; i++) {
        float rating;
        printf("Enter rating for review %d: ", i);
        scanf("%f", &rating);
        
        if (rating >= 0 && rating <= 5) {
            sumRating += rating;
        } else {
            printf("Invalid rating. Please enter a number between 0 and 5.\n");
            i--; // decrement i so the loop repeats for the same review number
        }
    }
    
    float avgRating = sumRating / numReviews;
    
    if (avgRating < 2.0) {
        printf("The average rating is %.2f. This movie has a POOR rating.\n", avgRating);
    } else if (avgRating < 3.0) {
        printf("The average rating is %.2f. This movie has an AVERAGE rating.\n", avgRating);
    } else if (avgRating < 4.5) {
        printf("The average rating is %.2f. This movie has a GOOD rating.\n", avgRating);
    } else {
        printf("The average rating is %.2f. This movie has an EXCELLENT rating!\n", avgRating);
    }
    
    return 0;
}