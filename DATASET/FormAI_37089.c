//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_FLOORS 20
#define MAX_PASSENGERS 10

int current_floor = 0;
int passengers_waiting[MAX_FLOORS] = {0};
int passengers_in_elevator = 0;
int elev_direction = 1; // 1 for up, -1 for down
int floors_travelled = 0;
sem_t elevator_mutex, floor_mutex;

void *elevator(void *param);
void *passenger(void *param);

int main(int argc, char *argv[]) {

    pthread_t elevator_thread;
    pthread_t passenger_threads[MAX_FLOORS][MAX_PASSENGERS];

    sem_init(&elevator_mutex, 0, 1);
    sem_init(&floor_mutex, 0, 1);

    pthread_create(&elevator_thread, NULL, elevator, NULL);

    for(int i = 0; i < MAX_FLOORS; i++) {
        for(int j = 0; j < MAX_PASSENGERS; j++) {
            pthread_create(&passenger_threads[i][j], NULL, passenger, (void *)i);
            usleep(100000);
        }
    }

    pthread_join(elevator_thread, NULL);

    return 0;
}

void *elevator(void *param) {

    while(1) {

        sem_wait(&floor_mutex);

        if(passengers_waiting[current_floor] > 0 || passengers_in_elevator > 0) {

            sem_wait(&elevator_mutex);

            printf("Elevator at floor %d with %d passengers.\n", current_floor, passengers_in_elevator);

            if(current_floor == 0 || current_floor == MAX_FLOORS - 1) {
                elev_direction *= -1;
            }

            current_floor += elev_direction;
            floors_travelled++;

            if(passengers_waiting[current_floor] > 0) {

                printf("Elevator doors opening at floor %d\n", current_floor);

                while(passengers_in_elevator < MAX_PASSENGERS && passengers_waiting[current_floor] > 0) {
                    passengers_waiting[current_floor]--;
                    passengers_in_elevator++;
                }

                printf("Elevator doors closing with %d passengers.\n", passengers_in_elevator);

                sleep(2); //Time to travel each floor

            } else {

                printf("Elevator doors closing with no passengers.\n");

                sleep(2); //Time to travel each floor

            }

            sem_post(&elevator_mutex);

        } else {

            sem_post(&floor_mutex);

        }

    }

}

void *passenger(void *param) {

    int current_waiting_floor = (int)param;

    while(1) {

        sem_wait(&elevator_mutex);

        if(passengers_in_elevator < MAX_PASSENGERS && current_waiting_floor == current_floor) {

            printf("Passenger %ld entered elevator on floor %d\n", pthread_self(), current_floor);

            passengers_waiting[current_waiting_floor]--;
            passengers_in_elevator++;

            sem_post(&elevator_mutex);

            while(current_waiting_floor != current_floor) {
                printf("Passenger %ld waiting for elevator at floor %d.\n", pthread_self(), current_waiting_floor);
                sleep(1);
            }

        } else {

            passengers_waiting[current_waiting_floor]++;

            sem_post(&elevator_mutex);

            while(current_waiting_floor != current_floor) {
                printf("Passenger %ld waiting for elevator at floor %d.\n", pthread_self(), current_waiting_floor);
                sleep(1);
            }

        }

        sem_wait(&elevator_mutex);

        if(passengers_in_elevator > 0 && current_floor == 0) {

            printf("Passenger %ld exited elevator on floor %d\n", pthread_self(), current_floor);

            passengers_in_elevator--;

            sem_post(&elevator_mutex);

        } else if(passengers_in_elevator > 0 && current_floor == MAX_FLOORS - 1) {

            printf("Passenger %ld exited elevator on floor %d\n", pthread_self(), current_floor);

            passengers_in_elevator--;
            floors_travelled--;

            sem_post(&elevator_mutex);

        } else {

            sem_post(&elevator_mutex);

        }

    }

}