//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_OF_ROOMS 5

typedef struct {
    int id;
    int visited;
} Room;

Room rooms[NUM_OF_ROOMS];

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_t threads[NUM_OF_ROOMS];

void *visit_room(void *arg) {
    int id = *((int *)arg);
    printf("Entering room %d\n", id);

    pthread_mutex_lock(&mutex);
    rooms[id].visited = 1;
    pthread_mutex_unlock(&mutex);

    sleep(1);

    printf("Exiting room %d\n", id);
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < NUM_OF_ROOMS; i++) {
        rooms[i].id = i;
        rooms[i].visited = 0;
    }

    printf("Welcome to the Haunted House Simulator!\n");

    while (1) {
        int random_room = rand() % NUM_OF_ROOMS;

        if (!rooms[random_room].visited) {
            pthread_create(&threads[random_room], NULL, visit_room, (void *)&rooms[random_room].id);
            pthread_join(threads[random_room], NULL);
            break;
        }
    }

    printf("Thank you for visiting the Haunted House!\n");
    return 0;
}