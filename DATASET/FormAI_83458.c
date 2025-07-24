//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

struct queue {      //A queue data structure with fixed size MAX_SIZE
    int front, rear;
    int items[MAX_SIZE];
};

struct stack {      //A stack data structure with fixed size MAX_SIZE
    int top;
    int items[MAX_SIZE];
};

void displayQueue(struct queue* q) {  //Function to display contents of a queue
    printf("\nQueue: ");
    int i;
    for(i = q->front; i < q->rear; i++) {
        printf("%d ", q->items[i]);
    }
}

void displayStack(struct stack* s) {  //Function to display contents of a stack
    printf("\nStack: ");
    int i;
    for(i = 0; i < s->top; i++) {
        printf("%d ", s->items[i]);
    }
}

int main() {
    struct queue q;   //Creating a queue instance
    q.front = 0;
    q.rear = 0;

    struct stack s;   //Creating a stack instance
    s.top = 0;

    //Enqueueing items into the queue
    printf("Enqueueing items into the queue...\n");
    q.items[q.rear++] = 10;
    q.items[q.rear++] = 20;
    q.items[q.rear++] = 30;
    q.items[q.rear++] = 40;
    displayQueue(&q);

    //Dequeuing items from the queue and pushing them into the stack
    printf("\nDequeuing items from the queue and pushing into the stack...\n");
    while(q.front != q.rear) {
        s.items[s.top++] = q.items[q.front++];
    }
    displayQueue(&q);
    displayStack(&s);

    //Popping items from the stack and enqueueing them into the queue
    printf("\nPopping items from the stack and enqueueing them into the queue...\n");
    while(s.top != 0) {
        q.items[q.rear++] = s.items[--s.top];
    }
    displayQueue(&q);
    displayStack(&s);

    //Enqueueing more items into the queue
    printf("\nEnqueueing more items into the queue...\n");
    q.items[q.rear++] = 50;
    q.items[q.rear++] = 60;
    displayQueue(&q);

    //Dequeueing items from the queue and displaying them
    printf("\nDequeuing items from the queue and displaying them...\n");
    while(q.front != q.rear) {
        printf("%d ", q.items[q.front++]);
    }
    displayQueue(&q);

    return 0;
}