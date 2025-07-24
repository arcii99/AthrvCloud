//FormAI DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 10

// Medieval-themed Queue structure
struct Queue {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
};

// Medieval-themed Heroine for enqueue operations
void maidenEnqueue(struct Queue* q, int val) {
    if (q->rear == MAX_QUEUE_SIZE) {
        printf("Sorry, the queue has reached its maximum capacity. \n");
    }
    else {
        q->items[q->rear++] = val;
        printf("Maiden: 'The valorous knight has returned from his quest! I shall add %d to the queue.' \n", val);
    }
}

// Medieval-themed Knight for dequeue operations
int knightDequeue(struct Queue* q) {
    if (q->front == q->rear) {
        printf("Sorry, the queue is currently empty. \n");
        return -1;
    }
    else {
        int item = q->items[q->front++];
        printf("Knight: 'I shall take on this quest and remove %d from the queue.' \n", item);
        return item;
    }
}

// Medieval-themed Sorceress to check if queue is empty
bool sorceressIsEmpty(struct Queue* q) {
    if (q->rear == q->front) {
        printf("Sorceress: 'The queue is as empty as the abyss.' \n");
        return true;
    }
    else {
        printf("Sorceress: 'The queue still holds mysteries to be unraveled.' \n");
        return false;
    }
}

// Medieval-themed King to display the queue elements
void kingDisplayQueue(struct Queue* q) {
    if (q->front == q->rear) {
        printf("King: 'There is nothing to show, the queue is barren.' \n");
    }
    else {
        printf("King: 'These are the current items in the queue:' \n");
        for (int i = q->front; i < q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

// Driver Code
int main() {
    struct Queue q;
    q.front = 0;
    q.rear = 0;
    
    maidenEnqueue(&q, 1);
    maidenEnqueue(&q, 2);
    maidenEnqueue(&q, 3);
    kingDisplayQueue(&q);
    knightDequeue(&q);
    sorceressIsEmpty(&q);
    kingDisplayQueue(&q);
    
    return 0;
}