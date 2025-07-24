//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int score=0;

void display(int num)
{
    printf("\nThe number is : %d\n",num);
    printf("Score : %d",score);
}

void check(int num,int guess)
{
    if(num == guess)
    {
        printf("\nCongratulations! Your guess is correct!\n");
        score++;
    }
    else
    {
        printf("\nOops! Your guess is incorrect!\n");
        printf("The correct number is : %d\n",num);
        score--;
    }
}

int main()
{
    srand(time(0));
    int num=0,guess=0;
    char choice;
    printf("\nWelcome to the Number Guessing Game!\n");
    do
    {
        num = rand() % 100 + 1;
        printf("\nGuess a number between 1 to 100\n");
        scanf("%d",&guess);
        check(num,guess);
        display(num);
        printf("\nDo you want to play again? Enter Y/N\n");
        scanf(" %c",&choice);
    } while(choice == 'y' || choice == 'Y');
    return 0;
}