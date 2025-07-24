//FormAI DATASET v1.0 Category: Data structures visualization ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 10

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

struct Stack {
    int top;
    int* elements;
};

void push(struct Stack* stack, int value) {
    pthread_mutex_lock(&mutex);
    stack->top++;
    stack->elements[stack->top] = value;
    pthread_mutex_unlock(&mutex);
}

int pop(struct Stack* stack) {
    int value = -1;
    pthread_mutex_lock(&mutex);
    if(stack->top != -1) {
        value = stack->elements[stack->top];
        stack->top--;
    }
    pthread_mutex_unlock(&mutex);
    return value;
}

void display(struct Stack* stack) {
    printf("[ ");
    for(int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->elements[i]);
    }
    printf("]\n");
}

void* producer(void* data) {
    struct Stack* stack = ((struct Stack*) data);
    for(int i = 1; i <= MAX_SIZE; i++) {
        push(stack, i);
        printf("Pushed %d\n", i);
        display(stack);
    }
    pthread_exit(NULL);
}

void* consumer(void* data) {
    struct Stack* stack = ((struct Stack*) data);
    int value = -1;
    for(int i = 0; i < MAX_SIZE; i++) {
        value = pop(stack);
        if(value != -1) {
            printf("Popped %d\n", value);
            display(stack);
        }
    }
    pthread_exit(NULL);
}

int main() {
    struct Stack stack;
    stack.top = -1;
    stack.elements = (int*) malloc(sizeof(int) * MAX_SIZE);

    pthread_t producer_thread, consumer_thread;

    pthread_create(&producer_thread, NULL, producer, (void*) &stack);
    pthread_create(&consumer_thread, NULL, consumer, (void*) &stack);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    free(stack.elements);

    return 0;
}