//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_BAGGAGE 100 // Maximum number of bags for simulation
#define MAX_WEIGHT 50 // Maximum weight of a single bag
#define MAX_TRANSFER_TIME 30 // Maximum time for a single bag transfer

// Structure to store information about a bag
typedef struct {
    int id;
    int weight;
} Bag;

// Function to get a random integer between min and max
int random_int(int min, int max) {
    int range = max - min + 1;
    return (rand() % range) + min;
}

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Initialize bag queue
    Bag queue[MAX_BAGGAGE];
    int front = 0;
    int rear = -1;
    int size = 0;

    // Initialize variables for simulation
    int total_bags = 0;
    int total_weight = 0;
    int total_time = 0;

    // Run simulation for 1 hour (60 minutes)
    for(int i=1; i<=60; i++) {
        // Generate random number of bags to add to queue
        int new_bags = random_int(1, 10);
        printf("Minute %d - %d new bags added to queue\n", i, new_bags);
        // Add bags to queue
        for(int j=0; j<new_bags; j++) {
            // Create new bag
            Bag new_bag;
            new_bag.id = total_bags + 1;
            new_bag.weight = random_int(1, MAX_WEIGHT);
            // Add new bag to queue
            if(size < MAX_BAGGAGE) {
                rear = (rear + 1) % MAX_BAGGAGE;
                queue[rear] = new_bag;
                size++;
                total_bags++;
                total_weight += new_bag.weight;
                printf("Bag %d (weight %d) added to queue\n", new_bag.id, new_bag.weight);
            } else {
                printf("*** Queue overflow! Bag %d (weight %d) lost\n", new_bag.id, new_bag.weight);
            }
        }
        // Transfer bags from queue to conveyor belt
        int transfer_time = 0;
        int bags_transferred = 0;
        while(size > 0 && transfer_time < MAX_TRANSFER_TIME) {
            // Remove bag from queue
            Bag current_bag = queue[front];
            front = (front + 1) % MAX_BAGGAGE;
            size--;
            // Transfer bag to conveyor belt
            printf("Bag %d (weight %d) transferred to conveyor belt\n", current_bag.id, current_bag.weight);
            bags_transferred++;
            transfer_time += random_int(1, 5);
        }
        // Print summary of transfer
        if(bags_transferred > 0) {
            printf("%d bags transferred to conveyor belt in %d minutes\n", bags_transferred, transfer_time);
            total_time += transfer_time;
        } else {
            printf("No bags transferred to conveyor belt this minute\n");
        }
        // Pause simulation for 1 second
        sleep(1);
    }
    // Print final statistics
    printf("Simulation completed - %d bags (%d kgs) transferred in %d minutes\n", total_bags, total_weight, total_time);
    return 0;
}