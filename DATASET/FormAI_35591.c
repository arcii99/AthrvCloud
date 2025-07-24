//FormAI DATASET v1.0 Category: Movie Rating System ; Style: accurate
#include <stdio.h>

int main()
{
    int rating;
    
    printf("Welcome to the Unique C Movie Rating System!\n");
    printf("Please enter your rating for the movie: ");
    scanf("%d", &rating);
    
    if(rating < 0 || rating > 10)
    {
        printf("Invalid rating. Please enter a rating from 0-10.\n");
        return 0;
    }
    else if(rating >= 0 && rating < 4)
    {
        printf("Terrible movie. Avoid at all costs.\n");
        return 0;
    }
    else if(rating >= 4 && rating < 6)
    {
        printf("Below average movie. Not worth the money.\n");
        return 0;
    }
    else if(rating >= 6 && rating < 8)
    {
        printf("Good movie. Recommended for movie-goers.\n");
        return 0;
    }
    else if(rating >= 8 && rating < 10)
    {
        printf("Great movie. A must-see for everyone.\n");
        return 0;
    }
    else if(rating == 10)
    {
        printf("Masterpiece. The best movie ever made.\n");
        return 0;
    }
    
    return 0;
}