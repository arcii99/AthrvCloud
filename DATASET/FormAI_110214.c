//FormAI DATASET v1.0 Category: System administration ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Create a struct to represent a server
typedef struct {
    int id;
    char name[50];
    int status;
} Server;

// Define a global array to store servers
Server servers[10];

// Define a function to update server status
void *updateServerStatus(void *serverId) {
    int id = *(int*)serverId;
    // Simulate server activity
    sleep(10);
    // Update server status
    servers[id].status = rand() % 2;
}

int main() {

    // Initialize servers array
    for (int i = 0; i < 10; i++) {
        servers[i].id = i;
        sprintf(servers[i].name, "Server %d", i);
        servers[i].status = 1;
    }

    // Create threads to simulate server activity and update status
    pthread_t threads[10];
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, updateServerStatus, &servers[i].id);
    }

    // Wait for threads to finish
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print updated server statuses
    for (int i = 0; i < 10; i++) {
        printf("%s is %s\n", servers[i].name, servers[i].status ? "up" : "down");
    }

    return 0;
}