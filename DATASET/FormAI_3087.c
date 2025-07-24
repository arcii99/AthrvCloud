//FormAI DATASET v1.0 Category: Syntax parsing ; Style: inquisitive
#include <stdio.h>

int main() {
    printf("Welcome to my C Syntax parser!\n");
    printf("Please input a line of valid C code:\n");
    
    char input[100];
    fgets(input, 100, stdin);

    int i, count = 0;
    for(i = 0; input[i] != '\0'; i++) {
        if(input[i] == '(') {
            count++;
        } else if(input[i] == ')') {
            count--;
        }
    }

    if(count == 0) {
        printf("Your code is properly parenthesized!\n");
    } else {
        printf("Your code is not properly parenthesized.\n");
    }
    
    return 0;
}