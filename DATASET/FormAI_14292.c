//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>

// Defining Process Structure
typedef struct {
    int pid; // process id
    int burst_time; // burst time of the process
    int arrival_time; // arrival time of the process
    int start_time; // start time of the process
    int completion_time; // completion time of the process
    int waiting_time; // waiting time of the process
    int turnaround_time; // turnaround time of the process
    int priority; // priority of the process
} Process;

// Function to sort the Processes based on Arrival Time
void sort(Process* p, int n) {
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(p[i].arrival_time > p[j].arrival_time) {
                Process temp=p[j];
                p[j]=p[i];
                p[i]=temp;
            }
        }
    }
}

// Function to execute the Process
void execute(Process* p, int n) {
    int current_time = 0, completed_process = 0;
    while(1) {
        int id = -1;
        int max_priority = -1;
      
        // Checking for the Process with Highest Priority
        for(int i=0; i<n; i++) {
            if(p[i].burst_time && p[i].arrival_time <= current_time && p[i].priority > max_priority) {
                max_priority=p[i].priority;
                id=i;
            }
        }
      
        if(id == -1) {
            if(!completed_process) {
                printf("\nNo processes to schedule. Exiting....\n");
            }
            break;
        }
      
        // Updating the Process Information
        p[id].start_time = current_time;
        p[id].completion_time = current_time + p[id].burst_time;
        p[id].waiting_time = p[id].start_time - p[id].arrival_time;
        p[id].turnaround_time = p[id].completion_time - p[id].arrival_time;
        current_time = p[id].completion_time;
        p[id].burst_time = 0;
        completed_process++;
    }
}

// Function to Calculate Average Waiting Time and Turnaround Time
void calculate(Process* p, int n, float *avg_wt, float *avg_tat) {
    int total_wt = 0, total_tat = 0;
    for(int i=0; i<n; i++) {
        total_wt += p[i].waiting_time;
        total_tat += p[i].turnaround_time;
    }
    *avg_wt = total_wt/(float)n;
    *avg_tat = total_tat/(float)n;
}

// Main Function
int main() {
    // Defining the Processes
    Process p[5] = { {1, 10, 0, 0, 0, 0, 0, 3},
                     {2, 1, 1, 0, 0, 0, 0, 1},
                     {3, 2, 2, 0, 0, 0, 0, 4},
                     {4, 1, 3, 0, 0, 0, 0, 2},
                     {5, 5, 4, 0, 0, 0, 0, 5} };
                     
    // Sorting the Processes based on Arrival Time
    sort(p, 5);
    
    // Executing the Processes
    execute(p, 5);
    
    // Calculating the Average Waiting Time and Turnaround Time
    float avg_wt = 0, avg_tat = 0;
    calculate(p, 5, &avg_wt, &avg_tat);
    
    // Displaying the Output
    printf("\nPID\tBT\tAT\tST\tCT\tWT\tTAT\tPriority\n");
    for(int i=0; i<5; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].burst_time, p[i].arrival_time, p[i].start_time, p[i].completion_time, p[i].waiting_time, p[i].turnaround_time, p[i].priority);
    }
    
    printf("\nAverage Waiting Time: %f\nAverage Turnaround Time: %f\n", avg_wt, avg_tat);
    
    return 0;
}