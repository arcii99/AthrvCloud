//FormAI DATASET v1.0 Category: Queue ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int front;
    int rear;
    int size;
    int data[MAX_QUEUE_SIZE];
} Queue;

void enqueue(Queue* queue, int newItem){
    if(queue->size == MAX_QUEUE_SIZE)
        printf("Queue is full.\n");
    else{
        if(queue->rear == MAX_QUEUE_SIZE - 1)
            queue->rear = 0;
        else
            queue->rear++;
        queue->data[queue->rear] = newItem;
        queue->size++;
    }
}

int dequeue(Queue* queue){
    int tmp = queue->data[queue->front];
    if(queue->size == 0)
        printf("Queue is empty.\n");
    else{
        if(queue->front == MAX_QUEUE_SIZE - 1)
            queue->front = 0;
        else
            queue->front++;
        queue->size--;
    }
    return tmp;
}

void printQueue(Queue queue){
    int i;
    if(queue.size == 0)
        printf("Queue is empty.\n");
    else{
        printf("Front -> ");
        for(i = 0; i < queue.size; i++){
            printf("%d -> ", queue.data[(queue.front + i) % MAX_QUEUE_SIZE]);
        }
        printf("Rear\n");
    }
}

int main(){
    Queue q = {0, 0, 0, {0}};
    int choice, newItem, tmp;

    do{
        printf("Enter 1 to Enqueue\n");
        printf("Enter 2 to Dequeue\n");
        printf("Enter 3 to Quit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter item to Enqueue: ");
                scanf("%d", &newItem);
                enqueue(&q, newItem);
                printQueue(q);
                break;
            case 2:
                tmp = dequeue(&q);
                printf("Dequeued item is %d\n", tmp);
                printQueue(q);
                break;
            case 3:
                printf("Goodbye!");
                break;
            default:
                printf("Invalid choice, please enter again.\n");
        }
    } while(choice != 3);

    return 0;
}