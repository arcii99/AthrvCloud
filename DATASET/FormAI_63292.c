//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Romeo and Juliet
// Romeo, a young and passionate developer
// Wrote code to implement Queue in C
// He wanted to impress his love, Juliet
// So he worked hard and never quit

// Juliet was curious, so asked Romeo
// "What is this code you wrote, my dear beau?"
// Romeo smiled and said, "It's a Queue,
// A data structure that'll make you say Woo!"

#include<stdio.h>
#include<stdlib.h>

#define SIZE 50

struct Queue
{
    int items[SIZE];
    int front;
    int rear;
};

typedef struct Queue Queue;

// Enqueue function
void Enqueue(Queue *q, int val)
{
    if(q->rear == SIZE-1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if(q->front == -1)
        {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = val;
        printf("Inserted %d\n", val);
    }
}

// Dequeue function
int Dequeue(Queue *q)
{
    int item;
    if(q->front == -1 || q->front > q->rear)
    {
        printf("Queue is empty\n");
        item = -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        printf("Deleted %d\n", item);
    }
    return item;
}

// The main function
void main()
{
    // Romeo created an empty Queue
    Queue q;
    q.front = -1;
    q.rear = -1;

    // Juliet asked Romeo to Enqueue some items
    Enqueue(&q, 1);
    Enqueue(&q, 2);
    Enqueue(&q, 3);

    // Romeo then Dequeued the items
    int x = Dequeue(&q);
    if(x != -1)
    {
        printf("Front element is %d\n", x);
    }

    x = Dequeue(&q);
    if(x != -1)
    {
        printf("Front element is %d\n", x);
    }

    x = Dequeue(&q);
    if(x != -1)
    {
        printf("Front element is %d\n", x);
    }

    // Romeo and Juliet lived happily ever after
}