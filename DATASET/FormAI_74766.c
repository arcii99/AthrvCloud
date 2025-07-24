//FormAI DATASET v1.0 Category: Movie Rating System ; Style: systematic
#include <stdio.h>

// Function to get user input and validate it
int getValidRating() {
    int rating;
    printf("Enter a rating (1-10): ");
    scanf("%d", &rating);
    while (rating < 1 || rating > 10) {
        printf("Invalid rating. Enter a rating (1-10): ");
        scanf("%d", &rating);
    }
    return rating;
}

// Function to calculate the average rating
double getAverageRating(int numRatings, int ratings[]) {
    int i;
    double sum = 0.0;
    for (i = 0; i < numRatings; i++) {
        sum += ratings[i];
    }
    return sum / numRatings;
}

// Main function
int main() {
    int numRatings, i;
    printf("Enter the number of ratings: ");
    scanf("%d", &numRatings);

    // Dynamic memory allocation for array of int ratings
    int *ratings = (int*) malloc(numRatings * sizeof(int));

    // Prompt user for each rating and store it in the array
    for (i = 0; i < numRatings; i++) {
        ratings[i] = getValidRating();
    }

    // Print the average rating
    printf("Average rating: %.2f\n", getAverageRating(numRatings, ratings));

    // Free the dynamically allocated memory
    free(ratings);

    return 0;
}