//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_BAGS 100 //maximum number of bags in the system

typedef struct Bag{ //structure to store bag information
    int id;
    int weight;
    int destination;
    int arrivalTime;
    int departureTime;
    int expectedDepartureTime;
    int checkInTime;
} Bag_t;

typedef struct Queue{ //structure to implement the queue data structure
    Bag_t bags[MAX_BAGS];
    int front;
    int rear;
} Queue_t;

Queue_t checkInQueue;
Queue_t securityQueue;
Queue_t baggageClaimQueue;

int currentTime = 0;
int totalWeight = 0;
int totalCheckedBags = 0;
int totalMissedFlights = 0;

void initialize(Queue_t* q){ //initialize a queue
    q->front = q->rear = -1;
}

int isEmpty(Queue_t* q){ //check if queue is empty
    return (q->front == -1);
}

int isFull(Queue_t* q){ //check if queue is full
    return (q->rear == MAX_BAGS - 1);
}

void enqueue(Queue_t* q, Bag_t bag){ //add a bag to the queue
    if (isFull(q)){
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)){
        q->front = q->rear = 0;
    }
    else{
        q->rear++;
    }
    q->bags[q->rear] = bag;
}

void dequeue(Queue_t* q){ //remove a bag from the queue
    if (isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    if (q->front == q->rear){
        q->front = q->rear = -1;
    }
    else{
        q->front++;
    }
}

Bag_t front(Queue_t* q){ //return the front bag in the queue
    if (isEmpty(q)){
        printf("Queue is empty\n");
        exit(1);
    }
    return q->bags[q->front];
}

int size(Queue_t* q){ //return the number of bags in the queue
    if (isEmpty(q)){
        return 0;
    }
    return q->rear - q->front + 1;
}

void printQueue(Queue_t* q){ //print the bags in the queue
    if (isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    printf("Bags in the queue:\n");
    for (int i = q->front; i <= q->rear; i++){
        printf("Bag %d: Weight = %d, Destination = %d\n", q->bags[i].id, q->bags[i].weight, q->bags[i].destination);
    }
}

int generateRandomNumber(int min, int max){ //generate a random integer between min and max
    return (rand() % (max - min + 1)) + min;
}

void generateBags(){ //generate bags at check-in counter
    int numOfBags = generateRandomNumber(1, 5);
    for (int i = 1; i <= numOfBags; i++){
        Bag_t bag;
        bag.id = totalCheckedBags + i;
        bag.weight = generateRandomNumber(5, 50);
        bag.destination = generateRandomNumber(1, 3);
        bag.arrivalTime = currentTime;
        bag.expectedDepartureTime = generateRandomNumber(30, 180);
        bag.checkInTime = currentTime;
        totalWeight += bag.weight;
        totalCheckedBags++;
        enqueue(&checkInQueue, bag);
    }
}

void checkIn(){ //check in bags at the check-in counter
    if (isEmpty(&checkInQueue)){
        return;
    }
    Bag_t bag = front(&checkInQueue);
    if (currentTime - bag.checkInTime >= 10){
        printf("Bag %d has been at check-in for too long and missed its flight\n", bag.id);
        totalMissedFlights++;
        dequeue(&checkInQueue);
        return;
    }
    if (currentTime >= bag.expectedDepartureTime){
        printf("Bag %d missed its flight\n", bag.id);
        totalMissedFlights++;
        dequeue(&checkInQueue);
        return;
    }
    if (size(&securityQueue) < 10){
        dequeue(&checkInQueue);
        enqueue(&securityQueue, bag);
    }
}

void securityCheck(){ //perform security check on bags
    if (isEmpty(&securityQueue)){
        return;
    }
    Bag_t bag = front(&securityQueue);
    if (currentTime - bag.checkInTime >= 30){
        printf("Bag %d has been at security check for too long and missed its flight\n", bag.id);
        totalMissedFlights++;
        dequeue(&securityQueue);
        return;
    }
    if (currentTime >= bag.expectedDepartureTime){
        printf("Bag %d missed its flight\n", bag.id);
        totalMissedFlights++;
        dequeue(&securityQueue);
        return;
    }
    dequeue(&securityQueue);
    enqueue(&baggageClaimQueue, bag);
}

void baggageClaim(){ //return bags to passengers at baggage claim
    if (isEmpty(&baggageClaimQueue)){
        return;
    }
    Bag_t bag = front(&baggageClaimQueue);
    if (currentTime - bag.arrivalTime >= 60){
        printf("Bag %d has been at baggage claim for too long\n", bag.id);
        totalMissedFlights++;
        dequeue(&baggageClaimQueue);
        return;
    }
    dequeue(&baggageClaimQueue);
    totalWeight -= bag.weight;
}

void printStatistics(){ //print statistics of the simulation
    printf("Total checked bags: %d\n", totalCheckedBags);
    printf("Total weight of checked bags: %d\n", totalWeight);
    printf("Total missed flights: %d\n", totalMissedFlights);
}

int main(){
    srand(time(0));
    initialize(&checkInQueue);
    initialize(&securityQueue);
    initialize(&baggageClaimQueue);
    while (currentTime <= 600){ //run the simulation for 10 hours
        generateBags();
        checkIn();
        securityCheck();
        baggageClaim();
        currentTime++;
    }
    printStatistics();
    return 0;
}