//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TOTAL_LUGGAGE 300
#define MAX_CAPACITY 100
#define UNUSED -1

void init_conveyor_belt(int *conveyor_belt, int size) {
    for(int i = 0; i < size; ++i) {
        conveyor_belt[i] = UNUSED;
    }
}

void get_luggage(int *conveyor_belt, int *airplane, int size) {
    int idx = 0;
    while(idx < size && airplane[idx] == UNUSED) {
        int jdx = 0;
        while(jdx < size && conveyor_belt[jdx] != UNUSED) {
            ++jdx;
        }
        if(jdx < size) {
            airplane[idx] = conveyor_belt[jdx];
            printf("Luggage with tag %d loaded in airplane at position %d\n", airplane[idx], idx);
            conveyor_belt[jdx] = UNUSED;
            ++idx;
        }
    }
}

int main() {
    srand(time(NULL));
    int conveyor_belt[MAX_CAPACITY], airplane[MAX_CAPACITY];

    printf("Simulation starting...\n");

    init_conveyor_belt(conveyor_belt, MAX_CAPACITY);
    init_conveyor_belt(airplane, MAX_CAPACITY);

    for(int i = 0; i < TOTAL_LUGGAGE; ++i) {
        int jdx = 0;
        while(jdx < MAX_CAPACITY && conveyor_belt[jdx] != UNUSED) {
            ++jdx;
        }
        if(jdx == MAX_CAPACITY) {
            printf("Conveyor belt is full. Cannot load more luggage.\n");
            break;
        }
        conveyor_belt[jdx] = rand() % 100000;
        printf("Luggage with tag %d loaded on conveyor belt at position %d.\n", conveyor_belt[jdx], jdx);
    }

    get_luggage(conveyor_belt, airplane, MAX_CAPACITY);

    for(int i = 0; i < MAX_CAPACITY; ++i) {
        if(airplane[i] != UNUSED) {
            printf("Luggage with tag %d unloaded from airplane at position %d.\n", airplane[i], i);
        }
    }

    printf("Simulation finished.\n");

    return 0;
}