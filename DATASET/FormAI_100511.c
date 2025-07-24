//FormAI DATASET v1.0 Category: Movie Rating System ; Style: grateful
#include <stdio.h>

int main()
{
    int rating;
    printf("Welcome to the Unique C Movie Rating System!\n");
    printf("Please rate the following movies from 1 - 10:\n");

    //asking for user input
    printf("The Shawshank Redemption: ");
    scanf("%d", &rating);

    //checking user input and giving output
    if(rating<=3) 
    {
        printf("You didn't like The Shawshank Redemption, better luck next time!\n");
    }
    else if(rating<=6)
    {
        printf("You thought The Shawshank Redemption was okay.\n");
    }
    else if(rating<=9)
    {
        printf("You really enjoyed The Shawshank Redemption!\n");
    }
    else
    {
        printf("You thought The Shawshank Redemption was a masterpiece!\n");
    }

    //repeating the process for other movies
    printf("The Godfather: ");
    scanf("%d", &rating);
    if(rating<=3) 
    {
        printf("You didn't like The Godfather, better luck next time!\n");
    }
    else if(rating<=6)
    {
        printf("You thought The Godfather was okay.\n");
    }
    else if(rating<=9)
    {
        printf("You really enjoyed The Godfather!\n");
    }
    else
    {
        printf("You thought The Godfather was a masterpiece!\n");
    }

    printf("The Dark Knight: ");
    scanf("%d", &rating);
    if(rating<=3) 
    {
        printf("You didn't like The Dark Knight, better luck next time!\n");
    }
    else if(rating<=6)
    {
        printf("You thought The Dark Knight was okay.\n");
    }
    else if(rating<=9)
    {
        printf("You really enjoyed The Dark Knight!\n");
    }
    else
    {
        printf("You thought The Dark Knight was a masterpiece!\n");
    }

    //ending message
    printf("Thank you for rating the movies!\n");

    return 0;
}