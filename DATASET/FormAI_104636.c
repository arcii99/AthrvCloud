//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: unmistakable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

int top = -1;
char arr[MAX];

void push(char input) {
    // check if stack is full
    if(top == MAX-1) {
        printf("Stack Overflow! Cannot push %c onto stack\n", input);
        return;
    }
    // push the input onto the stack
    arr[++top] = input;
}

char pop() {
    // check if stack is empty
    if(top == -1) {
        printf("Stack Underflow! Cannot pop from an empty stack\n");
        exit(1);
    }
    // pop the top element of the stack
    return arr[top--];
}

int main() {
    char str[MAX];
    int i, len;
    top = -1; // initialize the stack to empty
    printf("Enter a string: ");
    scanf("%s", str);
    len = strlen(str);
    for(i = 0; i < len; i++) {
        push(str[i]); // push all characters of the string onto the stack
    }
    // pop all characters from the stack and compare with the original string
    for(i = 0; i < len; i++) {
        if(str[i] != pop()) {
            printf("%s is not a palindrome", str);
            return 0;
        }
    }
    printf("%s is a palindrome", str);
    return 0;
}