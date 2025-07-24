//FormAI DATASET v1.0 Category: Movie Rating System ; Style: cheerful
#include <stdio.h>

int main()
{
    int rating;

    printf("Welcome to the C Movie Rating System! Please rate the movie you just watched out of 10: ");
    scanf("%d", &rating);

    if (rating >= 9)
    {
        printf("Wow! That's an amazing rating! You must have really loved the movie!\n");
    }
    else if (rating >= 7 && rating <= 8)
    {
        printf("Excellent! You clearly enjoyed the movie a lot!\n");
    }
    else if (rating >= 5 && rating <= 6)
    {
        printf("Not bad, but not great either. The movie was just okay.\n");
    }
    else if (rating >= 3 && rating <= 4)
    {
        printf("That's not a very good rating. You must have been disappointed with the movie.\n");
    }
    else
    {
        printf("Ouch! That's a terrible rating. Looks like you didn't enjoy the movie at all.\n");
    }

    return 0;
}