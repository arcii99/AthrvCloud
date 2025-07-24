//FormAI DATASET v1.0 Category: Table Game ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int nums[10], guess[5], count = 0, i, j;
    
    srand(time(0)); // Get time as seed
    
    // Generate random numbers to form the table
    for(i=0; i<10; i++){
        nums[i] = (rand() % 10) + 1; // Generate nums ranging from 1 to 10
    }
    
    // Output the table
    printf("Table: \n");
    printf(" _ _ _ _ _ _ _ _ _ _\n"); // First row
    for(i=0; i<10; i++){
        printf("|%d ", nums[i]); // Print numbers
        if(i == 4){
            printf("|   <- Guess Here"); // Add hints to guess
        }
    }
    printf("|\n");
    printf(" ‾ ‾ ‾ ‾ ‾ ‾ ‾ ‾ ‾ ‾ ‾\n"); // Last row
    
    // Ask for user input 5 times
    for(i=0; i<5; i++){
        printf("\nEnter guess %d: ", i+1);
        scanf("%d", &guess[i]);
        
        // Check if guess is correct for all numbers in the table
        if(guess[i] == nums[i+5]){
            printf("\nCorrect Guess!\n");
            count++; // Increase count if guess is correct
        }
        else{
            printf("\nSorry, Wrong Guess :(\n");
        }
    }
    
    // Output final result
    printf("\nYou have guessed %d numbers correctly out of 5. \n", count);
    
    return 0;
}