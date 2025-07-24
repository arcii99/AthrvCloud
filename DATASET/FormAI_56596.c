//FormAI DATASET v1.0 Category: Arithmetic ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, result;
    char operator;
    
    srand(time(NULL)); // set the random seed based on the current time
    
    printf("===== RETRO CALCULATOR =====\n");
    printf("Enter 'q' anytime to quit.\n\n");
    
    while(1) {
        num1 = rand() % 100;
        num2 = rand() % 100;
        
        printf("What is %d ? (+, -, *, or /): ", num1);
        scanf(" %c", &operator);
        
        if(operator == 'q') { // quit program
            break;
        }
        else if(operator == '+') { // addition
            result = num1 + num2;
            printf("The answer is %d !\n\n", result);
        }
        else if(operator == '-') { // subtraction
            result = num1 - num2;
            printf("The answer is %d !\n\n", result);
        }
        else if(operator == '*') { // multiplication
            result = num1 * num2;
            printf("The answer is %d !\n\n", result);
        }
        else if(operator == '/') { // division
            result = num1 / num2;
            printf("The answer is %d !\n\n", result);
        }
        else { // unrecognized operator
            printf("Sorry, I didn't understand that.\n\n");
        }
    }
    
    printf("Thank you for using the Retro Calculator!\n");
    
    return 0;
}