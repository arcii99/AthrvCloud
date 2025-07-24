//FormAI DATASET v1.0 Category: Pattern printing ; Style: funny
#include<stdio.h>
int main(){
    printf("Who said C patterns have to be boring? Let's make it fun!\n");

    for (int row = 1; row <= 5; row++) // row loop for 5 rows
    {
        for (int space = 5 - row; space >= 1; space--) // loop to print spaces at the beginning
        {
            printf(" ");
        }
        for (int j = 1; j <= row; j++) // loop to print numbers from 1 to row number
        {
            printf("%d ", j);
        }
        printf("\n"); // move to next line
    }

    printf("How about a pirate ship pattern matey? Arrrrrr!\n");

    for (int row = 1; row <= 6; row++) // row loop for 6 rows
    {
        for (int space = 6 - row; space >= 1; space--) // loop to print spaces before the ship
        {
            printf(" ");
        }
        for (int j = 1; j <= row * 2; j++) // loop to print asterisks for the ship
        {
            printf("*");
        }
        printf("\n"); // move to next line
    }
    // print the ship's mast
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 12; j++)
        {
            if (j == 4 || j == 5 || j == 8 || j == 9)
            {
                printf("|");
            }
            else if (j == 6 || j == 7)
            {
                printf("^");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("Let's finish with a wavy pattern, because life is too short to be boring!\n");

    for (int row = 1; row <= 10; row++) // row loop for 10 rows
    {
        for (int j = 1; j <= 50; j++) // loop to print wavy pattern
        {
            if (j % 10 == row || j % 10 == 10 - row) // if statement to print * for wavy pattern
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n"); // move to next line
    }

    printf("Voila! Fun C patterns that will put a smile on your face! :)\n");
    
    return 0;
}