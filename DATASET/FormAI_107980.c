//FormAI DATASET v1.0 Category: Dice Roller ; Style: expert-level
#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 

int main(){
    int n; 
    char c;
    
    srand(time(0)); //seed for random number generation
    
    printf("Welcome to Dice Roller!\n");
    
    do{
        printf("\nEnter the number of dice to roll: ");
        scanf("%d",&n);  //input number of dice to roll
        
        if(n<=0) printf("Invalid input. Number of dice must be greater than 0.\n"); 
        
    }while(n<=0);  
    
    int* dice_result = calloc(n,sizeof(int));  //array to store results of each dice roll
    
    printf("\nRolling %d dice...\n",n);
    for(int i=0; i<n; i++){
        dice_result[i] = rand()%6+1;  //generate random number between 1 to 6
    }
    
    printf("\nResults: ");
    for(int i=0; i<n; i++){
        printf("%d ",dice_result[i]);  //display each dice result
    }
    
    free(dice_result);  //free allocated memory
    
    printf("\nEnter 'y' to roll again, any other key to exit: ");
    scanf(" %c",&c);  //input to roll again or exit
    
    if(c=='y') main();  //call main function to roll again
    
    printf("\nGoodbye!");
    
    return 0;
}