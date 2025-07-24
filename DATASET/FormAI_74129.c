//FormAI DATASET v1.0 Category: Movie Rating System ; Style: shocked
#include <stdio.h>
#include <string.h>

int main()
{
    char movie[50];
    int rating;

    printf("Welcome to the C Movie Rating System!\n");
    printf("Please enter the name of the movie: ");
    scanf("%s", movie);

    printf("Please rate the movie out of 10: ");
    scanf("%d", &rating);

    if (rating < 0 || rating > 10)
    {
        printf("Invalid rating. Please rate the movie out of 10: ");
        scanf("%d", &rating);
    }

    if (rating >= 0 && rating <= 3)
    {
        printf("\nOh my God, did you even watch the movie? This is a terrible rating for %s.\n", movie);

    }
    else if (rating >= 4 && rating <= 6)
    {
        printf("\nHmm, we're not sure if we like %s very much with this rating.\n", movie);
    }
    else if (rating >= 7 && rating <= 8)
    {
        printf("\nImpressive rating for %s! This is definitely a movie to watch!\n", movie);
    }
    else
    {
        printf("\nWow, this is an exceptional rating for %s! We'll be sure to recommend this movie to everyone!\n", movie);
    }

    return 0;
}