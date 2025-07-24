//FormAI DATASET v1.0 Category: Movie Rating System ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

int recursive_rating(int rating) {
    // In a base case, if the rating is below 0, exit the program and return an error message.
    if (rating < 0) {
        printf("Invalid rating.\n");
        exit(EXIT_FAILURE);
    }

    // In another base case, if the rating is between 0 and 3, the movie is considered terrible.
    if (rating >= 0 && rating <= 3) {
        printf("This movie is terrible!\n");
        return 0;
    }

    // The recursive case. We will calculate the rating of the movie by subtracting 3 from the rating and
    // calling the recursive_rating function again with the new rating.
    int r = recursive_rating(rating - 3);

    // Once we have the final rating, we will return it and print an appropriate message.
    if (r == 5) {
        printf("This movie is amazing!\n");
        return 5;
    } else if (r == 4) {
        printf("This movie is great!\n");
        return 4;
    } else {
        printf("This movie is average.\n");
        return 3;
    }
}

int main() {
    int rating;

    // Ask the user to enter the movie rating.
    printf("Enter the movie rating (0-10): ");
    scanf("%d", &rating);

    // Call the recursive_rating function and print the final rating.
    int final_rating = recursive_rating(rating);
    printf("Final rating: %d\n", final_rating);

    return 0;
}