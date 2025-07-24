//FormAI DATASET v1.0 Category: Dice Roller ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i=0, n=0, num=0, sum=0;
    char choice='y';

    srand(time(0)); // seeding the rand function with current time

    do
    {
        printf("Enter the number of dice you want to roll: ");
        scanf("%d",&n);
        printf("\n");

        printf("Your dice roll values are: ");

        for(i=0;i<n;i++)
        {
            num = (rand()%6)+1; // generating random numbers between 1 and 6
            printf("%d ",num);
            sum += num;
        }

        printf("\n");

        printf("The sum of the dice values is: %d",sum);

        printf("\n");

        printf("Do you want to roll again? (y/n): ");
        scanf(" %c",&choice);
        printf("\n");

        sum=0; // resetting sum for next roll

    }while(choice=='y' || choice=='Y');

    printf("Thanks for playing!");

    return 0;
}