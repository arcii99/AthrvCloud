//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define QUANTUM 4 //Configurable Quantum
#define PROCESSES 5 //Configurable number of processes

int total_time = 0, total_wait_time = 0;
int queue[PROCESSES], front = -1, rear = -1; //Using Queue data structure for ready queue

struct Process{
    int pid;
    int burst_time;
    int arrival_time;
    int wait_time;
    int turnaround_time;
    int remaining_time;
}process[PROCESSES];

void enqueue(int pid){ //Function to add process to the ready queue
    if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = pid;
    }
    else{
        rear++;
        queue[rear] = pid;
    }
}

int dequeue(){ //Function to remove process from the ready queue
    int pid = queue[front];
    if(front == rear){
        front = rear = -1;
    }
    else{
        front++;
    }
    return pid;
}

int isQueueEmpty(){ //Function to check if ready queue is empty
    if(front == -1 && rear == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void initialize(){ //Initializing process parameters
    for(int i=0; i<PROCESSES; i++){
        process[i].pid = i+1;
        process[i].arrival_time = rand()%10 + total_time; //Random arrival_time for each process
        process[i].burst_time = rand()%10 + 1; //Random burst_time for each process, ranging from 1 to 10
        process[i].remaining_time = process[i].burst_time;
        process[i].wait_time = 0;
        process[i].turnaround_time = 0;
    }
}

void sort_by_arrival_time(){ //Function to sort processes by their arrival_time
    int i, j;
    struct Process temp;
    for(i=0; i<PROCESSES-1; i++){
        for(j=i+1; j<PROCESSES; j++){
            if(process[i].arrival_time > process[j].arrival_time){
                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }
}

void round_robin(){ //Round Robin Scheduling Algorithm
    int time_quantum = QUANTUM; //Assigning time_quantum as per the configured quantum
    while(!isQueueEmpty()){ //Processing the ready queue while it is not empty
        int pid = dequeue(); //Removing process from the ready queue
        if(process[pid-1].remaining_time <= time_quantum){ //Process completes execution within the time_quantum
            total_time += process[pid-1].remaining_time; //Updating total_time
            process[pid-1].remaining_time = 0;
            process[pid-1].turnaround_time = total_time - process[pid-1].arrival_time;
            process[pid-1].wait_time = process[pid-1].turnaround_time - process[pid-1].burst_time;
            total_wait_time += process[pid-1].wait_time;
        }
        else{ //Process still has some burst time left after current execution
            total_time += time_quantum; //Updating total_time
            process[pid-1].remaining_time -= time_quantum;
            enqueue(pid); //Adding process back to the ready queue
        }
    }
}

void display(){ //Function to display process scheduling parameters
    printf("PID\tArrival Time\tBurst Time\tWait Time\tTurnaround Time\n");
    for(int i=0; i<PROCESSES; i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", process[i].pid, process[i].arrival_time, process[i].burst_time, process[i].wait_time, process[i].turnaround_time);
    }
    printf("Average Waiting Time: %f\n", (float)total_wait_time/PROCESSES); //Calculating and displaying average waiting time
}

int main(){
    srand(time(0)); //Seeding rand() with time(0)
    initialize();
    sort_by_arrival_time();
    round_robin();
    display();
    return 0;
}