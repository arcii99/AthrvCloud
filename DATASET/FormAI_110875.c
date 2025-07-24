//FormAI DATASET v1.0 Category: Dice Roller ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h> 

int roll(int sides){  //recursive function to roll the dice
    int result;
    if(sides<=0) {
        printf("Number of sides cannot be negative or zero\n");
        exit(0); //exit function if user inputs negative value
    }
    if(sides==1) return 1; //base case
    result = (rand() % sides) + 1; //generating random number between 1 and sides
    printf("Rolling the dice with %d sides: %d\n",sides,result);
    return result+roll(sides-1); //recursively calling roll function
}

int main()
{
    int sides,result;
    srand(time(0)); //Seed for random number generator
    printf("Enter the number of sides: ");
    scanf("%d",&sides);
    result = roll(sides); //calling recursive function
    printf("\nTotal Result: %d",result);
    return 0;
}