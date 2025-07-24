//FormAI DATASET v1.0 Category: Syntax parsing ; Style: curious
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Welcome to my curious C syntax parsing program!\n");
    
    char input[100];
    
    printf("Enter a C program to parse: \n");
    fgets(input, 100, stdin);
    
    printf("Parsing the program...\n");
    
    int i = 0;
    int vars_count = 0;
    int loops_count = 0;
    int conditions_count = 0;
    
    while(input[i] != '\0'){
        // Parse variables
        if(input[i] == 'i' && input[i+1] == 'n' && input[i+2] == 't'){
            vars_count++;
        }
        
        // Parse loops
        if(input[i] == 'f' && input[i+1] == 'o' && input[i+2] == 'r'){
            loops_count++;
        }
        
        // Parse conditions
        if(input[i] == 'i' && input[i+1] == 'f'){
            conditions_count++;
        }
        
        i++;
    }
    
    printf("Parsing complete!\n");
    printf("Total number of variables in the program: %d\n", vars_count);
    printf("Total number of loops in the program: %d\n", loops_count);
    printf("Total number of conditions in the program: %d\n", conditions_count);
    
    printf("Thanks for using my curious C syntax parsing program!\n");
    
    return 0;
}