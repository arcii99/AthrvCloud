//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


#define MAX_FLOORS 10
#define MAX_THREADS 20

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int total_passengers = 0;
int current_floor = 0;
int current_direction = 1; //1 for up, -1 for down
int floors[MAX_FLOORS] = {0}; // floors array indicates how many passengers are waiting at each floor

void* passenger(void *arg) {
    int src_floor = rand() % MAX_FLOORS;
    int dest_floor = rand() % MAX_FLOORS;
   
    while(src_floor == dest_floor){
        dest_floor = rand() % MAX_FLOORS;
    }
   
    printf("Passenger is waiting at floor %d, going to floor %d\n", src_floor, dest_floor);
   
    pthread_mutex_lock(&mutex);
    floors[src_floor]++;
    total_passengers++;
    pthread_cond_wait(&cond, &mutex); //waiting for the elevator to arrive
    floors[src_floor]--;
    pthread_mutex_unlock(&mutex);
   
    usleep(rand() % 500000 + 500000); //time to board the elevator (between 0.5 to 1 seconds)
    printf("Passenger is in the elevator, going from floor %d to floor %d\n", src_floor, dest_floor);

    usleep(rand() % 500000 + 500000); //time to reach the destination floor (between 0.5 to 1 seconds)
    printf("Passenger has arrived at floor %d\n", dest_floor);

    return (void*)0;
}


void* elevator(void *arg) {
    while(total_passengers > 0){
        pthread_mutex_lock(&mutex);
        while(floors[current_floor] == 0){
            current_floor += current_direction;
            if(current_floor == 0 || current_floor == MAX_FLOORS-1) current_direction = -current_direction;
            usleep(100000); //waiting for 0.1 seconds before checking for the next floor
        }
        printf("Elevator is now at floor %d\n", current_floor);
        pthread_cond_broadcast(&cond); //all passengers waiting at this floor can board the elevator now
        pthread_mutex_unlock(&mutex);
       
        usleep(500000); //time to board the passengers (0.5 second)
    }
    return (void*)0;
}


int main(){
    pthread_t threads[MAX_THREADS];
    pthread_create(&threads[0], NULL, elevator, NULL);
   
    int i;
    for(i=1; i<MAX_THREADS; i++){
        pthread_create(&threads[i], NULL, passenger, NULL);
        usleep(rand() % 500000 + 500000);
    }
   
    for(i=0; i<MAX_THREADS; i++) pthread_join(threads[i], NULL);
    return 0;
}