//FormAI DATASET v1.0 Category: Data structures visualization ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

// stack data structure
typedef struct {
    int top;
    int items[MAX_SIZE];
} Stack;

// queue data structure
typedef struct {
    int front, rear, size;
    int items[MAX_SIZE];
} Queue;

// insert function for stack
void push(Stack *stack, int val) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->items[++stack->top] = val;
}

// delete function for stack
int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack->items[stack->top--];
}

// insert function for queue
void enqueue(Queue *queue, int val) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Queue full!\n");
        return;
    }
    queue->items[++queue->rear] = val;
    queue->size++;
}

// delete function for queue
int dequeue(Queue *queue) {
    if (queue->front == queue->rear) {
        printf("Queue underflow!\n");
        return -1;
    }
    queue->size--;
    return queue->items[++queue->front];
}

int main() {
    Stack stack = { .top = -1 };
    Queue queue = { .front = 0, .rear = -1, .size = 0 };

    // insert values in the stack
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);

    // insert values in the queue
    enqueue(&queue, 6);
    enqueue(&queue, 7);
    enqueue(&queue, 8);
    enqueue(&queue, 9);
    enqueue(&queue, 10);

    printf("Stack contents:\n[ ");
    for (int i = stack.top; i >= 0; i--) {
        printf("%d ", stack.items[i]);
    }
    printf("]\n");

    printf("Queue contents:\n[ ");
    for (int i = queue.front; i <= queue.rear; i++) {
        printf("%d ", queue.items[i]);
    }
    printf("]\n");

    // delete elements from the stack and queue
    int deleted_item1 = pop(&stack);
    int deleted_item2 = dequeue(&queue);

    printf("After deletion:\n");

    printf("Stack contents:\n[ ");
    for (int i = stack.top; i >= 0; i--) {
        printf("%d ", stack.items[i]);
    }
    printf("]\n");

    printf("Queue contents:\n[ ");
    for (int i = queue.front; i <= queue.rear; i++) {
        printf("%d ", queue.items[i]);
    }
    printf("]\n");

    return 0;
}