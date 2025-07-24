//FormAI DATASET v1.0 Category: Syntax parsing ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>

int main() {
    char input[100];
    int count = 0;
    printf("Enter a valid C code snippet: \n");
    fgets(input, 100, stdin);
    
    // Parsing the code snippet
    for(int i = 0; i < 100; i++) {
        if(input[i] == '{') {
            count++;
        } else if(input[i] == '}') {
            count--;
        } else if(input[i] == '#') {
            printf("Error: Preprocessor directive not allowed!\n");
            exit(0);
        } else if(input[i] == 'c') {
            printf("Error: Misspelled name of programming language!\n");
            exit(0);
        } else if(input[i] == '/') {
            if(input[i+1] == '/') {
                printf("Error: Single line comments not allowed!\n");
                exit(0);
            } else if(input[i+1] == '*') {
                printf("Error: Multi-line comments not allowed!\n");
                exit(0);
            }
        }
    }
    
    if(count == 0) {
        printf("Code snippet is valid!\n");
    } else {
        printf("Error: Missing curly braces\n");
    }
    return 0;
}