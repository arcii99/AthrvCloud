//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a job
struct Job {
    int start;
    int end;
};

// Define a function to compare two jobs based on their end times
int compareJobs(const void* a, const void* b) {
    const struct Job* jobA = (struct Job*)a;
    const struct Job* jobB = (struct Job*)b;
    return jobA->end - jobB->end;
}

// Define a function to find the maximum number of jobs that can be scheduled
int findMaxJobs(struct Job jobs[], int length) {
    // Sort the jobs in ascending order based on their end times
    qsort(jobs, length, sizeof(struct Job), compareJobs);
    
    // Start with the first job in the sorted list
    int currentJob = 0;
    int maxJobs = 1; // At least one job can be scheduled
    
    // For each subsequent job, if it starts after the previous job ends,
    // it can be scheduled and we update the current job and maximum job count
    for (int i = 1; i < length; i++) {
        if (jobs[i].start >= jobs[currentJob].end) {
            currentJob = i;
            maxJobs++;
        }
    }
    
    return maxJobs;
}

int main() {
    // Create some example jobs
    struct Job jobs[] = {{1, 3}, {2, 5}, {4, 7}, {6, 9}, {8, 10}};
    int numJobs = sizeof(jobs) / sizeof(struct Job);
    
    // Find the maximum number of jobs that can be scheduled
    int maxJobs = findMaxJobs(jobs, numJobs);
    
    // Output the result
    printf("The maximum number of jobs that can be scheduled is: %d\n", maxJobs);
    
    return 0;
}