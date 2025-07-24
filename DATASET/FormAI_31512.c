//FormAI DATASET v1.0 Category: Movie Rating System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rating;
    char movie_name[30];

    printf("Welcome to the Unique C Movie Rating System!\n");
    printf("Please enter the name of the movie you would like to rate: ");
    scanf("%s", movie_name);

    printf("Please enter your rating for %s (1-10): ", movie_name);
    scanf("%d", &rating);

    if (rating < 1 || rating > 10)
    {
        printf("Invalid rating. Please enter a rating between 1 and 10.");
        return 0;
    }

    printf("Processing your rating...\n");

    switch (rating)
    {
        case 1:
        case 2:
        case 3:
            printf("Sorry, your rating of %d for %s has been classified as 'poor'.\n", rating, movie_name);
            break;
        case 4:
        case 5:
        case 6:
            printf("Your rating of %d for %s has been classified as 'average'.\n", rating, movie_name);
            break;
        case 7:
        case 8:
        case 9:
            printf("Congratulations! Your rating of %d for %s has been classified as 'good'.\n", rating, movie_name);
            break;
        case 10:
            printf("Wow! Your rating of %d for %s has been classified as 'excellent'.\n", rating, movie_name);
            break;
    }

    return 0;
}