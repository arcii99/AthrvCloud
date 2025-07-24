//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>

#define MAX 5 // Maximum size of the stack

int stack[MAX] = {0}; // Initialize the stack with 0s
int top = -1; // Initialize the top of the stack to -1

// Function to push an element into the stack
void push(int elem) {
    if(top == MAX-1) {
        printf("Stack overflow! Cannot push element %d.\n", elem);
        return;
    }
    
    top++;
    stack[top] = elem;
}

// Function to pop an element from the stack
int pop() {
    if(top == -1) {
        printf("Stack underflow! Cannot pop element.\n");
        return -1;
    }
    
    int elem = stack[top];
    stack[top] = 0;
    top--;
    return elem;
}

// Function to display the contents of the stack
void display() {
    printf(" _________\n");
    printf("|         |\n");
    for(int i = MAX-1; i >= 0; i--) {
        printf("|   ");
        if(i <= top) {
            printf("%d", stack[i]);
        }
        printf("    |\n");
    }
    printf("|_________|\n");
}

int main() {
    push(1);
    push(2);
    display();
    
    pop();
    display();
    
    push(3);
    push(4);
    push(5);
    push(6);
    display();
    
    pop();
    pop();
    display();
    
    push(7);
    display();
    
    pop();
    pop();
    pop();
    pop();
    pop();
    display();
    
    return 0;
}