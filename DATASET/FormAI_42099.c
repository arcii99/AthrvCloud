//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: distributed
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<pthread.h>
#include<string.h>

#define MAX_BURST_TIME 20 
#define MAX_PRIORITY 10 
#define QUANTUM_TIME 1 

void* execute_process(void*); 
void start_execution(); 
int add_process(int, int, int); 
int delete_process(int); 
void print_processes(); 

typedef struct process{
    int pid; 
    int priority; 
    int burst_time; 
    int remaining_time; 
    int waiting_time; 
    int turnaround_time; 
    pthread_t thread; 
    struct process* next; 
} process; 

process* head = NULL; 

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER; 

int main(){
    
    srand(time(0)); 
    
    printf("\nAdding Processes...");
    add_process(1, rand()%MAX_PRIORITY+1, rand()%MAX_BURST_TIME+1); 
    add_process(2, rand()%MAX_PRIORITY+1, rand()%MAX_BURST_TIME+1); 
    add_process(3, rand()%MAX_PRIORITY+1, rand()%MAX_BURST_TIME+1); 
    add_process(4, rand()%MAX_PRIORITY+1, rand()%MAX_BURST_TIME+1); 
    add_process(5, rand()%MAX_PRIORITY+1, rand()%MAX_BURST_TIME+1); 
    
    print_processes(); 
    
    start_execution(); 
    
    printf("\nAll processes executed successfully!\n");
    pthread_exit(NULL); 
}

// Function to add a process to the linked list
int add_process(int pid, int priority, int burst_time){
  
    process *new_process = (process*) malloc(sizeof(process));
    new_process->pid = pid; 
    new_process->priority = priority; 
    new_process->burst_time = burst_time; 
    new_process->remaining_time = burst_time; 
    new_process->waiting_time = 0; 
    new_process->turnaround_time = 0; 
    new_process->next = NULL;
    
    pthread_create(&new_process->thread, NULL, execute_process, (void*)new_process);  
    
    if(!head){
        head = new_process; 
        return 0; 
    }
    
    process* current = head; 
    while(current->next){
        current = current->next; 
    }
    current->next = new_process; 
    return 0; 
}

// Function to delete a process from the linked list
int delete_process(int pid){
    
    if(!head){
        printf("List is empty!\n");
        return 0; 
    }
    
    pthread_mutex_lock(&mutex1); 
    
    process* current = head; 
    if(current->pid == pid){
        printf("Process %d deleted successfully!\n", current->pid); 
        head = head->next; 
        free(current); 
        pthread_mutex_unlock(&mutex1);
        return 0; 
    }
    
    while(current->next){
        if(current->next->pid == pid){
            printf("Process %d deleted successfully!\n", current->next->pid); 
            process* temp = current->next->next; 
            free(current->next); 
            current->next = temp; 
            pthread_mutex_unlock(&mutex1);
            return 0; 
        }   
        current = current->next; 
    }
    
    printf("Process not found!\n");
    pthread_mutex_unlock(&mutex1);
    return 0; 
    
}

// Function to print all the processes in the linked list
void print_processes(){
    
    process* current = head;
    printf("\nProcess Information:");
    printf("\nPID\tPriority\tBurst Time\tRemaining Time\tWaiting Time\tTurnaround Time\n");
    
    while(current){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",current->pid, current->priority, current->burst_time, current->remaining_time, current->waiting_time, current->turnaround_time);
        current = current->next;  
    }
    
    printf("\n");
    
}

// Function to execute a process
void* execute_process(void* process_data){
    
    process* current = (process*)process_data;
    
    while(current->remaining_time){
        if(current->remaining_time <= QUANTUM_TIME){
            sleep(current->remaining_time);
            current->remaining_time = 0; 
        }else{
            sleep(QUANTUM_TIME); 
            current->remaining_time -= QUANTUM_TIME; 
        }
    }
    
    pthread_mutex_lock(&mutex1); 
    
    current->turnaround_time = (int)time(NULL); 
    current->waiting_time = current->turnaround_time - current->burst_time; 
    
    pthread_mutex_unlock(&mutex1); 
    
}

// Function to start the execution of processes
void start_execution(){
    
    printf("\nExecuting Processes...\n"); 
    
    while(head){
        pthread_mutex_lock(&mutex1); 
        
        process* current = head; 
        process* highest_priority_process = current; 
        
        while(current){
            if(current->priority > highest_priority_process->priority){
                highest_priority_process = current; 
            }
            current = current->next; 
        }
        
        pthread_mutex_unlock(&mutex1); 
        
        sleep(QUANTUM_TIME); 
        
        if(highest_priority_process->remaining_time <= QUANTUM_TIME){
            delete_process(highest_priority_process->pid);
        }else{
            pthread_mutex_lock(&mutex1); 
            highest_priority_process->priority -= 1;
            highest_priority_process->remaining_time -= QUANTUM_TIME; 
            pthread_mutex_unlock(&mutex1); 
        }
        
    }
    
}