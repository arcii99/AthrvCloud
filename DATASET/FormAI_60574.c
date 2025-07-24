//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define PPL_ON_FLOOR 5

pthread_mutex_t up_mutex[MAX_FLOORS];
pthread_mutex_t down_mutex[MAX_FLOORS];

int curr_floor = 0;

void* elevator(void* arg) {
    int next_floor;
    int direction = *(int*) arg;
    while (1) {
        if (direction == 1) {
            if (curr_floor == MAX_FLOORS-1) {
                direction = -1;
                continue;
            }
            next_floor = curr_floor + 1;
        }
        else {
            if (curr_floor == 0) {
                direction = 1;
                continue;
            }
            next_floor = curr_floor - 1;
        }
        if (direction == 1) {
            pthread_mutex_lock(&up_mutex[next_floor]);
            printf("Elevator going up, arrived at floor %d\n", next_floor+1);
            curr_floor = next_floor;
            sleep(2);
            pthread_mutex_unlock(&up_mutex[next_floor]);
        }
        else {
            pthread_mutex_lock(&down_mutex[next_floor]);
            printf("Elevator going down, arrived at floor %d\n", next_floor+1);
            curr_floor = next_floor;
            sleep(2);
            pthread_mutex_unlock(&down_mutex[next_floor]);
        }
    }
}

void* person(void* arg) {
    int curr_floor = *(int*) arg;
    int dest_floor;
    while (1) {
        do {
            dest_floor = rand() % MAX_FLOORS;
        } while (dest_floor == curr_floor);
        if (dest_floor > curr_floor) {
            pthread_mutex_lock(&up_mutex[curr_floor]);
            printf("Person going up from floor %d to %d\n", curr_floor+1, dest_floor+1);
            pthread_mutex_unlock(&up_mutex[curr_floor]);
            while (curr_floor < dest_floor) {
                sleep(1);
                curr_floor++;
            }
            pthread_mutex_lock(&up_mutex[curr_floor]);
            printf("Person arrived at floor %d\n", curr_floor+1);
            pthread_mutex_unlock(&up_mutex[curr_floor]);
        }
        else {
            pthread_mutex_lock(&down_mutex[curr_floor]);
            printf("Person going down from floor %d to %d\n", curr_floor+1, dest_floor+1);
            pthread_mutex_unlock(&down_mutex[curr_floor]);
            while (curr_floor > dest_floor) {
                sleep(1);
                curr_floor--;
            }
            pthread_mutex_lock(&down_mutex[curr_floor]);
            printf("Person arrived at floor %d\n", curr_floor+1);
            pthread_mutex_unlock(&down_mutex[curr_floor]);
        }
        sleep(rand() % 5 + 1);
    }
}

int main() {
    pthread_t elevator_thread;
    pthread_t person_thread[MAX_FLOORS * PPL_ON_FLOOR];
    int direction = 1;
    srand(time(NULL));
    pthread_mutex_init(&up_mutex[0], NULL);
    pthread_mutex_init(&down_mutex[MAX_FLOORS-1], NULL);
    for (int i = 1; i < MAX_FLOORS; i++) {
        pthread_mutex_init(&up_mutex[i], NULL);
        pthread_mutex_init(&down_mutex[i-1], NULL);
    }
    for (int i = 0; i < MAX_FLOORS * PPL_ON_FLOOR; i++) {
        int* curr_floor = (int*) malloc(sizeof(int));
        *curr_floor = rand() % MAX_FLOORS;
        pthread_create(&person_thread[i], NULL, person, curr_floor);
    }
    pthread_create(&elevator_thread, NULL, elevator, &direction);
    pthread_join(elevator_thread, NULL);
    return 0;
}