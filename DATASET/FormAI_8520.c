//FormAI DATASET v1.0 Category: Data structures visualization ; Style: happy
#include <stdio.h>
#define MAX_SIZE 10

struct stack {
    int items[MAX_SIZE];
    int top;
};

typedef struct stack Stack;

void initializeStack(Stack *s) {
    s -> top = -1;
}

int isFull(Stack *s) {
    return s -> top == MAX_SIZE - 1;
}

int isEmpty(Stack *s) {
    return s -> top == -1;
}

void push(Stack *s, int item) {
    if(isFull(s)) {
        printf("Stack is full. Cannot push %d\n", item);
    } else {
        s -> top++;
        s -> items[s -> top] = item;
    }
}

int pop(Stack *s) {
    if(isEmpty(s)) {
        printf("Stack is empty. Cannot pop \n");
        return -1;
    } else {
        int item = s -> items[s -> top];
        s -> top--;
        return item;
    }
}

void printStack(Stack *s) {
    printf("\n Stack: ");
    for(int i = 0; i <= s -> top; i++) {
        printf("%d ", s -> items[i]);
    }
    printf("\n");
}

int main() {
    Stack myStack;
    initializeStack(&myStack);

    push(&myStack, 1);
    push(&myStack, 2);
    push(&myStack, 3);
    push(&myStack, 4);
    push(&myStack, 5);
    push(&myStack, 6);
    push(&myStack, 7);
    push(&myStack, 8);
    push(&myStack, 9);
    push(&myStack, 10);
    push(&myStack, 11);

    printStack(&myStack);

    printf("\n Item popped: %d", pop(&myStack));

    printf("\n After popping: ");
    printStack(&myStack);

    return 0;
}