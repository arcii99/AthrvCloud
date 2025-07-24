//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define FLOORS 10
#define MAX_PEOPLE 5

struct Elevator {
    int current_floor;
    int direction;
    int capacity;
};

struct Person {
    int from_floor;
    int to_floor;
};

pthread_mutex_t elevator_mutex;
pthread_cond_t elevator_serving_condition;
pthread_cond_t elevator_empty_condition;
pthread_cond_t elevator_full_condition;
pthread_cond_t call_condition;

int waiting_people[FLOORS];
int served_people[FLOORS];
struct Person people_list[MAX_PEOPLE] = {{1, 3}, {2, 4}, {3, 2}, {6, 9}, {7, 1}};
struct Elevator elevator = {1, 1, 0};

void *elevator_thread(void *arg) {
    while (1) {
        pthread_mutex_lock(&elevator_mutex);
        if (elevator.capacity > 0) {
            printf("Elevator going to floor %d\n", elevator.direction == 1 ? elevator.current_floor + 1 : elevator.current_floor - 1);
            elevator.current_floor += elevator.direction;
        } else {
            pthread_cond_signal(&elevator_empty_condition);
            pthread_cond_wait(&elevator_serving_condition, &elevator_mutex);
        }

        if (elevator.current_floor == FLOORS) {
            elevator.direction = -1;
        } else if (elevator.current_floor == 1) {
            elevator.direction = 1;
        }

        printf("Elevator at floor %d\n", elevator.current_floor);
        served_people[elevator.current_floor - 1] += elevator.capacity;
        elevator.capacity = 0;

        pthread_cond_broadcast(&call_condition);
        pthread_mutex_unlock(&elevator_mutex);  
    }

    pthread_exit(NULL);
}

void *person_thread(void *arg) {
    struct Person *person = (struct Person*) arg;

    while (1) {
        pthread_mutex_lock(&elevator_mutex);
        while (person->from_floor != elevator.current_floor || elevator.capacity == MAX_PEOPLE) {
            waiting_people[person->from_floor - 1]++;
            pthread_cond_wait(&call_condition, &elevator_mutex);
            waiting_people[person->from_floor - 1]--;
        }

        elevator.capacity++;
        printf("Person from floor %d got in. Elevator has %d people\n", person->from_floor, elevator.capacity);

        if (elevator.capacity == MAX_PEOPLE) {
            pthread_cond_signal(&elevator_full_condition);
        }

        while (person->to_floor != elevator.current_floor) {
            pthread_cond_wait(&elevator_serving_condition, &elevator_mutex);
        }

        elevator.capacity--;
        printf("Person from floor %d got out. Elevator has %d people\n", person->to_floor, elevator.capacity);

        if (elevator.capacity == 0) {
            pthread_cond_signal(&elevator_empty_condition);
        }

        pthread_mutex_unlock(&elevator_mutex);
        served_people[person->to_floor - 1]++;
        pthread_exit(NULL);
    }
}

int main() {
    pthread_t elevator_tid, person_tids[MAX_PEOPLE];

    pthread_mutex_init(&elevator_mutex, NULL);
    pthread_cond_init(&elevator_serving_condition, NULL);
    pthread_cond_init(&elevator_empty_condition, NULL);
    pthread_cond_init(&elevator_full_condition, NULL);
    pthread_cond_init(&call_condition, NULL);

    pthread_create(&elevator_tid, NULL, elevator_thread, NULL);
    for (int i = 0; i < MAX_PEOPLE; i++) {
        pthread_create(&person_tids[i], NULL, person_thread, &people_list[i]);
    }

    pthread_join(elevator_tid, NULL);
    for (int i = 0; i < MAX_PEOPLE; i++) {
        pthread_join(person_tids[i], NULL);
    }

    printf("Waiting People\n");
    for (int i = 0; i < FLOORS; i++) {
        printf("Floor %d: %d\n", i + 1, waiting_people[i]);
    }

    printf("Served People\n");
    for (int i = 0; i < FLOORS; i++) {
        printf("Floor %d: %d\n", i + 1, served_people[i]);
    }

    pthread_mutex_destroy(&elevator_mutex);
    pthread_cond_destroy(&elevator_serving_condition);
    pthread_cond_destroy(&elevator_empty_condition);
    pthread_cond_destroy(&elevator_full_condition);
    pthread_cond_destroy(&call_condition);

    return 0;
}