//FormAI DATASET v1.0 Category: Dice Roller ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int dice;
    srand(time(NULL)); // Seed for random number generation
    printf("Welcome to the Cyberpunk Dice Roller!\n");
    printf("Enter the number of dice you want to roll: ");
    scanf("%d",&dice);
    printf("-----------------------------------------------\n");
    printf("Rolling %d dice...\n\n",dice);
    int sum = 0; // Variable to store the sum of the rolled dice
    for(int i=1;i<=dice;i++){
        int roll = rand()%6+1; // Generating random numbers from 1 to 6 for each dice
        printf("Dice %d rolled a %d\n",i,roll);
        sum += roll; // Adding the roll to the sum variable
    }
    printf("\n-----------------------------------------------\n");
    printf("Total roll: %d\n",sum);
    printf("-----------------------------------------------\n");
    printf("Thank you for using the Cyberpunk Dice Roller!");
    return 0;
}