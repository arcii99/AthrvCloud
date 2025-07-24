//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining a Process Structure
struct Process {
    int pid;
    int arrTime;
    int burstTime;
    int priority;
};

// Function to swap two processes
void swap(struct Process* a, struct Process* b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort the processes based on arrival time
void sortArrivalTime(struct Process* arr, int n) {
    int i, j;
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            // If arrival time of i is greater than j, swap the processes
            if(arr[i].arrTime > arr[j].arrTime) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

// Function to implement the Round Robin Scheduling Algorithm
void roundRobinScheduling(struct Process* arr, int n, int quantum) {
    // Initializing the waiting, turnaround and response time of the first process
    int waitTime[n], turnaroundTime[n], responseTime[n];
    waitTime[0] = 0;
    responseTime[0] = 0;
    turnaroundTime[0] = arr[0].burstTime; 

    // Initializing the remaining burst time of the processes
    int remainingBurstTime[n];
    int i;
    for(i = 0; i < n; i++) {
        remainingBurstTime[i] = arr[i].burstTime;
    }

    // Implementing the Round Robin Scheduling Algorithm
    int t = 0;
    int flag = 0;
    while(1) {
        flag = 0;
        for(i = 0; i < n; i++) {
            // If the remaining burst time of the process is greater than zero, continue
            if(remainingBurstTime[i] > 0) {
                flag = 1;
                // If the remaining burst time of the process is greater than quantum, subtract quantum
                if(remainingBurstTime[i] > quantum) {
                    t += quantum;
                    remainingBurstTime[i] -= quantum;
                }
                // If the remaining burst time of the process is less than or equal to quantum, process will complete
                else {
                    t += remainingBurstTime[i];
                    waitTime[i] = t - arr[i].burstTime - arr[i].arrTime;
                    remainingBurstTime[i] = 0; 
                }
            }
        }
        // If all processes are completed, break the loop
        if(flag == 0) {
            break;
        }
    }

    // Calculating the turnaround time and response time of each process
    for(i = 0; i < n; i++) {
        turnaroundTime[i] = arr[i].burstTime + waitTime[i];
        responseTime[i] = waitTime[i];
    }

    // Calculating the average waiting time, turnaround time and response time
    float avgWaitTime = 0;
    float avgTurnaroundTime = 0;
    float avgResponseTime = 0;

    for(i = 0; i < n; i++) {
        avgWaitTime += waitTime[i];
        avgTurnaroundTime += turnaroundTime[i];
        avgResponseTime += responseTime[i];
    }

    avgWaitTime /= n;
    avgTurnaroundTime /= n;
    avgResponseTime /= n;

    // Printing the results
    printf("\nSherlock Holmes was solving a case in the Baker Street when he heard a sound... \nHe found a bottle with an important message inside it...\n\n");
    printf("\t\t ROUND ROBIN SCHEDULING ALGORITHM \n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("| Process ID\t| Arrival Time\t| Burst Time\t| Priority\t| Waiting Time\t| Turnaround Time  | Response Time  |\n");
    printf("--------------------------------------------------------------------------------------------------------\n");

    for(i = 0; i < n; i++) {
        printf("| P%d\t\t| %d\t\t| %d\t\t| %d\t\t| %d\t\t| %d\t\t   | %d\t\t  |\n", arr[i].pid, arr[i].arrTime, arr[i].burstTime, arr[i].priority, waitTime[i], turnaroundTime[i], responseTime[i]);
    }

    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("Average Waiting Time: %.2f\n", avgWaitTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
    printf("Average Response Time: %.2f\n\n", avgResponseTime);
}

// Function to implement the Priority Scheduling Algorithm
void priorityScheduling(struct Process* arr, int n) {
    // Initializing the waiting, turnaround and response time of the first process
    int waitTime[n], turnaroundTime[n], responseTime[n];
    waitTime[0] = 0;
    responseTime[0] = 0;
    turnaroundTime[0] = arr[0].burstTime; 

    // Initializing the remaining burst time of the processes
    int remainingBurstTime[n];
    int i;
    for(i = 0; i < n; i++) {
        remainingBurstTime[i] = arr[i].burstTime;
    }

    // Implementing the Priority Scheduling Algorithm
    int j, minPriority, index;
    for(i = 0; i < n-1; i++) {
        minPriority = arr[i].priority;
        index = i;
        for(j = i+1; j < n; j++) {
            if(arr[j].priority < minPriority) {
                minPriority = arr[j].priority;
                index = j;
            }
        }
        swap(&arr[i], &arr[index]);
    }

    int t = 0;
    for(i = 1; i < n; i++) {
        // Subtracting the burst time of the process from the current time
        t += arr[i-1].burstTime;
        waitTime[i] = t - arr[i].arrTime;
        if(waitTime[i] < 0) {
            waitTime[i] = 0;
        }
        turnaroundTime[i] = arr[i].burstTime + waitTime[i];
        responseTime[i] = waitTime[i];
    }

    // Calculating the average waiting time, turnaround time and response time
    float avgWaitTime = 0;
    float avgTurnaroundTime = 0;
    float avgResponseTime = 0;

    for(i = 0; i < n; i++) {
        avgWaitTime += waitTime[i];
        avgTurnaroundTime += turnaroundTime[i];
        avgResponseTime += responseTime[i];
    }

    avgWaitTime /= n;
    avgTurnaroundTime /= n;
    avgResponseTime /= n;

    // Printing the results
    printf("\nSherlock Holmes was checking the messages on website when he saw an urgent mail...\n\n");
    printf("\t\t PRIORITY SCHEDULING ALGORITHM \n");
    printf("---------------------------------------------------------------------------------------------\n");
    printf("| Process ID\t| Arrival Time\t| Burst Time\t| Priority\t| Waiting Time\t| Turnaround Time  | Response Time  |\n");
    printf("---------------------------------------------------------------------------------------------\n");

    for(i = 0; i < n; i++) {
        printf("| P%d\t\t| %d\t\t| %d\t\t| %d\t\t| %d\t\t| %d\t\t   | %d\t\t  |\n", arr[i].pid, arr[i].arrTime, arr[i].burstTime, arr[i].priority, waitTime[i], turnaroundTime[i], responseTime[i]);
    }

    printf("---------------------------------------------------------------------------------------------\n");
    printf("Average Waiting Time: %.2f\n", avgWaitTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
    printf("Average Response Time: %.2f\n\n", avgResponseTime);
}

// Main function
int main() {
    // Defining and initializing the processes
    int n = 5;
    struct Process arr[n];
    arr[0].pid = 1; arr[0].arrTime = 0; arr[0].burstTime = 5; arr[0].priority = 3;
    arr[1].pid = 2; arr[1].arrTime = 1; arr[1].burstTime = 3; arr[1].priority = 1;
    arr[2].pid = 3; arr[2].arrTime = 2; arr[2].burstTime = 8; arr[2].priority = 2;
    arr[3].pid = 4; arr[3].arrTime = 3; arr[3].burstTime = 6; arr[3].priority = 4;
    arr[4].pid = 5; arr[4].arrTime = 4; arr[4].burstTime = 4; arr[4].priority = 1;

    printf("Sherlock Holmes received a message from Dr. Watson about the arrival of new processes...\n");

    // Sorting the processes based on arrival time
    sortArrivalTime(arr, n);

    // Implementing the Round Robin Scheduling Algorithm
    int quantum = 2;
    roundRobinScheduling(arr, n, quantum);

    // Implementing the Priority Scheduling Algorithm
    priorityScheduling(arr, n);

    return 0;
}