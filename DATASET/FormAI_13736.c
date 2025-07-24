//FormAI DATASET v1.0 Category: Movie Rating System ; Style: funny
#include <stdio.h>

int main()
{
    char rating;
    printf("Welcome to the unique C Movie Rating System!\n");
    printf("Please enter your rating for the movie on a scale of A to F: ");
    scanf("%c", &rating);

    if (rating == 'A')
    {
        printf("Wow! You must have really enjoyed the movie! We'll give it a 10/10\n");
    }
    else if (rating == 'B')
    {
        printf("A solid rating, we'll give the movie a 7/10\n");
    }
    else if (rating == 'C')
    {
        printf("I mean, it's not great, but it's by no means terrible. We'll give the movie a 5/10\n");
    }
    else if (rating == 'D')
    {
        printf("Yikes, not a great rating. The movie gets a 3/10\n");
    }
    else if (rating == 'F')
    {
        printf("Oh no. The movie scored an F? We're sorry to hear that. We'll give it a 1/10\n");
    }
    else
    {
        printf("Invalid rating. Please enter a rating from A-F\n");
    }

    printf("Thanks for participating in the unique C Movie Rating System!");

    return 0;
}