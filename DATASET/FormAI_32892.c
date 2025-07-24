//FormAI DATASET v1.0 Category: Movie Rating System ; Style: happy
#include <stdio.h>

int main() {
    int user_rating;
    int total_ratings = 0;
    int num_ratings = 0;
    float avg_rating = 0;
    int rating_data[10];

    printf("Welcome to the Happy Movie Rating System! \n");

    // Get user ratings
    do {
        printf("Please rate the movie on a scale of 1 to 10. (Enter -1 to exit): ");
        scanf("%d", &user_rating);
        if (user_rating >= 1 && user_rating <= 10) { // Valid rating
            rating_data[num_ratings] = user_rating;
            total_ratings += user_rating;
            num_ratings++;
        } else if (user_rating != -1) { // Invalid rating
            printf("Invalid rating. Please enter a rating between 1 and 10 or -1 to exit. \n");
        }
    } while (user_rating != -1 && num_ratings < 10);

    if (num_ratings == 0) { // No ratings entered
        printf("\nNo ratings entered. Goodbye! \n");
        return 0;
    }

    avg_rating = (float)total_ratings / num_ratings;

    printf("\nHere is a summary of the movie's ratings: \n\n");
    for (int i = 0; i < num_ratings; i++) {
        printf("Rating %d: %d \n", i+1, rating_data[i]);
    }
    printf("\nTotal number of ratings: %d \n", num_ratings);
    printf("Average rating: %.2f \n", avg_rating);

    // Calculate Happy Rating
    int happy_rating = (int)avg_rating + 2;

    printf("\nBased on the ratings, the Happy Rating for this movie is: %d \n\n", happy_rating);

    printf("Thank you for using the Happy Movie Rating System! \n");

    return 0;
}