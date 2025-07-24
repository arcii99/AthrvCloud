//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int score = 0;
    char input;
    srand(time(0));

    printf("Welcome to Shape Shifter game!\n");
    printf("Instructions:\n");
    printf("The game will generate a random shape and ask you to transform it into another random shape.\n");
    printf("You have to press the right letter to transform the shape within 3 seconds.\n");
    printf("A correct answer will get you 1 point and a wrong answer will deduct 1 point.\n");
    printf("The game will end if your score is less than -5.\n\n");
    
    while(score >= -5)
    {
        int shape1 = rand() % 4 + 1;
        int shape2 = rand() % 4 + 1;
        while(shape1 == shape2)
        {
            shape2 = rand() % 4 + 1;
        }

        // Display shape1
        switch(shape1)
        {
            case 1:
                printf("Shape: [][][]\n");
                break;
            case 2:
                printf("Shape: []\n      [][]\n");
                break;
            case 3:
                printf("Shape:   [][]\n      [][]  \n");
                break;
            case 4:
                printf("Shape: [][]\n        [][]\n");
                break;
        }

        // Get user input
        printf("Transform into the following shape within 3 seconds:\n");
        switch(shape2)
        {
            case 1:
                printf("[][][]\n");
                input = getchar();
                if(input == 'c')
                {
                    score++;
                }
                else
                {
                    score--;
                }
                break;
            case 2:
                printf("[]\n[][]\n");
                input = getchar();
                if(input == 'd')
                {
                    score++;
                }
                else
                {
                    score--;
                }
                break;
            case 3:
                printf("[][]\n  [][]\n");
                input = getchar();
                if(input == 'g')
                {
                    score++;
                }
                else
                {
                    score--;
                }
                break;
            case 4:
                printf("[]\n[]\n[]\n[]\n");
                input = getchar();
                if(input == 'h')
                {
                    score++;
                }
                else
                {
                    score--;
                }
                break;
        }

        printf("Current score: %d\n\n", score);
        fflush(stdin);
    }

    printf("Game over! Your score: %d\n", score);
    return 0;
}