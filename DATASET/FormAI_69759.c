//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: grateful
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

//Our PCB structure to hold information about processes
struct processControlBlock
{
    int processId;  //unique process id
    int arrivalTime;  //Time at which the process arrived
    int burstTime;  //Time taken by the process to complete execution
    int priority;  //Priority of the process, useful in priority scheduling
    int remainingTime;  //Remaining burst time of the process
};

//Function to swap two processControlBlock objects
void swapProcesses(struct processControlBlock *a, struct processControlBlock *b)
{
    struct processControlBlock temp = *a;
    *a = *b;
    *b = temp;
}

//Function to sort an array of processes based on arrival time
void sortByArrivalTime(struct processControlBlock processes[], int numberOfProcesses)
{
    for(int i = 0; i < numberOfProcesses-1; i++)
    {
        for(int j = 0; j < numberOfProcesses-i-1; j++)
        {
            if(processes[j].arrivalTime > processes[j+1].arrivalTime)
            {
                swapProcesses(&processes[j], &processes[j+1]);
            }
        }
    }
}

//Function to sort an array of processes based on priority
void sortByPriority(struct processControlBlock processes[], int numberOfProcesses)
{
    for(int i = 0; i < numberOfProcesses-1; i++)
    {
        for(int j = 0; j < numberOfProcesses-i-1; j++)
        {
            if(processes[j].priority > processes[j+1].priority)
            {
                swapProcesses(&processes[j], &processes[j+1]);
            }
        }
    }
}

//Function to sort an array of processes based on remaining time
void sortByRemainingTime(struct processControlBlock processes[], int numberOfProcesses)
{
    for(int i = 0; i < numberOfProcesses-1; i++)
    {
        for(int j = 0; j < numberOfProcesses-i-1; j++)
        {
            if(processes[j].remainingTime > processes[j+1].remainingTime)
            {
                swapProcesses(&processes[j], &processes[j+1]);
            }
        }
    }
}

//Function to simulate the execution of processes using Round Robin Scheduling
void simulateRoundRobinScheduling(struct processControlBlock processes[], int numberOfProcesses, int timeQuantum)
{
    printf("Starting Round Robin Scheduling...\n");
    int timeElapsed = 0;
    int completed = 0;
    int currentProcess = -1;
    while(completed != numberOfProcesses)
    {
        //Find the suitable process to execute
        int foundProcess = 0;
        for(int i = 0; i < numberOfProcesses; i++)
        {
            if(processes[i].arrivalTime <= timeElapsed && processes[i].remainingTime > 0)
            {
                currentProcess = i;
                foundProcess = 1;
                break;
            }
        }
        if(!foundProcess)
        {
            //If no process was found to execute, then we wait for one second
            printf("Time Elapsed: %d seconds\n", timeElapsed);
            timeElapsed++;
            continue;
        }
        //Execute the process for the time quantum
        int executionTime = timeQuantum;
        if(processes[currentProcess].remainingTime < timeQuantum)
        {
            executionTime = processes[currentProcess].remainingTime;
        }
        processes[currentProcess].remainingTime -= executionTime;
        timeElapsed += executionTime;
        if(processes[currentProcess].remainingTime <= 0)
        {
            //If the process is complete, then we print the completion time and update the counter
            printf("Process %d completed at time %d\n", processes[currentProcess].processId, timeElapsed);
            processes[currentProcess].remainingTime = 0;
            completed++;
        }
        //Print the status of the process
        printf("Process %d executing from time %d to time %d\n", processes[currentProcess].processId, timeElapsed - executionTime, timeElapsed);
    }
}

//Function to simulate the execution of processes using Priority Scheduling
void simulatePriorityScheduling(struct processControlBlock processes[], int numberOfProcesses)
{
    printf("Starting Priority Scheduling...\n");
    int timeElapsed = 0;
    int completed = 0;
    int currentProcess = -1;
    while(completed != numberOfProcesses)
    {
        //Find the suitable process to execute
        int foundProcess = 0;
        for(int i = 0; i < numberOfProcesses; i++)
        {
            if(processes[i].arrivalTime <= timeElapsed && processes[i].remainingTime > 0)
            {
                currentProcess = i;
                foundProcess = 1;
                break;
            }
        }
        if(!foundProcess)
        {
            //If no process was found to execute, then we wait for one second
            printf("Time Elapsed: %d seconds\n", timeElapsed);
            timeElapsed++;
            continue;
        }
        //Execute the process with the highest priority
        sortByPriority(processes, numberOfProcesses);
        currentProcess = 0;
        while(processes[currentProcess].arrivalTime > timeElapsed || processes[currentProcess].remainingTime <= 0)
        {
            currentProcess++;
        }
        int executionTime = processes[currentProcess].remainingTime;
        processes[currentProcess].remainingTime = 0;
        timeElapsed += executionTime;
        //Print the status of the process
        printf("Process %d executing from time %d to time %d\n", processes[currentProcess].processId, timeElapsed - executionTime, timeElapsed);
        printf("Process %d completed at time %d\n", processes[currentProcess].processId, timeElapsed);
        completed++;
    }
}

//Function to simulate the execution of processes using Shortest Remaining Time First Scheduling
void simulateShortestRemainingTimeFirstScheduling(struct processControlBlock processes[], int numberOfProcesses)
{
    printf("Starting Shortest Remaining Time First Scheduling...\n");
    int timeElapsed = 0;
    int completed = 0;
    int currentProcess = -1;
    while(completed != numberOfProcesses)
    {
        //Find the suitable process to execute
        int foundProcess = 0;
        for(int i = 0; i < numberOfProcesses; i++)
        {
            if(processes[i].arrivalTime <= timeElapsed && processes[i].remainingTime > 0)
            {
                currentProcess = i;
                foundProcess = 1;
                break;
            }
        }
        if(!foundProcess)
        {
            //If no process was found to execute, then we wait for one second
            printf("Time Elapsed: %d seconds\n", timeElapsed);
            timeElapsed++;
            continue;
        }
        //Execute the process with the shortest remaining time
        sortByRemainingTime(processes, numberOfProcesses);
        currentProcess = 0;
        while(processes[currentProcess].arrivalTime > timeElapsed || processes[currentProcess].remainingTime <= 0)
        {
            currentProcess++;
        }
        int executionTime = processes[currentProcess].remainingTime;
        processes[currentProcess].remainingTime = 0;
        timeElapsed += executionTime;
        //Print the status of the process
        printf("Process %d executing from time %d to time %d\n", processes[currentProcess].processId, timeElapsed - executionTime, timeElapsed);
        printf("Process %d completed at time %d\n", processes[currentProcess].processId, timeElapsed);
        completed++;
    }
}

int main()
{
    printf("Welcome to the CPU Scheduling Algorithm Simulator!\n");
    srand(time(NULL));
    printf("Generating random processes...\n");
    struct processControlBlock processes[10];
    for(int i = 0; i < 10; i++)
    {
        processes[i].processId = i+1;
        processes[i].arrivalTime = rand()%10;
        processes[i].burstTime = rand()%7 + 1;
        processes[i].priority = rand()%5 + 1;
        processes[i].remainingTime = processes[i].burstTime;
    }
    printf("Processes generated!\n");
    printf("Printing details of the processes:\n");
    printf("Process ID\tArrival Time\tBurst Time\tPriority\n");
    for(int i = 0; i < 10; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].processId, processes[i].arrivalTime, processes[i].burstTime, processes[i].priority);
    }
    printf("\n\n");
    printf("Select a CPU Scheduling Algorithm:\n1. Round Robin Scheduling\n2. Priority Scheduling\n3. Shortest Remaining Time First Scheduling\n");
    int choice;
    scanf("%d", &choice);
    switch(choice)
    {
        case 1: simulateRoundRobinScheduling(processes, 10, 2);
                break;
        case 2: simulatePriorityScheduling(processes, 10);
                break;
        case 3: simulateShortestRemainingTimeFirstScheduling(processes, 10);
                break;
        default: printf("Invalid choice!\n");
    }
    return 0;
}