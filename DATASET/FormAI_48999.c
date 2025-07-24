//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_BAGGAGE 50 //Maximum baggage allowed in the system
#define MAX_QUEUE 20 //Maximum number of bags that can queue up before moving them to conveyor
#define CONVEYOR_SPEED 2000 //Speed of the conveyor belt in millisecond
#define SECURITY_SCAN_TIME 3000 //Time taken to scan one bag at security checkpoint
#define DESTINATION_SCAN_TIME 2000 //Time taken to scan one bag at destination point

struct Baggage{
    int id;
    char* origin;
    char* destination;
    int weight;
    int scanned;
};

struct Node{
    struct Baggage* bag;
    struct Node* next;
};

struct Queue{
    int size;
    struct Node* front;
    struct Node* rear;
};

void initQueue(struct Queue* q){
    q->size = 0;
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(struct Queue* q){
    return q->size == 0;
}

void enqueue(struct Queue* q, struct Baggage* b){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->bag = b;
    newNode->next = NULL;
    if(isEmpty(q)){
        q->front = newNode;
        q->rear = newNode;
    }else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

struct Baggage* dequeue(struct Queue* q){
    if(isEmpty(q)){
        printf("\nQueue is empty!");
        return NULL;
    }
    struct Node* temp = q->front;
    struct Baggage* b = temp->bag;
    q->front = q->front->next;
    if(q->front == NULL || q->size == 1){
        q->rear = NULL;
    }
    q->size--;
    free(temp);
    return b;
}

void displayBaggage(struct Baggage* b){
    printf("\n[ID] %d [Origin] %s [Destination] %s [Weight] %d kg", b->id, b->origin, b->destination, b->weight);
}

void displayConveyorBelt(struct Baggage* conveyorBelt[], int n){
    printf("\n---CONVEYOR BELT---");
    for(int i = 0; i < n; i++){
        if(conveyorBelt[i] != NULL){
            displayBaggage(conveyorBelt[i]);
        }else{
            printf("\n[ ] Empty slot");
        }
    }
}

void moveBagsToConveyor(struct Queue* q, struct Baggage* conveyorBelt[], int n){
    printf("\nMoving bags to conveyor belt...");
    for(int i = 0; i < n; i++){
        if(conveyorBelt[i] == NULL){
            if(isEmpty(q)){
                break;
            }
            conveyorBelt[i] = dequeue(q);
        }
    }
    displayConveyorBelt(conveyorBelt, n);
}

int scanBags(struct Baggage* conveyorBelt[], int n, int scanTime){
    int scannedBags = 0;
    for(int i = 0; i < n; i++){
        if(conveyorBelt[i] != NULL && conveyorBelt[i]->scanned == 0){
            printf("\nScanning bag with ID: %d", conveyorBelt[i]->id);
            conveyorBelt[i]->scanned = 1;
            scannedBags++;
            sleep(scanTime/1000);
            printf("\nScanning complete for bag with ID: %d", conveyorBelt[i]->id);
        }
    }
    return scannedBags;
}

void removeBag(struct Baggage* conveyorBelt[], int n, int index){
    free(conveyorBelt[index]);
    conveyorBelt[index] = NULL;
}

void moveBagsToDestination(struct Baggage* conveyorBelt[], int n){
    printf("\nMoving bags from conveyor belt to destination...");
    for(int i = 0; i < n; i++){
        if(conveyorBelt[i] != NULL){
            displayBaggage(conveyorBelt[i]);
            removeBag(conveyorBelt, n, i);
            printf("\nBag with ID %d has reached its destination.", conveyorBelt[i]->id);
        }
    }
}

void displayMenu(){
    printf("\n--------- MENU ---------");
    printf("\n1. Add bags to the system");
    printf("\n2. Move bags to conveyor belt");
    printf("\n3. Scan bags at security checkpoint");
    printf("\n4. Move bags to destination");
    printf("\n5. Exit");
}

int main(){
    struct Queue baggageQueue;
    initQueue(&baggageQueue);
    struct Baggage* conveyorBelt[MAX_QUEUE]; //Creating an array of pointers to Baggage struct
    memset(conveyorBelt, NULL, sizeof(conveyorBelt)); //Initializing all the pointers to NULL

    int choice, id, weight;
    char origin[30], destination[30];
    struct Baggage* newBaggage;
    int countBags = 0; //Count of bags added to the system
    int scannedBags = 0; //Count of bags scanned at security checkpoint

    do{
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter the origin airport: ");
                scanf("%s", origin);
                printf("Enter the destination airport: ");
                scanf("%s", destination);
                printf("Enter the weight of the bag (in kgs): ");
                scanf("%d", &weight);
                newBaggage = (struct Baggage*)malloc(sizeof(struct Baggage));
                newBaggage->id = ++countBags;
                newBaggage->origin = (char*)malloc(strlen(origin) + 1);
                strcpy(newBaggage->origin, origin);
                newBaggage->destination = (char*)malloc(strlen(destination) + 1);
                strcpy(newBaggage->destination, destination);
                newBaggage->weight = weight;
                newBaggage->scanned = 0;
                enqueue(&baggageQueue, newBaggage);
                displayBaggage(newBaggage);
                break;

            case 2:
                moveBagsToConveyor(&baggageQueue, conveyorBelt, MAX_QUEUE);
                break;

            case 3:
                scannedBags += scanBags(conveyorBelt, MAX_QUEUE, SECURITY_SCAN_TIME);
                break;

            case 4:
                moveBagsToDestination(conveyorBelt, MAX_QUEUE);
                break;

            case 5:
                printf("\nExiting...");
                break;

            default:
                printf("\nInvalid choice!");
        }

    }while(choice != 5);

    printf("\nTotal bags added: %d", countBags);
    printf("\nNumber of bags scanned: %d", scannedBags);
    return 0;
}