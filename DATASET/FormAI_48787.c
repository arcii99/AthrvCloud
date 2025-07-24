//FormAI DATASET v1.0 Category: Data validation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* This is a unique data validation program that checks if a given input is a valid number or not.
 * The program accepts an input integer from the user and returns whether it is positive, negative, or zero. 
 * If the input is not a valid number, the program prompts the user to enter a valid number. */

int main(){

    int num; //Declare a variable to hold the input
    
    while(true){ //Enter an infinite loop until a valid input is entered
        
        printf("Enter a number: "); //Prompt the user to enter a number
        
        if(scanf("%d", &num) == 1){ //Check if the input is a valid integer
            break; //If a valid integer is entered, exit the loop
        }
        else{ //If the input is not a valid integer
            printf("Invalid input! Please enter a valid number.\n"); //Prompt the user to enter a valid number
            fflush(stdin); //Flush the input buffer to clear any invalid characters
        }
    }
    
    //Check if the input is positive, negative, or zero
    
    if(num > 0){
        printf("%d is a positive number.\n", num);
    }
    else if(num < 0){
        printf("%d is a negative number.\n", num);
    }
    else{
        printf("%d is zero.\n", num);
    }
    
    return 0; //Exit the program
}