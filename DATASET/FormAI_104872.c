//FormAI DATASET v1.0 Category: Table Game ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void drawline(int n,char symbol)
{
    int i;
    for(i=0;i<n;i++)
        printf("%c",symbol);
    printf("\n");
}

void rules()
{
    system("cls");
    printf("\n\n");
    drawline(80,'-');
    printf("\t\tRULES OF THE GAME\n");
    drawline(80,'-');
    printf("\t1. Choose a number between 1 and 9.\n");
    printf("\t2. If you choose the same number as the computer, you win!\n");
    printf("\t3. You have 5 attempts to guess the computer's number.\n");
    printf("\t4. Goodluck!\n");
    drawline(80,'-');
}

int main()
{
    int number,guess,nguesses=0;
    srand(time(0));
    number=rand()%100+1; // Generates a random number between 1 and 100
    rules();
    do
    {
        printf("Guess the number between 1 and 100: ");
        scanf("%d",&guess);
        nguesses++;
        if(guess>number)
            printf("Lower number please!\n");
        else if(guess<number)
            printf("Higher number please!\n");
        else
            printf("\nCongratulations! You guessed the correct number in %d attempts.\n",nguesses);
    }while(guess!=number&&nguesses!=5);
    if(nguesses==5)
        printf("\nSORRY! YOU LOST THE GAME.\n The correct number is %d\n",number);
    return 0;
}