//FormAI DATASET v1.0 Category: Syntax parsing ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* This program demonstrates a simple C syntax parser */

int main()
{
    char input[1000]; // array to store user input
    char keyword[32][10] = {"auto", "break", "case", "char", "const", "continue", "default", "do", 
    "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", 
    "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", 
    "unsigned", "void", "volatile", "while"}; // array to store C keywords
    int count = 0; // variable to store keyword count
    
    printf("Enter a C program: "); // prompting user
    fgets(input, 1000, stdin); // reading user input
    
    char* token = strtok(input, " \t\n(){}[];,<>+-*&|=!/\""); // getting first token
    
    while(token != NULL)
    {
        for(int i=0;i<32;i++)
        {
            if(strcmp(token, keyword[i]) == 0) // comparing tokens with keywords
            {
                count++; // incrementing keyword count
                break;
            }
        }
        
        token = strtok(NULL, " \t\n(){}[];,<>+-*&|=!/\""); // getting next token
    }
    
    printf("This program has %d keywords\n", count); // printing keyword count
    
    return 0; // returning success
}