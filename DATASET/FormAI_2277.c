//FormAI DATASET v1.0 Category: Syntax parsing ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Welcome to the magical world of C Syntax Parsing! */

int main(){
    char str[100];

    printf("\nHello there! I'm a C Syntax Parsing Program.\n");

    printf("Please enter a C syntax statement: ");
    fgets(str, 100, stdin); // using fgets to get user input

    char * token; // declare token pointer

    token = strtok(str, " "); // split using space as delimiter

    while( token != NULL ) { // while there are still tokens
        printf( " %s\n", token ); // print each token
        token = strtok(NULL, " ");
    }

    printf("Thanks for using me! I hope you learned something about C Syntax Parsing today!");
    
    return 0;
}