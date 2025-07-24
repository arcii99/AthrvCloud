//FormAI DATASET v1.0 Category: Math exercise ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This is a portable C program that generates a random multiplication exercise 
   for users to solve and checks their answer. The program will keep running until 
   the user types 'exit'. */

int main() {
    int a, b, prod, ans;
    char input[5]; // to store user input
    
    srand(time(0)); // use current time as seed for random number generator
    
    printf("Welcome to the Math Exercise program! Type 'exit' to quit.\n\n");
    
    while (1) { // infinite loop until user types 'exit'
        a = rand() % 10 + 1; // generate random number between 1 and 10
        b = rand() % 10 + 1; // generate another random number between 1 and 10
        prod = a * b; // calculate the product
        
        printf("What is the answer to %d x %d? ", a, b);
        fgets(input, 5, stdin); // read user input
        if (strstr(input, "exit") != NULL) { // check if user typed 'exit'
            printf("\nThanks for using the program. Goodbye!\n");
            exit(0);
        }
        ans = atoi(input); // convert input to integer
        
        if (ans == prod) { // user's answer is correct
            printf("Congratulations, your answer is correct!\n\n");
        } else { // user's answer is incorrect
            printf("Sorry, your answer is incorrect. The correct answer is %d.\n\n", prod);
        }
    }
    
    return 0;
}