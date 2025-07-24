//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_BELT_SIZE 10

typedef struct {
    int bag_id;
    int gate;
} Baggage;

typedef struct {
    Baggage contents[MAX_BELT_SIZE];
    int head;
    int tail;
    int count;
} Belt;

// Function declarations
void init_belt(Belt *b);
int add_bag(Belt *b, Baggage bag);
int remove_bag(Belt *b);

int main() {
    Belt belt;
    init_belt(&belt);
    srand(time(NULL)); // Seed random number generator
    
    // Simulate baggage handling
    for (int i = 0; i < MAX_BAGS; i++) {
        int gate = rand() % 5 + 1;
        Baggage bag = { i + 1, gate };
        int result = add_bag(&belt, bag);
        
        if (result == 0) {
            printf("Bag %d sent to gate %d\n", bag.bag_id, bag.gate);
        } else if (result == -1) {
            printf("Belt full, delaying flight!\n");
            break;
        }
    }
    
    // Empty remaining bags from belt
    while (belt.count > 0) {
        remove_bag(&belt);
    }
    
    return 0;
}

void init_belt(Belt *b) {
    b->head = 0;
    b->tail = 0;
    b->count = 0;
}

int add_bag(Belt *b, Baggage bag) {
    if (b->count == MAX_BELT_SIZE) {
        return -1; // Belt full
    }
    
    b->contents[b->tail] = bag;
    b->tail = (b->tail + 1) % MAX_BELT_SIZE;
    b->count++;
    
    return 0;
}

int remove_bag(Belt *b) {
    if (b->count == 0) {
        return -1; // Belt empty
    }
    
    Baggage bag = b->contents[b->head];
    b->head = (b->head + 1) % MAX_BELT_SIZE;
    b->count--;
    
    printf("Bag %d arrived at gate %d\n", bag.bag_id, bag.gate);
    
    return 0;
}