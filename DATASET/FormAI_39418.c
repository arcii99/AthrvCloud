//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: visionary
/*
 * This program demonstrates a unique CPU scheduling algorithm called "Star Priority".
 * The basic idea is to prioritize processes based on their importance to the overall performance of the system.
 * In this case, processes that have a higher "star rating" will be given priority over those with a lower rating.
 * The star rating is calculated based on a variety of factors, including the number of I/O requests, the amount of CPU time used, and the amount of memory required.
 * 
 * In order for this algorithm to work effectively, it is important to have a good understanding of the system and the processes that are running on it.
 * This information can be gathered through monitoring and analysis tools that are built into the system.
 */

#include <stdio.h>

struct process {
    int pid; // process ID
    int io_reqs; // number of I/O requests
    int cpu_time; // amount of CPU time used
    int mem_req; // amount of memory required
    int star_rating; // calculated "star rating" of the process
    int priority; // priority level of the process
};

int main() {
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    struct process proc[num_processes];
    
    // Get process information from user
    for(int i=0; i<num_processes; i++) {
        printf("Enter the process ID: ");
        scanf("%d", &proc[i].pid);
        printf("Enter the number of I/O requests: ");
        scanf("%d", &proc[i].io_reqs);
        printf("Enter the amount of CPU time used: ");
        scanf("%d", &proc[i].cpu_time);
        printf("Enter the amount of memory required: ");
        scanf("%d", &proc[i].mem_req);
        
        // Calculate the "star rating" of the process
        proc[i].star_rating = (proc[i].io_reqs * 2) + (proc[i].cpu_time / 10) - (proc[i].mem_req / 1024);
        
        // Set the priority level based on the star rating
        if(proc[i].star_rating >= 10) {
            proc[i].priority = 0;
        } else if(proc[i].star_rating >= 5 && proc[i].star_rating < 10) {
            proc[i].priority = 1;
        } else {
            proc[i].priority = 2;
        }
    }
    
    // Sort the processes based on priority level
    for(int i=0; i<num_processes-1; i++) {
        for(int j=0; j<num_processes-i-1; j++) {
            if(proc[j].priority > proc[j+1].priority) {
                struct process temp = proc[j];
                proc[j] = proc[j+1];
                proc[j+1] = temp;
            }
        }
    }
    
    // Display the sorted processes
    printf("\nProcess ID\tI/O Requests\tCPU Time\tMemory Required\tStar Rating\tPriority\n");
    for(int i=0; i<num_processes; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].io_reqs, proc[i].cpu_time, proc[i].mem_req, proc[i].star_rating, proc[i].priority);
    }
    
    return 0;
}