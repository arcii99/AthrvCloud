//FormAI DATASET v1.0 Category: Movie Rating System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rating;
    char movie_title[50];
    char review[200];
    printf("Welcome to the Medieval Movie Rating System!\n");
    printf("Enter the title of the movie: ");
    scanf("%s", movie_title);
    printf("Enter your review of the movie (max 200 characters): ");
    scanf(" %[^\n]%*c", review);
    printf("You have given the movie '%s' a review of: \n", movie_title);
    printf("%s\n", review);
    printf("Please rate the movie on a scale of 1 to 10: ");
    scanf("%d", &rating);
    printf("You have given the movie '%s' a rating of %d out of 10!\n", movie_title, rating);
    if (rating < 5)
    {
        printf("Oh dear, it looks like '%s' didn't quite meet your expectations. We'll make sure to pass your feedback along to the filmmakers.\n", movie_title);
    }
    else if (rating >= 5 && rating <= 7)
    {
        printf("Thanks for your review of '%s'! It's always good to hear feedback, and we'll make sure to let the filmmakers know what you thought.\n", movie_title);
    }
    else if (rating > 7)
    {
        printf("Wow! A rating of %d out of 10 for '%s'! It sounds like you really enjoyed the movie. Thanks for your review, and we'll make sure to let the filmmakers know what you thought!\n", rating, movie_title);
    }
    return 0;
}