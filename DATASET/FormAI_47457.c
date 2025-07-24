//FormAI DATASET v1.0 Category: Dice Roller ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int sides, num_dice, total, i, j, count;
    float avgRoll;
    char choice;

    srand(time(NULL)); //initialize random number generator

    do{
        printf("Enter the number of sides on the dice:\n");
        scanf("%d", &sides);

        printf("Enter the number of dice to roll:\n");
        scanf("%d", &num_dice);

        printf("How many times do you want to roll the dice?:\n");
        scanf("%d", &count);

        total = 0; //initialize total to 0

        printf("The results are:\n");

        //roll the dice 'count' times
        for(i = 1; i <= count; i++){
            printf("Roll #%d: ", i);
            int roll = 0;
            for(j = 1; j <= num_dice; j++){
                roll += (rand() % sides) + 1; //calculate the roll of each dice
            }
            total += roll; //add the roll to the total
            printf("%d\n", roll);
        }

        avgRoll = (float) total / count; //calculate the average roll

        printf("The total of all the rolls is %d.\n", total);
        printf("The average roll is %.2f.\n", avgRoll);

        fflush(stdin);
        printf("Do you want to roll again? (y/n): ");
        scanf("%c", &choice);

    }while(choice == 'y' || choice == 'Y');

    return 0;
}