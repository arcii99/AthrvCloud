//FormAI DATASET v1.0 Category: HTML beautifier ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 1000  // maximum size of stack

// defining stack and its operations
typedef struct{
    char data[MAX_STACK_SIZE];
    int top;
}Stack;
void initializeStack(Stack *stack);
void push(Stack *stack, char c);
char pop(Stack *stack);
char peek(Stack *stack);
int isEmpty(Stack *stack);

// main function to beautify HTML code
int main(){
    Stack tagStack;  // stack to store tags
    initializeStack(&tagStack);
    
    char str[10000];  // input string
    printf("Enter the HTML code to beautify:\n");
    fgets(str, 10000, stdin);
    
    int i = 0;
    while(str[i] != '\0'){  // loop to process each character of the input string
        if(str[i] == '<'){  // if opening tag is encountered
            if(!isEmpty(&tagStack)){
                printf("\n");  // insert line break before new tag to improve readability
            }
            push(&tagStack, '<');  // add opening tag to the stack
            putchar(str[i]);  // print the character
        }
        else if(str[i] == '>'){  // if closing tag is encountered
            putchar(str[i]);  // print the character
            pop(&tagStack);  // remove the opening tag from stack
        }
        else{
            putchar(str[i]);  // for all other characters, simply print them
        }
        i++;
    }

    return 0;
}

// function to initialize stack
void initializeStack(Stack *stack){
    stack->top = -1;
}

// function to push an element into stack
void push(Stack *stack, char c){
    if(stack->top >= MAX_STACK_SIZE-1){
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->top++;
    stack->data[stack->top] = c;
}

// function to pop an element from stack
char pop(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack Underflow\n");
        exit(1);
    }
    char c = stack->data[stack->top];
    stack->top--;
    return c;
}

// function to return the top element of stack without removing it
char peek(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->data[stack->top];
}

// function to check if stack is empty
int isEmpty(Stack *stack){
    if(stack->top == -1){
        return 1;
    }
    return 0;
}