//FormAI DATASET v1.0 Category: Data structures visualization ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX 10

// Struct representing the stack
typedef struct {
    int arr[MAX];
    int top;
} Stack;

// Push function to add element on the top of stack
void push(Stack *stack, int element) {
    if (stack->top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = element;
    printf("Pushed %d on to the stack.\n", element);
}

// Pop function to remove element from the top of stack
int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    int element = stack->arr[stack->top];
    stack->top--;
    printf("Popped %d from the stack.\n", element);
    return element;
}

// Display function to visualize the contents of the stack
void display(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is Empty!\n");
        return;
    }
    printf("Current stack:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->arr[i]);
    }
}

// Thread function to add elements to stack
void *addElements(void *param) {
    Stack *stack = (Stack *) param;
    for (int i = 0; i < MAX; i++) {
        push(stack, i);
        sleep(1);
    }
    pthread_exit(NULL);
}

// Thread function to remove elements from stack
void *removeElements(void *param) {
    Stack *stack = (Stack *) param;
    for (int i = 0; i < MAX; i++) {
        pop(stack);
        sleep(1);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t addThread, removeThread;
    Stack stack;
    stack.top = -1;

    // Create and run addElements thread
    if(pthread_create(&addThread, NULL, addElements, &stack) != 0) {
        perror("Error: cannot create thread");
        exit(-1);
    }

    // Create and run removeElements thread
    if(pthread_create(&removeThread, NULL, removeElements, &stack) != 0) {
        perror("Error: cannot create thread");
        exit(-1);
    }

    // Wait for threads to finish
    if(pthread_join(addThread, NULL) != 0) {
        perror("Error: cannot join thread");
        exit(-1);
    }
    if(pthread_join(removeThread, NULL) != 0) {
        perror("Error: cannot join thread");
        exit(-1);
    }

    // Display the final contents of the stack
    display(&stack);

    return 0;
}