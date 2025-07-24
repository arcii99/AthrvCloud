//FormAI DATASET v1.0 Category: Task Scheduler ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Job structure to hold all of the information for a job to be executed
struct Job {
    int id;
    int priority;
    int delay; // in seconds
    void (*function)(void);
};

// Function to execute a job
void executeJob(struct Job job) {
    printf("Executing Job %d...\n", job.id);
    sleep(job.delay);
    job.function();
}

// Task Scheduler function to run all scheduled jobs
void runScheduler(struct Job jobs[], int numJobs) {
    // Sort jobs by priority (highest to lowest)
    for (int i = 0; i < numJobs; i++) {
        for (int j = i + 1; j < numJobs; j++) {
            if (jobs[i].priority < jobs[j].priority) {
                struct Job temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            }
        }
    }

    // Execute jobs in order of priority (highest to lowest)
    for (int i = 0; i < numJobs; i++) {
        executeJob(jobs[i]);
    }
}

// Functions for the jobs to be executed
void job1() {
    printf("Job 1 executed.\n");
}

void job2() {
    printf("Job 2 executed.\n");
}

void job3() {
    printf("Job 3 executed.\n");
}

int main() {
    // Create jobs and add them to the job array
    struct Job jobs[3];
    jobs[0] = (struct Job) {1, 3, 2, job1};
    jobs[1] = (struct Job) {2, 1, 4, job2};
    jobs[2] = (struct Job) {3, 2, 1, job3};

    // Execute all scheduled jobs
    runScheduler(jobs, 3);

    return 0;
}