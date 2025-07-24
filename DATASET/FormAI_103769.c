//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_BAGS 50 // maximum number of bags handled by system
#define MAX_LOADING_GATES 3 // maximum number of loading gates at airport
#define MAX_BAGS_PER_GATE 5 // maximum number of bags that can be loaded on a plane per gate
#define BAG_WEIGHT_MIN 1 // minimum weight of a bag
#define BAG_WEIGHT_MAX 100 // maximum weight of a bag

// queue structure to maintain bags
typedef struct Queue {
    int* bags;
    int front;
    int rear;
    int size;
} Queue;

// function to check if queue is full
int isFull(Queue* queue) {
    return queue->size == MAX_BAGS;
}

// function to check if queue is empty
int isEmpty(Queue* queue) {
    return queue->size == 0;
}

// function to enqueue a bag in the queue
void enqueue(Queue* queue, int bag) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % MAX_BAGS;
    queue->bags[queue->rear] = bag;
    queue->size++;
}

// function to dequeue a bag from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int bag = queue->bags[queue->front];
    queue->front = (queue->front + 1) % MAX_BAGS;
    queue->size--;
    return bag;
}

// global variables for shared resources
Queue conveyor_belt; // conveyor belt to transport bags
Queue loading_gate_queues[MAX_LOADING_GATES]; // queues for each loading gate
pthread_mutex_t conveyor_mutex = PTHREAD_MUTEX_INITIALIZER; // mutex lock for conveyor belt
pthread_mutex_t gate_mutexes[MAX_LOADING_GATES] = PTHREAD_MUTEX_INITIALIZER; // mutex locks for loading gates

// function for a worker thread to add bags to conveyor belt
void* add_bags_to_conveyor_belt(void* arg) {
    int bags_added_count = 0;
    while (bags_added_count < MAX_BAGS) {
        int bag_weight = (rand() % (BAG_WEIGHT_MAX - BAG_WEIGHT_MIN + 1)) + BAG_WEIGHT_MIN; // generate random bag weight
        pthread_mutex_lock(&conveyor_mutex); // acquire mutex lock for conveyor belt
        enqueue(&conveyor_belt, bag_weight); // add bag to conveyor belt
        printf("Added bag with weight %d to conveyor belt\n", bag_weight);
        pthread_mutex_unlock(&conveyor_mutex); // release mutex lock for conveyor belt
        bags_added_count++;
    }
    return NULL;
}

// function for a worker thread to transport bags from conveyor belt to loading gates
void* transport_bags_to_loading_gates(void* arg) {
    int bags_loaded_count = 0;
    int loading_gate_id = *(int*)arg; // get loading gate ID from thread argument
    while (bags_loaded_count < MAX_BAGS) {
        pthread_mutex_lock(&conveyor_mutex); // acquire mutex lock for conveyor belt
        if (!isEmpty(&conveyor_belt)) {
            int bag_weight = dequeue(&conveyor_belt); // remove bag from conveyor belt
            pthread_mutex_unlock(&conveyor_mutex); // release mutex lock for conveyor belt
            pthread_mutex_lock(&gate_mutexes[loading_gate_id]); // acquire mutex lock for loading gate
            enqueue(&loading_gate_queues[loading_gate_id], bag_weight); // add bag to loading gate queue
            printf("Transported bag with weight %d to loading gate %d\n", bag_weight, loading_gate_id);
            pthread_mutex_unlock(&gate_mutexes[loading_gate_id]); // release mutex lock for loading gate
            bags_loaded_count++;
        } else {
            pthread_mutex_unlock(&conveyor_mutex); // release mutex lock for conveyor belt if queue is empty
        }
    }
    printf("Finished transport to loading gates for gate %d\n", loading_gate_id);
    return NULL;
}

// function for a worker thread to load bags from loading gates onto plane
void* load_bags_onto_plane(void* arg) {
    int bags_loaded_count = 0;
    int loading_gate_id = *(int*)arg; // get loading gate ID from thread argument
    while (bags_loaded_count < MAX_BAGS_PER_GATE) {
        pthread_mutex_lock(&gate_mutexes[loading_gate_id]); // acquire mutex lock for loading gate
        if (!isEmpty(&loading_gate_queues[loading_gate_id])) {
            int bag_weight = dequeue(&loading_gate_queues[loading_gate_id]); // remove bag from loading gate queue
            printf("Loaded bag with weight %d onto plane at loading gate %d\n", bag_weight, loading_gate_id);
            pthread_mutex_unlock(&gate_mutexes[loading_gate_id]); // release mutex lock for loading gate
            bags_loaded_count++;
        } else {
            pthread_mutex_unlock(&gate_mutexes[loading_gate_id]); // release mutex lock for loading gate if queue is empty
        }
    }
    printf("Finished loading at loading gate %d\n", loading_gate_id);
    return NULL;
}

int main() {
    // initialize queues
    conveyor_belt.bags = (int*)malloc(MAX_BAGS * sizeof(int));
    conveyor_belt.front = 0;
    conveyor_belt.rear = -1;
    conveyor_belt.size = 0;
    for (int i = 0; i < MAX_LOADING_GATES; i++) {
        loading_gate_queues[i].bags = (int*)malloc(MAX_BAGS_PER_GATE * sizeof(int));
        loading_gate_queues[i].front = 0;
        loading_gate_queues[i].rear = -1;
        loading_gate_queues[i].size = 0;
    }
    // create threads for each worker task
    pthread_t conveyor_worker, transport_workers[MAX_LOADING_GATES], loading_workers[MAX_LOADING_GATES];
    pthread_create(&conveyor_worker, NULL, add_bags_to_conveyor_belt, NULL);
    for (int i = 0; i < MAX_LOADING_GATES; i++) {
        int* arg = (int*)malloc(sizeof(*arg));
        *arg = i;
        pthread_create(&transport_workers[i], NULL, transport_bags_to_loading_gates, arg);
        pthread_create(&loading_workers[i], NULL, load_bags_onto_plane, arg);
    }
    // wait for threads to finish
    pthread_join(conveyor_worker, NULL);
    for (int i = 0; i < MAX_LOADING_GATES; i++) {
        pthread_join(transport_workers[i], NULL);
        pthread_join(loading_workers[i], NULL);
    }
    // free memory
    free(conveyor_belt.bags);
    for (int i = 0; i < MAX_LOADING_GATES; i++) {
        free(loading_gate_queues[i].bags);
    }
    return 0;
}