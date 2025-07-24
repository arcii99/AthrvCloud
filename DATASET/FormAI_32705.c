//FormAI DATASET v1.0 Category: Data structures visualization ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Structure for each node of the queue
struct queueNode {
    int data;
    struct queueNode* next;
};

// Structure for the queue
struct queue {
    struct queueNode *front, *rear;
};

// Function to create a new node with given data
struct queueNode* newQueueNode(int data)
{
    struct queueNode* temp = (struct queueNode*)malloc(sizeof(struct queueNode));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to create a new queue
struct queue* createQueue()
{
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to add an element to the queue
void enqueue(struct queue* q, int data)
{
    struct queueNode* temp = newQueueNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Function to remove an element from the queue
void dequeue(struct queue* q)
{
    if (q->front == NULL) {
        return;
    }
    struct queueNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}

// Function to display the queue
void display(struct queue* q)
{
    struct queueNode* temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    // Creating a new queue
    struct queue* q = createQueue();
    
    // Adding elements to the queue
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    
    // Displaying the queue
    display(q);
    
    // Removing an element from the queue
    dequeue(q);
    
    // Displaying the updated queue
    display(q);
    
    return 0;
}