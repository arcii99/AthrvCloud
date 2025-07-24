//FormAI DATASET v1.0 Category: Dice Roller ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int i = 0;
    int n = 0;
    int dice1 = 0, dice2 = 0, sum = 0;
    srand(time(NULL)); //Seeding the random number generator
    printf("\nWelcome to the futuristic Dice Roller!\n\n");
    while(1){
        printf("Enter the number of dice rolls (-1 to exit): ");
        scanf("%d", &n);
        if(n==-1) break; //Exiting condition
        printf("\n");
        for(i=0;i<n;i++){
            dice1 = rand()%6+1; //Generating random number between 1 and 6
            dice2 = rand()%6+1;
            sum += dice1 + dice2;
            printf("Dice Roll %d: %d %d\n", i+1, dice1, dice2); //Printing the results
        }
        printf("\nTotal Sum: %d\n\n", sum);
        sum = 0;
    }
    printf("Thank you for using the futuristic Dice Roller!\n\n");
    return 0;
}