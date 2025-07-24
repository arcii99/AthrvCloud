//FormAI DATASET v1.0 Category: Dice Roller ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int roll_dice(int num_dice, int num_sides);

int main(){
    int num_dice, num_sides;
    char c;
    srand(time(NULL));

    printf("Welcome to Dice Roller!\n");

    do{
        printf("How many dice would you like to roll? ");
        scanf("%d",&num_dice);
        printf("How many sides does each die have? ");
        scanf("%d",&num_sides);

        int total = roll_dice(num_dice,num_sides);

        printf("\nYou rolled %d dice with %d sides each and got a total of %d\n\n",num_dice,num_sides,total);

        printf("Would you like to roll again? (Y/N): ");
        scanf(" %c",&c);

    }while(c=='Y'||c=='y');

    printf("Thanks for rolling dice with us!\n");

    return 0;
}

int roll_dice(int num_dice, int num_sides){
    int total = 0;
    for(int i=0;i<num_dice;++i){
        total += rand()%num_sides+1;
    }
    return total;
}