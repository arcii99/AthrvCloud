//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CAPACITY 10 //Maximum capacity of the conveyor belt
#define MAX_BAG_WEIGHT 20 //Maximum weight of a bag
#define MAX_LUGGAGE 50 //Maximum number of bags in the system

//Structures
struct Bag {
    int weight;
    char flight_number[15];
};

struct ConveyorBelt {
    int capacity;
    int current_load;
    struct Bag bags[MAX_CAPACITY];
};

//Function prototypes
void add_baggage(struct ConveyorBelt *cb, int weight, char *flight_number);
void remove_baggage(struct ConveyorBelt *cb, int index);
void display_conveyor_belt(struct ConveyorBelt *cb);

int main() {

    struct ConveyorBelt cb = {
        .capacity = MAX_CAPACITY,
        .current_load = 0,
    };
    
    //Step 1: Adding bags to the conveyor belt
    add_baggage(&cb, 10, "AK456");
    add_baggage(&cb, 15, "UA123");
    add_baggage(&cb, 18, "AA098");
    add_baggage(&cb, 12, "DL759");
    add_baggage(&cb, 20, "BA673");
    add_baggage(&cb, 16, "LH890");
    add_baggage(&cb, 10, "AF234");
    add_baggage(&cb, 11, "AC345");
    add_baggage(&cb, 19, "KL678");
    add_baggage(&cb, 14, "AF345");

    //Step 2: Displaying the conveyor belt status
    printf("Conveyor Belt Status:\n");
    display_conveyor_belt(&cb);

    //Step 3: Removing bags with flight number starting with "A"
    for (int i = 0; i < cb.current_load; i++) {
        if (cb.bags[i].flight_number[0] == 'A') {
            remove_baggage(&cb, i);
            i--;
        }
    }

    //Step 4: Displaying the updated conveyor belt status
    printf("Updated Conveyor Belt Status:\n");
    display_conveyor_belt(&cb);

    return 0;
}

//Function to add baggage to the conveyor belt
void add_baggage(struct ConveyorBelt *cb, int weight, char *flight_number) {
    if (cb->current_load >= MAX_CAPACITY) {
        printf("Conveyor belt is full. Baggage cannot be added.\n");
        return;
    }

    if (weight > MAX_BAG_WEIGHT) {
        printf("Bag weight exceeds maximum limit. Baggage cannot be added.\n");
        return;
    }

    struct Bag bag = {
        .weight = weight,
    };

    for (int i = 0; i < strlen(flight_number); i++) {
        bag.flight_number[i] = flight_number[i];
    }

    cb->bags[cb->current_load++] = bag;
    printf("Baggage added successfully to the conveyor belt.\n");
}

//Function to remove baggage from the conveyor belt
void remove_baggage(struct ConveyorBelt *cb, int index) {
    if (index >= cb->current_load) {
        printf("Invalid index. Baggage cannot be removed.\n");
        return;
    }

    printf("Removing baggage with flight number %s from the conveyor belt.\n", cb->bags[index].flight_number);

    for (int i = index; i < cb->current_load; i++) {
        cb->bags[i] = cb->bags[i + 1];
    }
    cb->current_load--;
}

//Function to display the conveyor belt status
void display_conveyor_belt(struct ConveyorBelt *cb) {
    if (cb->current_load == 0) {
        printf("Conveyor belt is empty.\n");
    } else {
        printf("Current load: %d/%d\n", cb->current_load, cb->capacity);
        printf("Bags: ");
        for (int i = 0; i < cb->current_load; i++) {
            printf("[%s, %dkg] ", cb->bags[i].flight_number, cb->bags[i].weight);
        }
        printf("\n");
    }
}