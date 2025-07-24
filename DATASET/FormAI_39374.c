//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// a structure to represent the baggage
typedef struct {
    int id;
    int weight;
} Baggage;

// a structure to represent the conveyor belt
typedef struct {
    Baggage* bag_arr[100];
    int front, rear;
} ConveyorBelt;

// a function to add a baggage to the conveyor belt
void add_baggage(ConveyorBelt* cb_ptr, Baggage* bg_ptr) {
    if (cb_ptr->rear == 99)
        printf("Conveyor belt is full\n");
    else {
        cb_ptr->rear++;
        cb_ptr->bag_arr[cb_ptr->rear] = bg_ptr;
        printf("Baggage with id %d and weight %d added to the conveyor belt\n",
                bg_ptr->id, bg_ptr->weight);
    }
}

// a function to remove the top baggage from the conveyor belt
Baggage* remove_baggage(ConveyorBelt* cb_ptr) {
    if (cb_ptr->rear < cb_ptr->front) {
        printf("Conveyor belt is empty\n");
        return NULL;
    }
    else {
        cb_ptr->front++;
        printf("Baggage with id %d and weight %d removed from the conveyor belt\n",
                cb_ptr->bag_arr[cb_ptr->front]->id,
                cb_ptr->bag_arr[cb_ptr->front]->weight);
        return cb_ptr->bag_arr[cb_ptr->front];
    }
}

// a function to display all the baggage on the conveyor belt
void display_conveyor_belt(ConveyorBelt cb) {
    if (cb.rear < cb.front)
        printf("Conveyor belt is empty\n");
    else {
        printf("Baggage on the conveyor belt:\n");
        for (int i = cb.front + 1; i <= cb.rear; i++)
            printf("Id: %d, Weight: %d\n", cb.bag_arr[i]->id, cb.bag_arr[i]->weight);
    }
}

int main() {
    ConveyorBelt cb;            // declaring a conveyor belt
    cb.front = -1;
    cb.rear = -1;

    // creating some baggage
    Baggage b1 = { 101, 20 };
    Baggage b2 = { 102, 15 };
    Baggage b3 = { 103, 30 };
    Baggage b4 = { 104, 10 };
    Baggage b5 = { 105, 25 };
    Baggage b6 = { 106, 18 };

    // adding the baggage to the conveyor belt
    add_baggage(&cb, &b1);
    add_baggage(&cb, &b2);
    add_baggage(&cb, &b3);
    add_baggage(&cb, &b4);
    add_baggage(&cb, &b5);
    add_baggage(&cb, &b6);

    // displaying the baggage on the conveyor belt
    display_conveyor_belt(cb);

    // removing some baggage from the conveyor belt
    remove_baggage(&cb);
    remove_baggage(&cb);

    // displaying the baggage on the conveyor belt again
    display_conveyor_belt(cb);

    return 0;
}