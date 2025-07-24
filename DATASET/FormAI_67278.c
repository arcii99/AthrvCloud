//FormAI DATASET v1.0 Category: Queue Implementation ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
 
#define MAX_QUEUE_SIZE 10
 
// define the player structure
typedef struct {
    char name[20];
    int score;
} Player;
 
// define the queue structure
typedef struct {
    Player data[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int size;
} Queue;
 
// function prototypes
void init(Queue* q);
int isFull(Queue* q);
int isEmpty(Queue* q);
void enqueue(Queue* q, Player player);
Player dequeue(Queue* q);
void display(Queue* q);

// function to initialize the queue
void init(Queue* q) {
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

// function to check if the queue is full
int isFull(Queue* q) {
    return q->size == MAX_QUEUE_SIZE;
}

// function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->size == 0;
}

// function to add a player to the queue
void enqueue(Queue* q, Player player) {
    if(isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if(q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = player;
    q->size++;
}

// function to remove a player from the queue
Player dequeue(Queue* q) {
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        Player player = {"", -1};
        return player;
    }
    Player player = q->data[q->front];
    if(q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    }
    q->size--;
    return player;
}

// function to display the queue
void display(Queue* q) {
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    int i;
    for(i = q->front; i != q->rear; i = (i + 1) % MAX_QUEUE_SIZE) {
        printf("%s(%d) ", q->data[i].name, q->data[i].score);
    }
    printf("%s(%d)\n", q->data[i].name, q->data[i].score);
}
 
// main function
int main() {
    Queue q;
    init(&q);
    
    // create some players
    Player p1 = {"Alice", 100};
    Player p2 = {"Bob", 200};
    Player p3 = {"Charlie", 300};
    Player p4 = {"David", 400};
    Player p5 = {"Eva", 500};
    
    // add some players to the queue
    enqueue(&q, p1);
    printf("Add player %s\n", p1.name);
    display(&q);
    enqueue(&q, p2);
    printf("Add player %s\n", p2.name);
    display(&q);
    enqueue(&q, p3);
    printf("Add player %s\n", p3.name);
    display(&q);
    
    // remove some players from the queue
    Player p = dequeue(&q);
    printf("Remove player %s\n", p.name);
    display(&q);
    p = dequeue(&q);
    printf("Remove player %s\n", p.name);
    display(&q);
    
    // add some more players to the queue
    enqueue(&q, p4);
    printf("Add player %s\n", p4.name);
    display(&q);
    enqueue(&q, p5);
    printf("Add player %s\n", p5.name);
    display(&q);
    
    return 0;
}