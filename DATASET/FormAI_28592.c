//FormAI DATASET v1.0 Category: HTML beautifier ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#define TAB_SIZE 4 /* Set the tab size to 4 spaces */

/* Stack implementation */
#define MAX_STACK 1000 /* Maximum size of stack */
int stack[MAX_STACK];
int top = -1;
void push(int value) {
    if (top >= MAX_STACK - 1) { /* Check if stack is full */
        printf("Error: stack overflow\n");
        exit(1);
    }
    top++;
    stack[top] = value;
}
int pop() {
    if (top == -1) { /* Check if stack is empty */
        printf("Error: stack underflow\n");
        exit(1);
    }
    int value = stack[top]; /* Remove element from top */
    top--;
    return value;
}

int main() {
    char ch, prev;
    int i, indent = 0, in_tag = 0;
    while ((ch = getchar()) != EOF) {
        if (ch == '<') {
            in_tag = 1;
            if (prev != '\n')
                putchar('\n');
            for (i = 0; i < indent; i++)
                putchar(' '); /* Indent using spaces */
        }
        putchar(ch);
        if (ch == '>') {
            in_tag = 0;
            if (prev == '/')
                indent -= TAB_SIZE; /* Decrease indent for closing tag */
            else if (prev != '!' && prev != '?')
                push(indent); /* Save indent value for opening tag */
        }
        if (in_tag && ch == '/')
            indent -= TAB_SIZE; /* Decrease indent for closing tag */
        if (prev == '<' && ch != '/')
            indent += TAB_SIZE; /* Increase indent for opening tag */
        prev = ch;
    }
    return 0;
}