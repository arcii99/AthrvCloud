//FormAI DATASET v1.0 Category: Queue Implementation ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node{
    int data;
    struct node* next;
};

struct queue{
    struct node *front, *rear;
};

struct node* getNode(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct queue* createQueue(){
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct queue* q, int data){
    struct node* temp = getNode(data);
    if(q->rear == NULL){
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

void dequeue(struct queue* q){
    if(q->front == NULL){
        printf("Queue is empty.\n");
        return;
    }
    struct node* temp = q->front;
    q->front = q->front->next;
    if(q->front == NULL){
        q->rear = NULL;
    }
    free(temp);
}

int front(struct queue* q){
    if(q->front == NULL){
        printf("Queue is empty.\n");
        return -1;
    }
    return q->front->data;
}

int rear(struct queue* q){
    if(q->rear == NULL){
        printf("Queue is empty.\n");
        return -1;
    }
    return q->rear->data;
}

void display(struct queue* q){
    struct node* temp = q->front;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct queue* q = createQueue();
    srand(time(NULL));
    printf("Welcome to the Mind-bending Queue Program!\n");
    printf("Initializing the queue with random numbers between 1 and 100...\n");
    for(int i = 0; i < 10; i++){
        int data = rand() % 100 + 1;
        enqueue(q, data);
    }
    printf("Queue contents: ");
    display(q);
    printf("The front element is: %d\n", front(q));
    printf("The rear element is: %d\n", rear(q));
    printf("Removing the front element...\n");
    dequeue(q);
    printf("Queue contents: ");
    display(q);
    printf("Adding a new element to the rear of the queue...\n");
    int data = rand() % 100 + 1;
    enqueue(q, data);
    printf("Queue contents: ");
    display(q);
    printf("The front element is: %d\n", front(q));
    printf("The rear element is: %d\n", rear(q));
    printf("Emptying the queue...\n");
    while(q->front != NULL){
        dequeue(q);
    }
    printf("Queue contents: ");
    display(q);
    printf("Queue empty.\n");
    return 0;
}