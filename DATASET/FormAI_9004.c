//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: lively
#include<stdio.h>

// defining the structure of a process
struct process{
    int pid;
    int arrivalTime;
    int burstTime;
    int waitTime;
    int turnaroundTime;
};

// function to swap two processes
void swap(struct process *xp, struct process *yp){
    struct process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// function to sort the processes based on arrival time
void sortProcessesBasedOnArrivalTime(struct process processes[], int n){
    int i, j;
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(processes[j].arrivalTime > processes[j+1].arrivalTime){
                swap(&processes[j], &processes[j+1]);
            }
        }
    }
}

// function to implement Round Robin Scheduling Algorithm
void roundRobinScheduling(struct process processes[], int n, int quantumTime){
    // array to store remaining burst time of processes
    int remainingBurstTime[n];
    int i;
    for(i = 0; i < n; i++){
        remainingBurstTime[i] = processes[i].burstTime;
    }
    int t = 0; // current time
    // loop until all the processes are completed
    while(1){
        int done = 1;
        // loop through all the processes
        for(i = 0; i < n; i++){
            // if the process has remaining burst time
            if(remainingBurstTime[i] > 0){
                done = 0;
                // if the process remaining burst time is less than or equal to the quantum time
                if(remainingBurstTime[i] <= quantumTime){
                    // increase current time by the remaining burst time of the process
                    t += remainingBurstTime[i]; 
                    // update wait time and turnaround time of the process
                    processes[i].waitTime = t - processes[i].burstTime - processes[i].arrivalTime;
                    processes[i].turnaroundTime = t - processes[i].arrivalTime;
                    // set the remaining burst time of the process to 0
                    remainingBurstTime[i] = 0;
                }
                // if the process remaining burst time is greater than the quantum time
                else{
                    // increase current time by the quantum time
                    t += quantumTime;
                    // update the remaining burst time of the process
                    remainingBurstTime[i] -= quantumTime;
                }
            }
        }
        // exit the loop if all the processes are completed
        if(done == 1){
            break;
        }
    }
}

// function to calculate and print average wait time and average turnaround time of the processes
void calculateAndPrintAverageTime(struct process processes[], int n){
    int i;
    float totalWaitTime = 0, totalTurnaroundTime = 0;
    for(i = 0; i < n; i++){
        totalWaitTime += processes[i].waitTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }
    printf("\nAverage wait time = %f\nAverage turnaround time = %f\n", (totalWaitTime/n), (totalTurnaroundTime/n));
}

// main function
int main(){
    // array of processes
    struct process processes[] = {{1, 0, 8}, {2, 1, 4}, {3, 2, 9}, {4, 3, 5}, {5, 4, 2}};
    int n = sizeof(processes) / sizeof(processes[0]);
    // sort the processes based on arrival time
    sortProcessesBasedOnArrivalTime(processes, n);
    int quantumTime = 3;
    // implement Round Robin Scheduling Algorithm with quantum time of 3
    roundRobinScheduling(processes, n, quantumTime);
    // calculate and print average wait time and average turnaround time of the processes
    calculateAndPrintAverageTime(processes, n);
    return 0;
}