//FormAI DATASET v1.0 Category: Dice Roller ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int i,num,dice[7];
    srand(time(NULL)); //To get different values of dice on every execution
    printf("Enter the number of dice rolls: ");
    scanf("%d",&num); //To get number of rolls of dice
    
    for(i=0;i<=6;i++){
        dice[i]=0; //Initialize dice values to zero;
    }
    
    for(i=1;i<=num;i++){
        int d=rand()%6+1; //To generate random number between 1 to 6 for each dice roll
        dice[d]++; //Add one to dice counter array
        printf("Dice %d: %d\n",i,d);
    }
    
    printf("\n");
    printf("Dice Rolls\t Number of Times\n");
    
    
    for(i=1;i<=6;i++){
        printf("%d\t\t %d\n",i,dice[i]); //Printing the number of times each number on a dice is rolled
    }
    return 0; //End of Program
}