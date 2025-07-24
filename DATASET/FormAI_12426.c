//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_JOBS 100 // Maximum number of jobs
#define MAX_TIME 100 // Maximum duration of jobs

// Structure to represent a job
typedef struct {
    int deadline; // Deadline of the job
    int profit; // Profit of the job
    int duration; // Duration of the job
} job_t;

// Function to compare two jobs based on their profit
int compare_jobs(const void* a, const void* b) {
    job_t* job1 = (job_t*) a;
    job_t* job2 = (job_t*) b;
    return job2->profit - job1->profit;
}

// Function to schedule jobs on a single machine
void schedule_jobs(job_t* jobs, int n) {
    int schedule[MAX_TIME] = {0}; // Initialize the machine schedule
    int total_profit = 0;

    // Sort the jobs based on their profit in descending order
    qsort(jobs, n, sizeof(job_t), compare_jobs);

    // Schedule each job in order
    for (int i = 0; i < n; i++) {
        // Find the earliest available time slot for the job
        int slot = jobs[i].deadline - jobs[i].duration;
        while (slot >= 0 && schedule[slot]) {
            slot--;
        }

        // If a time slot is available, schedule the job and update the total profit
        if (slot >= 0) {
            schedule[slot] = 1;
            total_profit += jobs[i].profit;
        }
    }

    // Print the total profit and the schedule
    printf("Total profit = %d\n", total_profit);
    printf("Schedule:\n");
    for (int i = 0; i < MAX_TIME; i++) {
        printf("%c", schedule[i] ? '#' : '-');
    }
    printf("\n");
}

int main() {
    // Example jobs
    job_t jobs[MAX_JOBS] = {
        { 2, 30, 1 },
        { 1, 10, 1 },
        { 2, 20, 2 },
        { 3, 30, 1 },
        { 3, 10, 1 }
    };
    int n = 5;

    // Schedule the jobs and print the result
    schedule_jobs(jobs, n);

    return 0;
}