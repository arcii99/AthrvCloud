//FormAI DATASET v1.0 Category: Task Scheduler ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct task {
    int id;             // Task ID
    int priority;       // Task Priority
    int timeleft;       // Time remaining for task
};

// Function to run the task
void run_task(struct task *t) {
    printf("Running Task %d...\n", t->id);
    t->timeleft = 0;    // Set timeleft to zero when task is completed
}

// Function to print the queue of tasks
void print_queue(struct task *queue, int n) {
    printf("Task ID\tPriority\tTime Left\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", queue[i].id, queue[i].priority, queue[i].timeleft);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));  // Seed random number generator
    
    int n = 5;           // Number of tasks in the queue
    struct task queue[n];   // Array to store the queue of tasks
    
    // Initialize the queue with random tasks
    for(int i = 0; i < n; i++) {
        queue[i].id = i+1;                      // Set task ID
        queue[i].priority = rand() % 10 + 1;    // Set priority (1-10)
        queue[i].timeleft = rand() % 10 + 1;    // Set timeleft (1-10)
    }
    
    // Print the initial queue of tasks
    printf("Initial Queue of Tasks:\n");
    print_queue(queue, n);
    
    // Run the tasks in order of priority
    while(n > 0) {
        int max_idx = 0;        // Index of task with highest priority
        for(int i = 1; i < n; i++) {
            // If the current task has higher priority than previous task
            // OR if priority is same, but timeleft is less for current task
            if(queue[i].priority > queue[max_idx].priority ||
               (queue[i].priority == queue[max_idx].priority && queue[i].timeleft < queue[max_idx].timeleft)) {
                max_idx = i;    // Update index of task with highest priority
            }
        }
        run_task(&queue[max_idx]);  // Run the task with highest priority
        // Remove the task with highest priority from the queue
        for(int i = max_idx; i < n-1; i++) {
            queue[i] = queue[i+1];
        }
        n--;    // Decrement the size of the queue
        // Print the updated queue of tasks
        printf("Updated Queue of Tasks:\n");
        print_queue(queue, n);
    }
    
    printf("All tasks completed.\n");
    return 0;
}