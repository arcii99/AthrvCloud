//FormAI DATASET v1.0 Category: Task Scheduler ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// job structure to hold task details
struct Job {
    int id;
    int priority;
    int burst_time;
    int wait_time;
    int turnaround_time;
};

// function to initialize the job queue
void init_job_queue(struct Job * job_queue, int num_jobs) {
    for (int i = 0; i < num_jobs; i++) {
        job_queue[i].id = i + 1;
        job_queue[i].priority = rand() % 5 + 1; // generate random priority level between 1 to 5
        job_queue[i].burst_time = rand() % 10 + 1; // generate random burst time between 1 to 10
        job_queue[i].wait_time = 0;
        job_queue[i].turnaround_time = 0;
    }
}

// function to print the details of a single job
void print_job(struct Job job) {
    printf("Job ID: %d, Priority: %d, Burst Time: %d, Wait Time: %d, Turnaround Time: %d\n", 
           job.id, job.priority, job.burst_time, job.wait_time, job.turnaround_time);
}

// function to print the details of all jobs in the queue
void print_job_queue(struct Job * job_queue, int num_jobs) {
    printf("Job Queue:\n");
    for (int i = 0; i < num_jobs; i++) {
        print_job(job_queue[i]);
    }
}

// main function
int main() {
    int num_jobs = 10; // number of jobs in the queue
    struct Job job_queue[num_jobs]; // create a job queue of size num_jobs
    
    init_job_queue(job_queue, num_jobs); // initialize the job queue
    
    print_job_queue(job_queue, num_jobs); // print the details of all jobs in the queue
    
    return 0;
}