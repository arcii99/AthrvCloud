//FormAI DATASET v1.0 Category: Data structures visualization ; Style: realistic
#include <stdio.h>

#define MAX_SIZE 100

// define a struct of a person with name and age attributes
typedef struct Person {
    char name[20];
    int age;
} Person;

// define a stack data structure
typedef struct Stack {
    Person arr[MAX_SIZE];
    int top;
} Stack;

// function to add a person to the stack
void push(Stack* stack, Person p) {
    if (stack->top == MAX_SIZE-1) {
        printf("Stack overflow\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = p;
}

// function to remove a person from the stack
Person pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        Person p;
        p.age = -1;
        return p;
    }
    Person p = stack->arr[stack->top];
    stack->top--;
    return p;
}

// function to display all elements in the stack
void displayStack(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("Name: %s\n", stack->arr[i].name);
        printf("Age: %d\n", stack->arr[i].age);
    }
}

int main() {
    // create a stack and add some people to it
    Stack stack;
    stack.top = -1;

    Person p1 = {"Alice", 24};
    push(&stack, p1);

    Person p2 = {"Bob", 32};
    push(&stack, p2);

    Person p3 = {"Charlie", 19};
    push(&stack, p3);

    // display the stack
    displayStack(&stack);

    // remove some people from the stack
    pop(&stack);
    pop(&stack);

    // display the stack again
    displayStack(&stack);

    return 0;
}