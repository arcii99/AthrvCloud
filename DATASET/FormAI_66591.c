//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define MAX_PROCESSES 10
#define MAX_QUEUE 5
 
/* Defining structure for Process */
typedef struct {
    int process_id;
    int burst_time;
    int priority;
    float waiting_time;
    float turnaround_time;
    int remaining_burst_time;
} Process;
 
/* Creating global variables */
Process L1_Queue[MAX_QUEUE], L2_Queue[MAX_QUEUE], L3_Queue[MAX_QUEUE];
int L1_Front = -1, L2_Front = -1, L3_Front = -1, L1_Rear = -1, L2_Rear = -1, L3_Rear = -1;
Process process_list[MAX_PROCESSES], L1_Executing, L2_Executing, L3_Executing;
int num_processes, L1_count = 1, L2_count = 1, L3_count = 1;
float avg_wt, avg_tat;
 
/* Creating functions */
void *execute_L1(void *args);
void *execute_L2(void *args);
void *execute_L3(void *args);
void round_robin(Process *p, int quantum, int front, int rear);
int insert(Process *data, int *front, int *rear);
Process remove_process(Process *queue, int *front);
void print_queue(Process *queue, int front, int rear);
 
int main() {
    pthread_t tid_L1, tid_L2, tid_L3;
    int time_quantum_L1, time_quantum_L2, count, i;
 
    /* Input values from user */
    printf("\nEnter the number of processes:");
    scanf("%d", &num_processes);
 
    for(i=0;i<num_processes;i++) {
        printf("\nEnter the burst time of process %d: ", i+1);
        scanf("%d", &process_list[i].burst_time);
 
        printf("Enter the priority of process %d: ", i+1);
        scanf("%d", &process_list[i].priority);
 
        process_list[i].process_id = i+1;
        process_list[i].remaining_burst_time = process_list[i].burst_time;
    }
 
    /* Setting execute_L1 thread with priority 1 */
    pthread_attr_t attr;
    struct sched_param param;
    pthread_attr_init(&attr);
    pthread_attr_setschedpolicy(&attr, SCHED_FIFO);
    param.sched_priority = 1;
    pthread_attr_setschedparam(&attr, &param);
 
    /* Creating threads for all the levels */
    time_quantum_L1 = 4;
    pthread_create(&tid_L1, &attr, execute_L1, &time_quantum_L1);
 
    /* Setting execute_L2 thread with priority 2 */
    param.sched_priority = 2;
    pthread_attr_setschedparam(&attr, &param);
    time_quantum_L2 = 6;
    pthread_create(&tid_L2, &attr, execute_L2, &time_quantum_L2);
 
    /* Setting execute_L3 thread with priority 3 */
    param.sched_priority = 3;
    pthread_attr_setschedparam(&attr, &param);
    pthread_create(&tid_L3, &attr, execute_L3, NULL);
 
    /* Waiting for all threads to complete */
    pthread_join(tid_L1, NULL);
    pthread_join(tid_L2, NULL);
    pthread_join(tid_L3, NULL);
 
    /* Display output */
    printf("\n\nAverage Waiting Time: %0.2f\n", avg_wt/num_processes);
    printf("Average Turnaround Time: %0.2f\n", avg_tat/num_processes);
 
    return 0;
}
 
/* Function to execute processes in Level-1 */
void *execute_L1(void *args) {
    int time_quantum = *(int *)args;
    int i, j, m=0;
    int num_executed_L1 = 0;
    Process current_process;
 
    while(L1_Front!=L1_Rear || L1_Executing.remaining_burst_time>0) {
        if(L1_Front!=-1 && L1_Executing.remaining_burst_time<=0) {
            L1_Executing = remove_process(L1_Queue, &L1_Front);
            num_executed_L1 += 1;
        }
 
        /* Inserting new processes in Level-1 */
        for(i=m;i<num_processes;i++) {
            if(process_list[i].priority >= 1 && process_list[i].priority <= 3) {
                insert(&process_list[i], &L1_Front, &L1_Rear);
                m++;
            }
        }
 
        /* Executing process */
        if(L1_Executing.remaining_burst_time>0) {
            round_robin(&L1_Executing, time_quantum, L1_Front, L1_Rear);
            L1_Executing.priority += 1;
            if(L1_Executing.remaining_burst_time<=0) {
                num_executed_L1 += 1;
            }
        }
 
        /* Moving processes from Level-1 to Level-2 */
        if(L1_Executing.priority>3 && L1_Executing.remaining_burst_time>0) {
            Process temp = L1_Executing;
            L1_Executing = remove_process(L1_Queue, &L1_Front);
            insert(&temp, &L2_Front, &L2_Rear);
        }
 
        /* Moving a process from Level-1 to Level-3 as per aging */
        for(j=L1_Front;j<=L1_Rear;j++) {
            L1_Queue[j].waiting_time += 1;
            if(L1_Queue[j].waiting_time>5 && L1_Queue[j].remaining_burst_time>0) {
                Process p = remove_process(L1_Queue, &L1_Front);
                insert(&p, &L3_Front, &L3_Rear);
            }
        }
 
        /* Waiting for 1 second */
        sleep(1);
    }
 
    avg_wt += L1_Executing.waiting_time;
    avg_tat += L1_Executing.turnaround_time;
    printf("\n\nProcesses executed in Level-1: %d", num_executed_L1);
 
    /* Executing Level-2 */
    execute_L2(args);
}
 
/* Function to execute processes in Level-2 */
void *execute_L2(void *args) {
    int time_quantum = *(int *)args;
    int i, j, m=0;
    int num_executed_L2 = 0;
    Process temp;
 
    while(L2_Front!=L2_Rear || L2_Executing.remaining_burst_time>0) {
        if(L2_Front!=-1 && L2_Executing.remaining_burst_time<=0) {
            L2_Executing = remove_process(L2_Queue, &L2_Front);
            num_executed_L2 += 1;
        }
 
        /* Inserting new processes in Level-2 */
        for(i=m;i<num_processes;i++) {
            if(process_list[i].priority >= 4 && process_list[i].priority <= 6) {
                insert(&process_list[i], &L2_Front, &L2_Rear);
                m++;
            }
        }
 
        /* Executing process */
        if(L2_Executing.remaining_burst_time>0) {
            round_robin(&L2_Executing, time_quantum, L2_Front, L2_Rear);
            L2_Executing.priority += 1;
            if(L2_Executing.remaining_burst_time<=0) {
                num_executed_L2 += 1;
            }
        }
 
        /* Moving a process from Level-2 to Level-3 as per aging */
        for(j=L2_Front;j<=L2_Rear;j++) {
            L2_Queue[j].waiting_time += 1;
            if(L2_Queue[j].waiting_time>5 && L2_Queue[j].remaining_burst_time>0) {
                Process p = remove_process(L2_Queue, &L2_Front);
                insert(&p, &L3_Front, &L3_Rear);
            }
        }
 
        /* Moving a process from Level-2 to Level-1 if its priority becomes less than 4 */
        if(L2_Executing.priority<4 && L2_Executing.remaining_burst_time>0) {
            temp = L2_Executing;
            L2_Executing = remove_process(L2_Queue, &L2_Front);
            insert(&temp, &L1_Front, &L1_Rear);
        }
 
        /* Waiting for 1 second */
        sleep(1);
    }
 
    avg_wt += L2_Executing.waiting_time;
    avg_tat += L2_Executing.turnaround_time;
    printf("\n\nProcesses executed in Level-2: %d", num_executed_L2);
 
    /* Executing Level-3 */
    execute_L3(args);
}
 
/* Function to execute processes in Level-3 */
void *execute_L3(void *args) {
    int i, j, m=0, num_executed_L3 = 0;
 
    while(L3_Front!=L3_Rear || L3_Executing.remaining_burst_time>0) {
        if(L3_Front!=-1 && L3_Executing.remaining_burst_time<=0) {
            L3_Executing = remove_process(L3_Queue, &L3_Front);
            num_executed_L3 += 1;
        }
 
        /* Inserting new processes in Level-3 */
        for(i=m;i<num_processes;i++) {
            if(process_list[i].priority >= 7 && process_list[i].priority <= 10) {
                insert(&process_list[i], &L3_Front, &L3_Rear);
                m++;
            }
        }
 
        /* Executing process */
        if(L3_Executing.remaining_burst_time>0) {
            L3_Executing.remaining_burst_time -= 1;
            L3_Executing.priority += 1;
            if(L3_Executing.remaining_burst_time<=0) {
                num_executed_L3 += 1;
            }
        }
 
        /* Moving a process from Level-3 to Level-2 if its priority becomes less than 7 */
        if(L3_Executing.priority<7 && L3_Executing.remaining_burst_time>0) {
            Process temp = L3_Executing;
            L3_Executing = remove_process(L3_Queue, &L3_Front);
            insert(&temp, &L2_Front, &L2_Rear);
        }
 
        /* Waiting for 1 second */
        sleep(1);
    }
 
    avg_wt += L3_Executing.waiting_time;
    avg_tat += L3_Executing.turnaround_time;
    printf("\n\nProcesses executed in Level-3: %d", num_executed_L3);
}
 
/* Function for round robin scheduling */
void round_robin(Process *p, int quantum, int front, int rear) {
    int remaining_time = p->remaining_burst_time;
 
    /* Executing process with time quantum 'quantum' */
    if(remaining_time>quantum) {
        p->remaining_burst_time -= quantum;
        for(int i=0;i<quantum;i++) {
            sleep(1);
            for(int j=front;j<=rear;j++) {
                if(p->process_id!=L1_Executing.process_id && p->process_id!=L2_Executing.process_id && p->process_id!=L3_Executing.process_id) {
                    process_list[j].waiting_time += 1;
                }
            }
        }
    }
 
    /* Executing remaining part of the process */
    else {
        p->remaining_burst_time -= remaining_time;
        for(int i=0;i<remaining_time;i++) {
            sleep(1);
            for(int j=front;j<=rear;j++) {
                if(p->process_id!=L1_Executing.process_id && p->process_id!=L2_Executing.process_id && p->process_id!=L3_Executing.process_id) {
                    process_list[j].waiting_time += 1;
                }
            }
        }
 
        /* Calculating waiting time and turnaround time */
        p->turnaround_time += p->waiting_time + p->burst_time;
        avg_wt += p->waiting_time;
        avg_tat += p->turnaround_time;
    }
}
 
/* Function to insert a process into the queue */
int insert(Process *data, int *front, int *rear) {
    if((*front == 0 && *rear == MAX_QUEUE - 1) || (*front == *rear + 1)){
        return -1; /* Queue overflow */
    }
    if(*front == -1) {
        *front = 0;
        *rear = 0;
    } else {
        if(*rear == MAX_QUEUE - 1) {
            *rear = 0;
        } else {
            *rear = *rear + 1;
        }
    }
    if(data->priority >= 1 && data->priority <= 3) {
        L1_Queue[*rear] = *data;
        L1_Queue[*rear].waiting_time = 0;
    }
    else if(data->priority >= 4 && data->priority <= 6) {
        L2_Queue[*rear] = *data;
        L2_Queue[*rear].waiting_time = 0;
    }
    else {
        L3_Queue[*rear] = *data;
        L3_Queue[*rear].waiting_time = 0;
    }
    return 0;
}
 
/* Function to remove a process from the queue */
Process remove_process(Process *queue, int *front) {
    Process data;
    if(*front == -1) {
        return data; /* Queue underflow */
    }
 
    data = queue[*front];
    if(*front == 0 && *front == MAX_QUEUE - 1) {
        *front = -1;
    } else {
        if(*front == MAX_QUEUE - 1) {
            *front = 0;
        } else {
            *front = *front + 1;
        }
    }
    return data;
}
 
/* Function to print the queue */
void print_queue(Process *queue, int front, int rear) {
    if(front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("\n\nThe current queue is: ");
    if(rear >= front) {
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i].process_id);
        }
    }
    else {
        for(int i=front;i<MAX_QUEUE;i++){
            printf("%d ",queue[i].process_id);
        }
        for(int i=0;i<=rear;i++){
            printf("%d ",queue[i].process_id);
        }
    }
}