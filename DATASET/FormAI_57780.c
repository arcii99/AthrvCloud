//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_PROCESS 5 // Maximum number of processes that can be serviced
#define MAX_BURST 20 // Maximum burst time for a process
#define MAX_PRIORITY 10 // Maximum priority level


struct process {
    int process_id;
    int burst_time;
    int priority_level;
};

struct priority_queue_node {
    struct process proc;
    struct priority_queue_node* next;
};

// function to create a new priority queue node
struct priority_queue_node* create_new_node(struct process proc) {
    struct priority_queue_node* new_node = (struct priority_queue_node*) malloc(sizeof(struct priority_queue_node));
    new_node->proc = proc;
    new_node->next = NULL;
    return new_node;
}

// function to insert a process in priority queue based on its priority level
void insert_process(struct priority_queue_node** queue_head, struct process proc) {
    struct priority_queue_node* new_node = create_new_node(proc);
    if (*queue_head == NULL) {
        *queue_head = new_node;
        return;
    }
    if ((*queue_head)->proc.priority_level > proc.priority_level) {
        new_node->next = *queue_head;
        *queue_head = new_node;
        return;
    }
    struct priority_queue_node* temp = *queue_head;
    while (temp->next != NULL && temp->next->proc.priority_level <= proc.priority_level)
        temp = temp->next;
    new_node->next = temp->next;
    temp->next = new_node;
    return;
}

// function to remove the highest priority process in queue and return it
struct process remove_process(struct priority_queue_node** queue_head) {
    if (*queue_head == NULL) {
        printf("\nERROR: Queue is empty.");
        struct process null_proc;
        null_proc.process_id = -1;
        null_proc.burst_time = -1;
        null_proc.priority_level = -1;
        return null_proc;
    }
    struct priority_queue_node* temp = *queue_head;
    struct process highest_priority_proc = temp->proc;
    *queue_head = (*queue_head)->next;
    free(temp);
    return highest_priority_proc;
}

// function to display queue of processes in order of priority
void display_queue(struct priority_queue_node* queue_head) {
    if (queue_head == NULL) {
        printf("\nQueue is empty.");
        return;
    }
    printf("\nQueue of processes:");
    struct priority_queue_node* temp = queue_head;
    while (temp != NULL) {
        printf("\nProcess ID: %d, Burst Time: %d, Priority Level: %d",
        temp->proc.process_id, temp->proc.burst_time, temp->proc.priority_level);
        temp = temp->next;
    }
}

int main() {
    srand(time(0));
    
    // create an array of processes with random burst time and priority level
    struct process processes[MAX_PROCESS];
    for (int i=0; i<MAX_PROCESS; i++) {
        processes[i].process_id = i+1;
        processes[i].burst_time = rand() % MAX_BURST + 1;
        processes[i].priority_level = rand() % MAX_PRIORITY + 1;
    }
    
    // display the array of processes
    printf("Initial array of processes:");
    for (int i=0; i<MAX_PROCESS; i++) {
        printf("\nProcess ID: %d, Burst Time: %d, Priority Level: %d",
        processes[i].process_id, processes[i].burst_time, processes[i].priority_level);
    }
    
    // insert the processes in priority queue based on their priority levels
    struct priority_queue_node* queue_head = NULL;
    for (int i=0; i<MAX_PROCESS; i++)
        insert_process(&queue_head, processes[i]);
    
    // display the queue of processes in order of priority
    display_queue(queue_head);
    
    // remove the highest priority process from queue and service it
    printf("\n\nServicing process with highest priority...");
    struct process highest_priority_proc = remove_process(&queue_head);
    printf("\nProcess ID: %d, Burst Time: %d, Priority Level: %d",
    highest_priority_proc.process_id, highest_priority_proc.burst_time, highest_priority_proc.priority_level);
    
    // display the updated queue of processes
    printf("\n\nUpdated queue of processes in order of priority:");
    display_queue(queue_head);
    
    return 0;
}