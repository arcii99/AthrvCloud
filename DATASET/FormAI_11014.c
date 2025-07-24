//FormAI DATASET v1.0 Category: Data structures visualization ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Declare a stack structure
typedef struct{
    int data[MAX_SIZE];
    int top;
} Stack;

// Initialize the stack by setting top to -1
void init_stack(Stack* s){
    s->top = -1;
}

// Push an element into the stack
void push(Stack* s, int value){
    if(s->top < MAX_SIZE-1){
        s->top++;
        s->data[s->top] = value;
    }
}

// Pop an element from the stack and return it
int pop(Stack* s){
    int value = -1;
    if(s->top >= 0){
        value = s->data[s->top];
        s->top--;
    }
    return value;
}

// Check if the stack is empty
bool is_empty(Stack* s){
    if(s->top < 0){
        return true;
    }
    return false;
}

// Reverse the order of elements in the stack
void reverse_stack(Stack* s){
    if(is_empty(s)){
        return;
    }
    int value = pop(s);
    reverse_stack(s);
    push(s, value);
}

// Print the contents of the stack
void print_stack(Stack* s){
    Stack temp;
    init_stack(&temp);
    while(!is_empty(s)){
        int value = pop(s);
        printf("%d ", value);
        push(&temp, value);
    }
    while(!is_empty(&temp)){
        push(s, pop(&temp));
    }
    printf("\n");
}

int main(){
    Stack s;
    init_stack(&s);

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);

    printf("Original stack: ");
    print_stack(&s);

    reverse_stack(&s);

    printf("Reversed stack: ");
    print_stack(&s);
    
    return 0;
}