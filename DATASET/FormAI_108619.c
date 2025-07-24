//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: scientific
#include<stdio.h>
#include<stdlib.h>

int main(){
    int input;
    int sum = 0;
    char c;
    
    printf("This program will only accept positive integers.\n");
    printf("Enter 0 to exit the program.\n");
    
    while(1){
        
        printf("Enter a positive integer: ");
        
        // Read input
        while(scanf("%d", &input) != 1){
            while((c = getchar()) != '\n' && c != EOF);// Clear input buffer
            printf("Invalid input. Please enter a positive integer: ");
        }
        
        // Check for exit signal
        if(input == 0){
            printf("Exiting program.\n");
            break;
        }
        
        // Check for negative input
        if(input < 0){
            printf("Negative numbers not allowed. Please enter a positive integer: ");
            continue;
        }
        
        // Add input to sum
        sum += input;
    }
    
    printf("The sum of all positive integers entered is: %d.\n", sum);
    
    return 0;
}