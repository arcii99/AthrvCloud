//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct bag {
    int id; // unique identifier for each bag
    char destination[3]; // 3-letter airport code
    bool infected; // flag to indicate if bag is contaminated with virus
} bag;

typedef struct conveyor_belt {
    int size; // number of bags the conveyor belt can hold
    int num_bags; // number of bags currently on the conveyor belt
    bag **bags; // array of bag pointers
} conveyor_belt;

typedef struct plane {
    char destination[3]; // 3-letter airport code
    conveyor_belt *belt; // conveyor belt object for this plane
} plane;

typedef struct airport {
    char code[3]; // 3-letter airport code
    conveyor_belt *belt; // conveyor belt object for this airport
} airport;

void move_bags(conveyor_belt *from, conveyor_belt *to) {
    int i, j;
    for (i = 0; i < from->num_bags; i++) {
        bool can_move = true;
        if (from->bags[i]->infected) {
            printf("Bag %d is infected, cannot move to destination\n", from->bags[i]->id);
            can_move = false;
        }
        if (can_move) {
            // move bag to destination conveyor belt
            to->bags[to->num_bags] = from->bags[i];
            to->num_bags++;
            // remove bag from origin conveyor belt
            for (j = i+1; j < from->num_bags; j++) {
                from->bags[j-1] = from->bags[j];
            }
            from->num_bags--;
            i--;
        }
    }
}

void check_infected_bags(conveyor_belt *belt, plane *plane) {
    int i;
    for (i = 0; i < belt->num_bags; i++) {
        if (belt->bags[i]->destination == plane->destination) {
            belt->bags[i]->infected = true;
            printf("Bag %d is contaminated with virus\n", belt->bags[i]->id);
        }
    }
}

int main() {
    srand(time(NULL));
    // create airports and planes
    airport atlanta = {"ATL", NULL};
    airport chicago = {"ORD", NULL};
    airport new_york = {"JFK", NULL};
    plane plane1 = {"ORD", NULL};
    plane1.belt = (conveyor_belt*)malloc(sizeof(conveyor_belt));
    plane1.belt->size = 20;
    plane1.belt->num_bags = 0;
    plane1.belt->bags = (bag**)malloc(sizeof(bag*)*plane1.belt->size);
    plane plane2 = {"JFK", NULL};
    plane2.belt = (conveyor_belt*)malloc(sizeof(conveyor_belt));
    plane2.belt->size = 20;
    plane2.belt->num_bags = 0;
    plane2.belt->bags = (bag**)malloc(sizeof(bag*)*plane2.belt->size);
    // create conveyor belts for airports
    atlanta.belt = (conveyor_belt*)malloc(sizeof(conveyor_belt));
    atlanta.belt->size = 20;
    atlanta.belt->num_bags = 0;
    atlanta.belt->bags = (bag**)malloc(sizeof(bag*)*atlanta.belt->size);
    chicago.belt = (conveyor_belt*)malloc(sizeof(conveyor_belt));
    chicago.belt->size = 20;
    chicago.belt->num_bags = 0;
    chicago.belt->bags = (bag**)malloc(sizeof(bag*)*chicago.belt->size);
    new_york.belt = (conveyor_belt*)malloc(sizeof(conveyor_belt));
    new_york.belt->size = 20;
    new_york.belt->num_bags = 0;
    new_york.belt->bags = (bag**)malloc(sizeof(bag*)*new_york.belt->size);
    // load bags onto airport conveyor belts
    int i;
    for (i = 0; i < atlanta.belt->size; i++) {
        atlanta.belt->bags[i] = (bag*)malloc(sizeof(bag));
        atlanta.belt->bags[i]->id = i+1;
        atlanta.belt->bags[i]->infected = false;
        sprintf(atlanta.belt->bags[i]->destination, "ORD");
        atlanta.belt->num_bags++;
    }
    for (i = 0; i < chicago.belt->size; i++) {
        chicago.belt->bags[i] = (bag*)malloc(sizeof(bag));
        chicago.belt->bags[i]->id = i+1+atlanta.belt->size;
        chicago.belt->bags[i]->infected = false;
        sprintf(chicago.belt->bags[i]->destination, "JFK");
        chicago.belt->num_bags++;
    }
    for (i = 0; i < new_york.belt->size; i++) {
        new_york.belt->bags[i] = (bag*)malloc(sizeof(bag));
        new_york.belt->bags[i]->id = i+1+atlanta.belt->size+chicago.belt->size;
        new_york.belt->bags[i]->infected = false;
        sprintf(new_york.belt->bags[i]->destination, "ATL");
        new_york.belt->num_bags++;
    }
    // simulate baggage handling
    int time = 0;
    while (plane1.belt->num_bags < plane1.belt->size || plane2.belt->num_bags < plane2.belt->size) {
        time++;
        printf("Time %d:\n", time);
        // check for infected bags
        check_infected_bags(atlanta.belt, &plane1);
        check_infected_bags(chicago.belt, &plane1);
        check_infected_bags(new_york.belt, &plane2);
        // move bags to correct destination
        move_bags(atlanta.belt, &chicago.belt);
        move_bags(chicago.belt, &plane1.belt);
        move_bags(new_york.belt, &atlanta.belt);
        move_bags(atlanta.belt, &plane2.belt);
        move_bags(chicago.belt, &new_york.belt);
        // randomly generate new bags
        int num_new_bags = rand() % (atlanta.belt->size + chicago.belt->size + new_york.belt->size);
        for (i = 0; i < num_new_bags; i++) {
            int n = rand() % 3; // choose random airport
            airport *a;
            switch (n) {
                case 0: a = &atlanta; break;
                case 1: a = &chicago; break;
                case 2: a = &new_york; break;
            }
            if (a->belt->num_bags < a->belt->size) {
                a->belt->bags[a->belt->num_bags] = (bag*)malloc(sizeof(bag));
                a->belt->bags[a->belt->num_bags]->id = time*1000+i+1;
                a->belt->bags[a->belt->num_bags]->infected = false;
                sprintf(a->belt->bags[a->belt->num_bags]->destination, "%s", (n == 0) ? "JFK" : ((n == 1) ? "ATL" : "ORD"));
                a->belt->num_bags++;
            }
        }
        printf("\n");
    }
    return 0;
}