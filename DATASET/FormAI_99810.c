//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: future-proof
// C Airport Baggage Handling Simulation

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 50

typedef struct {
    int bag_ID;
    int weight;
    char dest[50];
} Baggage;

Baggage baggage_queue[MAX_BAGS];
int front = -1, rear = -1;

void enqueue(Baggage new_baggage) {
    if(rear == MAX_BAGS - 1) {
        printf("Baggage queue is full.\n");
        return;
    }
    if(front == -1) front++;
    rear++;
    baggage_queue[rear] = new_baggage;
    printf("Baggage %d added to queue. Destination: %s.\n", new_baggage.bag_ID, new_baggage.dest);
}

Baggage dequeue() {
    if(front > rear || front == -1) {
        Baggage empty = {-1, -1, ""};
        printf("All baggage has been processed.\n");
        return empty;
    }
    Baggage current_bag = baggage_queue[front];
    printf("Processing baggage %d...\n", current_bag.bag_ID);
    front++;
    return current_bag;
}

void simulate_baggage_handler() {
    srand(time(NULL));
    for(int i = 1; i <= MAX_BAGS; i++) {
        Baggage new_bag;
        new_bag.bag_ID = i;
        new_bag.weight = rand() % 50 + 1;
        int dest_choice = rand() % 3;
        switch(dest_choice) {
            case 0:
                sprintf(new_bag.dest, "New York");
                break;
            case 1:
                sprintf(new_bag.dest, "Paris");
                break;
            case 2:
                sprintf(new_bag.dest, "Tokyo");
                break;
            default:
                sprintf(new_bag.dest, "Unknown");
                break;
        }
        enqueue(new_bag);
        int process_time = rand() % 3 + 1;
        for(int j = 0; j < process_time; j++) {
            dequeue();
        }
    }
}

int main() {
    simulate_baggage_handler();
    return 0;
}