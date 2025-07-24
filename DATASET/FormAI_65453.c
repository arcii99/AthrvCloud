//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_QUEUE 10

typedef struct {
    int id;
    bool checked_in;
} Bag;

typedef struct {
    Bag bags[MAX_BAGS];
    int front;
    int rear;
} Queue;

void enqueue(Queue *q, Bag bg) {
    if (q->rear == MAX_QUEUE - 1) {
        printf("Queue is full!\n");
        return;
    }
    q->rear++;
    q->bags[q->rear] = bg;
}

Bag dequeue(Queue *q) {
    if (q->front > q->rear) {
        printf("Queue is empty!\n");
        Bag bg;
        bg.id = -1;
        bg.checked_in = false;
        return bg;
    }
    Bag bg = q->bags[q->front];
    q->front++;
    return bg;
}

int main() {
    srand(time(NULL));
    
    Queue queue;
    queue.front = 0;
    queue.rear = -1;

    int num_bags = rand() % MAX_BAGS + 1;

    for (int i = 0; i < num_bags; i++) {
        Bag bg;
        bg.id = i;
        bg.checked_in = false;
        enqueue(&queue, bg);
    }

    int num_checked_in = 0;
    while (num_checked_in < num_bags) {
        int num_to_check_in = rand() % (MAX_QUEUE - queue.front) + 1;
        for (int i = 0; i < num_to_check_in; i++) {
            Bag bg = dequeue(&queue);
            if (bg.id == -1) {
                continue;
            }
            printf("Checking in bag %d\n", bg.id);
            bg.checked_in = true;
            num_checked_in++;
        }
    }

    printf("All bags checked in!\n");
    return 0;
}