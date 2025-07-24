//FormAI DATASET v1.0 Category: Movie Rating System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rating;
    printf("Welcome to the C Movie Rating System!\n");

    printf("Please rate the movie on a scale of 1 to 10: ");
    scanf("%d", &rating);

    if(rating < 1 || rating > 10)
    {
        printf("Oops, invalid rating! Try again.\n");
        printf("Please rate the movie on a scale of 1 to 10: ");
        scanf("%d", &rating);
    }

    printf("Great, thanks for rating the movie!\n");

    switch(rating)
    {
        case 1:
            printf("Wow, you really didn't like this movie, did you?\n");
            break;
        case 2:
            printf("Well, at least it wasn't the worst movie you've ever seen.\n");
            break;
        case 3:
            printf("Eh, it's definitely not winning any Oscars.\n");
            break;
        case 4:
            printf("It was alright, but you've definitely seen better.\n");
            break;
        case 5:
            printf("A solid middle-of-the-road movie, nothing extraordinary.\n");
            break;
        case 6:
            printf("Not bad, not bad! A decent flick.\n");
            break;
        case 7:
            printf("Hey now, this movie is actually pretty good!\n");
            break;
        case 8:
            printf("Impressive! This movie definitely exceeded your expectations.\n");
            break;
        case 9:
            printf("Wow, this movie was amazing! You'd see it again in a heartbeat.\n");
            break;
        case 10:
            printf("Hands down, this is the best movie you've ever seen. A masterpiece.\n");
            break;
        default:
            printf("Oops, something went wrong. Better luck next time!");
    }

    return 0;
}