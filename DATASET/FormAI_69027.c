//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: introspective
#include <stdlib.h>  
#include <stdio.h>  
#include <pthread.h>  
#include <semaphore.h> 

#define MAX_LUGGAGE_ITEMS 10
#define MAX_CONVEYOR_BELTS 2

int luggage_items[MAX_LUGGAGE_ITEMS];
sem_t empty_spaces[MAX_CONVEYOR_BELTS];
sem_t fill_spaces[MAX_CONVEYOR_BELTS];

// Thread function that generates luggage items and puts them on the conveyor belts
void *generate_luggage(void *conveyor_belt) {
    int *board = (int*)conveyor_belt;
    while(1) {
        int luggage_item = rand() % 1000 + 1;
        printf("Generated luggage item: %d\n", luggage_item);
        sem_wait(&empty_spaces[*board]);

        // Critical section
        luggage_items[(*board)*MAX_LUGGAGE_ITEMS + luggage_items[*board]] = luggage_item;
        luggage_items[*board]++;
        printf("Put luggage item %d on conveyor belt %d\n", luggage_item, *board);
        
        sem_post(&fill_spaces[*board]);
        int sleep_time = rand() % 5 + 1;
        sleep(sleep_time);
    }
}

// Thread function that picks up luggage items from the conveyor belts and puts them on the airplane
void *pick_up_luggage(void *conveyor_belt) {
    int *board = (int*)conveyor_belt;
    while(1) {
        sem_wait(&fill_spaces[*board]);

        // Critical section
        int picked_item = luggage_items[(*board)*MAX_LUGGAGE_ITEMS];
        luggage_items[(*board)*MAX_LUGGAGE_ITEMS] = 0;
        luggage_items[*board]--;
        printf("Picked up luggage item %d from conveyor belt %d\n", picked_item, *board);

        sem_post(&empty_spaces[*board]);
        int sleep_time = rand() % 5 + 1;
        sleep(sleep_time);
    }
}

int main() {
    srand(time(NULL));
    pthread_t generators[MAX_CONVEYOR_BELTS], pickers[MAX_CONVEYOR_BELTS];
    int boards[MAX_CONVEYOR_BELTS];
    for(int i = 0; i < MAX_CONVEYOR_BELTS; i++) {
        boards[i] = i;
        sem_init(&empty_spaces[i], 0, MAX_LUGGAGE_ITEMS);
        sem_init(&fill_spaces[i], 0, 0);
    }

    for(int i = 0; i < MAX_CONVEYOR_BELTS; i++) {
        pthread_create(&generators[i], NULL, generate_luggage, &boards[i]);
        pthread_create(&pickers[i], NULL, pick_up_luggage, &boards[i]);
    }

    for(int i = 0; i < MAX_CONVEYOR_BELTS; i++) {
        pthread_join(generators[i], NULL);
        pthread_join(pickers[i], NULL);
    }

    for(int i = 0; i < MAX_CONVEYOR_BELTS; i++) {
        sem_destroy(&empty_spaces[i]);
        sem_destroy(&fill_spaces[i]);
    }
    return 0;
}