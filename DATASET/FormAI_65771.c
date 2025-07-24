//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_LUGGAGE 100
#define MAX_WEIGHT 50
#define MAX_BAGGAGE_COUNT 10
#define MAX_NAME_LEN 20
#define MAX_STATUS_LEN 30

struct Baggage {
    int id;
    int weight;
    char name[MAX_NAME_LEN];
    char status[MAX_STATUS_LEN];
};

struct BaggageBag {
    int count;
    struct Baggage baggage[MAX_BAGGAGE_COUNT];
};

void display_bag(struct Baggage bag) {
    printf("ID: %d | Name: %s | Weight: %d kg | Status: %s\n",
        bag.id, bag.name, bag.weight, bag.status);
}

void display_baggage(struct BaggageBag baggage_bag) {
    int i;
    printf("Number of Baggage: %d\n", baggage_bag.count);
    for (i = 0; i < baggage_bag.count; i++) {
        display_bag(baggage_bag.baggage[i]);
    }
}

void init_baggage_bag(struct BaggageBag *baggage_bag) {
    baggage_bag->count = 0;
}

int add_baggage(struct Baggage *baggage, struct BaggageBag *baggage_bag) {
    if (baggage_bag->count == MAX_BAGGAGE_COUNT) {
        printf("Baggage bag is full. Cannot add more baggage.\n");
        return 0;
    }
    baggage_bag->baggage[baggage_bag->count] = *baggage;
    baggage_bag->count++;
    return 1;
}

void display_status_message(struct Baggage baggage, char *status) {
    printf("Baggage ID %d: %s - %s\n", baggage.id, baggage.name, status);
}

void move_baggage_to_conveyor_belt(struct Baggage *baggage, struct BaggageBag *baggage_bag) {
    srand(time(0));
    int delay = rand() % 3 + 1; // Random time for delay in seconds
    printf("Moving Baggage ID %d to Conveyor Belt...\n", baggage->id);
    printf("Waiting for %d seconds...\n", delay);
    sleep(delay);
    strcpy(baggage->status, "On Conveyor Belt");
    display_status_message(*baggage, baggage->status);
}

void move_baggage_to_aircraft(struct Baggage *baggage, struct BaggageBag *baggage_bag) {
    srand(time(0));
    int delay = rand() % 3 + 1; // Random time for delay in seconds
    printf("Moving Baggage ID %d to Aircraft...\n", baggage->id);
    printf("Waiting for %d seconds...\n", delay);
    sleep(delay);
    strcpy(baggage->status, "On Aircraft");
    display_status_message(*baggage, baggage->status);
}

void check_in_baggage(struct Baggage *baggage, struct BaggageBag *baggage_bag) {
    int i;
    for (i = 0; i < MAX_LUGGAGE; i++) {
        baggage->id = i + 1;
        printf("Adding Baggage ID %d...\n", baggage->id);
        baggage->weight = rand() % MAX_WEIGHT + 1;
        sprintf(baggage->name, "Baggage %d", baggage->id);
        strcpy(baggage->status, "At Check-In Counter");
        display_bag(*baggage);
        add_baggage(baggage, baggage_bag);
    }

    printf("\nDisplaying All Baggage:\n");
    display_baggage(*baggage_bag);

    printf("\nMoving Baggage to Conveyor Belt:\n");
    for (i = 0; i < baggage_bag->count; i++) {
        move_baggage_to_conveyor_belt(&baggage_bag->baggage[i], baggage_bag);
    }

    printf("\nMoving Baggage to Aircraft:\n");
    for (i = 0; i < baggage_bag->count; i++) {
        move_baggage_to_aircraft(&baggage_bag->baggage[i], baggage_bag);
    }

    printf("\nDisplaying All Baggage:\n");
    display_baggage(*baggage_bag);
}

int main(void) {
    struct BaggageBag baggage_bag;
    struct Baggage baggage;
    init_baggage_bag(&baggage_bag);
    check_in_baggage(&baggage, &baggage_bag);
    printf("Simulation Completed.\n");
    return 0;
}