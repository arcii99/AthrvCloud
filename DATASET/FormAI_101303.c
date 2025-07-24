//FormAI DATASET v1.0 Category: Data structures visualization ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_SIZE 10

typedef struct Stack {
    int top;
    int buffer[MAX_SIZE];
    pthread_rwlock_t rwlock;
} Stack;

void init(Stack *stack) {
    stack->top = -1;
    pthread_rwlock_init(&stack->rwlock, NULL);
}

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int push(Stack *stack, int data) {
    pthread_rwlock_wrlock(&stack->rwlock); // writer lock
    if (isFull(stack)) {
        printf("Stack is full! Cannot push %d\n", data);
        pthread_rwlock_unlock(&stack->rwlock);
        return -1;
    }
    stack->buffer[++stack->top] = data;
    printf("Pushed %d to the stack\n", data);
    pthread_rwlock_unlock(&stack->rwlock); // release lock
    return 1;
}

int pop(Stack *stack) {
    pthread_rwlock_wrlock(&stack->rwlock); // writer lock
    if (isEmpty(stack)) {
        printf("Stack is empty! Cannot pop element\n");
        pthread_rwlock_unlock(&stack->rwlock);
        return -1;
    }
    int data = stack->buffer[stack->top--];
    printf("Popped %d from the stack\n", data);
    pthread_rwlock_unlock(&stack->rwlock); // release lock
    return data;
}

void display(Stack *stack) {
    pthread_rwlock_rdlock(&stack->rwlock); // reader lock
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        pthread_rwlock_unlock(&stack->rwlock);
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->buffer[i]);
    }
    printf("\n");
    pthread_rwlock_unlock(&stack->rwlock); // release lock
}

void *push_thread(void *arg) {
    Stack *stack = (Stack *)arg;

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);

    return NULL;
}

void *pop_thread(void *arg) {
    Stack *stack = (Stack *)arg;

    pop(stack);
    pop(stack);
    pop(stack);

    return NULL;
}

int main() {
    Stack stack;
    init(&stack);

    pthread_t push_tid, pop_tid;
    pthread_create(&push_tid, NULL, push_thread, &stack);
    pthread_create(&pop_tid, NULL, pop_thread, &stack);

    pthread_join(push_tid, NULL);
    pthread_join(pop_tid, NULL);

    display(&stack);

    return 0;
}