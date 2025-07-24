//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>

//defining the structure node
struct node{
    int data;
    struct node *next;
};

//defining the structure queue
struct queue{
    struct node *front;
    struct node *rear;
};

//function to create an empty queue
struct queue *createQueue(){
    struct queue *Q;
    Q = (struct queue*)malloc(sizeof(struct queue));
    if(!Q) return NULL;
    Q->front = Q->rear = NULL;
    return Q;
}

//function to check if queue is empty
int isEmptyQueue(struct queue *Q){
    return(Q->front == NULL);
}

//function to insert data into the queue
void enqueue(struct queue *Q, int data){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if(Q->rear){
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
    else{
        Q->front = Q->rear = newNode;
    }
    printf("Inserted %d into the queue.\n", data);
}

//function to remove data from the queue
int dequeue(struct queue *Q){
    int data;
    struct node *temp;
    if(isEmptyQueue(Q)){
        printf("Queue is empty.\n");
        return 0;
    }
    else{
        temp = Q->front;
        data = Q->front->data;
        Q->front = Q->front->next;
        free(temp);
        if(Q->front == NULL){
            Q->rear == NULL;
        }
        printf("Removed %d from the queue.\n", data);
        return data;
    }
}

//function to get the front of the queue
int front(struct queue *Q){
    if(isEmptyQueue(Q)){
        printf("Queue is empty.\n");
        return 0;
    }
    else{
        return Q->front->data;
    }
}

//function to get the rear of the queue
int rear(struct queue *Q){
    if(isEmptyQueue(Q)){
        printf("Queue is empty.\n");
        return 0;
    }
    else{
        return Q->rear->data;
    }
}

//main function to test the queue
int main(){
    int data, choice;
    struct queue *Q;
    Q = createQueue();
    printf("Queue created successfully.\n");
    while(1){
        printf("1. Enqueue\n2. Dequeue\n3. Front\n4. Rear\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                enqueue(Q, data);
                break;
            case 2:
                dequeue(Q);
                break;
            case 3:
                printf("Front of the queue: %d\n", front(Q));
                break;
            case 4:
                printf("Rear of the queue: %d\n", rear(Q));
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}