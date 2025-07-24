//FormAI DATASET v1.0 Category: Movie Rating System ; Style: random
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int rating = 0;

    printf("Welcome to the C Movie Rating System!\n");
    printf("Please rate the movie on a scale of 1 to 10:\n");
    scanf("%d", &rating);

    if(rating >= 1 && rating <= 10)
    {
        printf("\nThanks for rating the movie!\n");
        printf("Your rating: %d\n", rating);

        switch(rating)
        {
            case 1:
                printf("That was horrible!\n");
                break;
            case 2:
                printf("That was really bad!\n");
                break;
            case 3:
                printf("That was bad!\n");
                break;
            case 4:
                printf("That was below average!\n");
                break;
            case 5:
                printf("That was average!\n");
                break;
            case 6:
                printf("That was good!\n");
                break;
            case 7:
                printf("That was really good!\n");
                break;
            case 8:
                printf("That was great!\n");
                break;
            case 9:
                printf("That was fantastic!\n");
                break;
            case 10:
                printf("That was a masterpiece!\n");
                break;
        }
    }
    else
    {
        printf("\nInvalid rating!\n");
        printf("Please enter a rating between 1 and 10.\n");
    }

    return 0;
}