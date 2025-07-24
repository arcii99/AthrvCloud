//FormAI DATASET v1.0 Category: Dice Roller ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int n, i;
    printf("ENERGIZED DICE ROLLER\n");
    printf("Enter the number of dice you want to roll: ");
    scanf("%d",&n);
    printf("\n");
    srand(time(0)); //seeding the random number generator

    for(i=1;i<=n;i++){
        int roll = rand() % 6 + 1; //generating a random number between 1 to 6
        printf("Dice %d: %d\n",i,roll);
    }

    printf("\nKeep Playing, Keep Rolling!\n");

    return 0;
}