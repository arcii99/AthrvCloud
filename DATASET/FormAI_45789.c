//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_BURST_TIME 10
#define QUANTUM 2

typedef struct {
    int pid;
    int burst_time;
    int arrival_time;
    int turnaround_time;
    int waiting_time;
} Process;

int round_robin(Process processes[]);
int shortest_job_first(Process processes[]);
void print_process_table(Process processes[]);
void calculate_turnaround_time(Process processes[]);
void calculate_waiting_time(Process processes[]);

int main() {
    srand(time(NULL)); // Seed random number generator
    Process processes[MAX_PROCESSES]; // Create array of processes

    // Initialize processes with random arrival times and burst times
    for(int i = 0; i < MAX_PROCESSES; i++) {
        processes[i].pid = i;
        processes[i].arrival_time = rand() % 10; // Random arrival time between 0-9
        processes[i].burst_time = rand() % MAX_BURST_TIME + 1; // Random burst time between 1-10
    }

    printf("INITIAL PROCESS TABLE:\n");
    print_process_table(processes);

    int total_turnaround_time_rr = round_robin(processes);
    int total_turnaround_time_sjf = shortest_job_first(processes);

    calculate_waiting_time(processes);
    calculate_turnaround_time(processes);

    printf("\nFINAL PROCESS TABLE:\n");
    print_process_table(processes);

    printf("\nROUND ROBIN\nTotal turnaround time: %d\nAverage turnaround time: %.2f\n", total_turnaround_time_rr, (float) total_turnaround_time_rr / MAX_PROCESSES);
    printf("\nSHORTEST JOB FIRST\nTotal turnaround time: %d\nAverage turnaround time: %.2f\n", total_turnaround_time_sjf, (float) total_turnaround_time_sjf / MAX_PROCESSES);
    
    return 0;
}

int round_robin(Process processes[]) {
    printf("\nROUND ROBIN\n");

    int total_turnaround_time = 0;
    int executed_processes = 0;

    // Create a copy of the processes array and sort it by arrival time
    Process processes_copy[MAX_PROCESSES];
    for(int i = 0; i < MAX_PROCESSES; i++) {
        processes_copy[i] = processes[i];
    }
    for(int i = 0; i < MAX_PROCESSES-1; i++) {
        for(int j = i+1; j < MAX_PROCESSES; j++) {
            if(processes_copy[j].arrival_time < processes_copy[i].arrival_time) {
                Process temp = processes_copy[i];
                processes_copy[i] = processes_copy[j];
                processes_copy[j] = temp;
            }
        }
    }

    int current_time = processes_copy[0].arrival_time;
    int queue[MAX_PROCESSES]; // Create queue to store processes
    int queue_front = 0, queue_rear = 0;
    int time_quantum_counter = 0;

    queue[queue_rear++] = processes_copy[0].pid; // Add first process to queue
    processes_copy[0].burst_time -= QUANTUM;

    while(executed_processes < MAX_PROCESSES) {
        if(queue_front != queue_rear) {
            // Get next process from queue
            int pid = queue[queue_front++];
            Process* process = &processes_copy[pid];

            if(process->burst_time <= 0) {
                // Process has finished executing
                current_time += process->burst_time + QUANTUM;
                total_turnaround_time += current_time - process->arrival_time;
                executed_processes++;
            } else if(time_quantum_counter >= QUANTUM) {
                // Time quantum has been reached, move process to end of queue
                queue[queue_rear++] = pid;
                time_quantum_counter = 0;
            } else {
                // Execute process for one time quantum
                printf("Time: %d | Executing process %d\n", current_time, process->pid);
                process->burst_time -= 1;
                current_time += 1;
                time_quantum_counter += 1;
                // If another process arrives during current time quantum, add it to queue
                for(int i = queue_rear; i < MAX_PROCESSES; i++) {
                    if(processes_copy[i].arrival_time <= current_time && processes_copy[i].burst_time > 0) {
                        queue[queue_rear++] = processes_copy[i].pid;
                    }
                }
            }
        } else {
            // Queue is empty, find next process to add to queue
            for(int i = 0; i < MAX_PROCESSES; i++) {
                if(processes_copy[i].arrival_time > current_time && processes_copy[i].burst_time > 0) {
                    current_time = processes_copy[i].arrival_time;
                    queue[queue_rear++] = processes_copy[i].pid;
                    break;
                }
            }
        }
    }

    return total_turnaround_time;
}

int shortest_job_first(Process processes[]) {
    printf("\nSHORTEST JOB FIRST\n");

    int total_turnaround_time = 0;
    int executed_processes = 0;

    // Create a copy of the processes array and sort it by arrival time
    Process processes_copy[MAX_PROCESSES];
    for(int i = 0; i < MAX_PROCESSES; i++) {
        processes_copy[i] = processes[i];
    }
    for(int i = 0; i < MAX_PROCESSES-1; i++) {
        for(int j = i+1; j < MAX_PROCESSES; j++) {
            if(processes_copy[j].arrival_time < processes_copy[i].arrival_time) {
                Process temp = processes_copy[i];
                processes_copy[i] = processes_copy[j];
                processes_copy[j] = temp;
            }
        }
    }

    int current_time = processes_copy[0].arrival_time;
    int shortest_job_index = 0;

    while(executed_processes < MAX_PROCESSES) {
        int shortest_job_burst_time = MAX_BURST_TIME + 1;

        // Find shortest job that has arrived
        for(int i = 0; i < MAX_PROCESSES; i++) {
            if(processes_copy[i].arrival_time <= current_time && processes_copy[i].burst_time > 0 && processes_copy[i].burst_time < shortest_job_burst_time) {
                shortest_job_index = i;
                shortest_job_burst_time = processes_copy[i].burst_time;
            }
        }

        Process* process = &processes_copy[shortest_job_index];
        printf("Time: %d | Executing process %d\n", current_time, process->pid);

        process->burst_time -= 1;
        current_time += 1;

        if(process->burst_time <= 0) {
            // Process has finished executing
            total_turnaround_time += current_time - process->arrival_time;
            executed_processes++;
        }
    }

    return total_turnaround_time;
}

void print_process_table(Process processes[]) {
    printf("+-----+------------+--------------+-----------------+\n");
    printf("| PID | Arrival    | Burst Time   | Turnaround Time | Waiting Time    |\n");
    printf("+-----+------------+--------------+-----------------+\n");
    for(int i = 0; i < MAX_PROCESSES; i++) {
        printf("| %-3d | %-10d | %-12d | %-15d | %-15d |\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
    printf("+-----+------------+--------------+-----------------+\n");
}

void calculate_turnaround_time(Process processes[]) {
    for(int i = 0; i < MAX_PROCESSES; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void calculate_waiting_time(Process processes[]) {
    // Calculate waiting time for Round Robin
    int queue[MAX_PROCESSES];
    int queue_front = 0, queue_rear = 0;
    int time_quantum_counter = 0;
    int current_time = processes[0].arrival_time;

    // Create a copy of the processes array and sort it by arrival time
    Process processes_copy[MAX_PROCESSES];
    for(int i = 0; i < MAX_PROCESSES; i++) {
        processes_copy[i] = processes[i];
    }
    for(int i = 0; i < MAX_PROCESSES-1; i++) {
        for(int j = i+1; j < MAX_PROCESSES; j++) {
            if(processes_copy[j].arrival_time < processes_copy[i].arrival_time) {
                Process temp = processes_copy[i];
                processes_copy[i] = processes_copy[j];
                processes_copy[j] = temp;
            }
        }
    }

    queue[queue_rear++] = processes_copy[0].pid; // Add first process to queue
    processes_copy[0].burst_time -= QUANTUM;

    while(queue_front != queue_rear) {
        // Get next process from queue
        int pid = queue[queue_front++];
        Process* process = &processes_copy[pid];

        if(process->burst_time <= 0) {
            // Process has finished executing
            current_time += process->burst_time + QUANTUM;
            // If process finished in less than a time quantum, add remaining time to waiting time
            process->waiting_time += QUANTUM + process->burst_time;
        } else if(time_quantum_counter >= QUANTUM) {
            // Time quantum has been reached, move process to end of queue
            queue[queue_rear++] = pid;
            time_quantum_counter = 0;
        } else {
            // Execute process for one time quantum
            current_time += 1;
            time_quantum_counter += 1;
            // If another process arrives during current time quantum, add it to queue
            for(int i = queue_rear; i < MAX_PROCESSES; i++) {
                if(processes_copy[i].arrival_time <= current_time && processes_copy[i].burst_time > 0) {
                    queue[queue_rear++] = processes_copy[i].pid;
                }
            }
        }
    }

    // Calculate waiting time for Shortest Job First
    for(int i = 0; i < MAX_PROCESSES; i++) {
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
}