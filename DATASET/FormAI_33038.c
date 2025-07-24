//FormAI DATASET v1.0 Category: Syntax parsing ; Style: grateful
#include<stdio.h>
#include<stdlib.h>

#define MAX_STACK_SIZE 100

char openingBracket(char c) {
    switch(c) {
        case ')': return '(';
        case '}': return '{';
        case ']': return '[';
        default: return '\0';
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char c;
    char stack[MAX_STACK_SIZE];
    int top = -1;

    if(argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while((c = fgetc(fp)) != EOF) {
        if(c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        }
        else if(c == ')' || c == '}' || c == ']') {
            if(top == -1 || stack[top] != openingBracket(c)) {
                printf("Error: unmatched brackets/parentheses\n");
                fclose(fp);
                return 1;
            }
            else {
                top--;
            }
        }
    }

    if(top == -1) {
        printf("All brackets/parentheses are properly paired and nested.\n");
    }
    else {
        printf("Error: unmatched brackets/parentheses\n");
        fclose(fp);
        return 1;
    }

    fclose(fp);
    return 0;
}