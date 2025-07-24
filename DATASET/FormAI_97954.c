//FormAI DATASET v1.0 Category: Task Scheduler ; Style: scientific
/* Task Scheduler Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10 // maximum number of tasks supported by the program
#define TIME_LIMIT 60 // time limit in seconds for the program to run
#define MIN_TIME 5 // minimum time for a task in seconds
#define MAX_TIME 20 // maximum time for a task in seconds

/* Data Structure for holding a task */
typedef struct {
    int id; // task ID (unique)
    int time; // time required for the task in seconds
} Task;

/* Data structure for holding a list of tasks */
typedef struct {
    int length; // length of the list of tasks
    Task task_list[MAX_TASKS]; // list of tasks
} TaskList;

/* Function Prototypes */
void create_task_list(TaskList *task_list);
void print_task_list(TaskList task_list);
void schedule_tasks(TaskList task_list);

/* Main Function */
int main(void){
    TaskList task_list;
    srand(time(NULL)); // seed the random number generator
    
    create_task_list(&task_list); // create a list of tasks
    print_task_list(task_list); // print the list of tasks
    schedule_tasks(task_list); // schedule the tasks
    
    return 0;
}

/* Function to create a list of tasks */
void create_task_list(TaskList *task_list){
    int i;
    int time;
    task_list->length = rand() % MAX_TASKS + 1; // choose a random length for the list 
    
    for(i=0;i<task_list->length;i++){
        task_list->task_list[i].id = i+1; // assign a unique ID to each task
        time = rand() % (MAX_TIME - MIN_TIME + 1) + MIN_TIME; // choose random time between MIN_TIME and MAX_TIME
        task_list->task_list[i].time = time;
    }
}

/* Function to print a list of tasks */
void print_task_list(TaskList task_list){
    int i;
    
    printf("List of Tasks:\n");
    printf("ID \t Time\n");
    for(i=0;i<task_list.length;i++){
        printf("%d \t %d seconds\n", task_list.task_list[i].id, task_list.task_list[i].time);
    }
    printf("\n");
}

/* Function to schedule a list of tasks */
void schedule_tasks(TaskList task_list){
    int i;
    int current_time = 0; // the current time
    int completed_tasks = 0; // number of tasks completed
    
    printf("Task Execution Order:\n");
    while(current_time < TIME_LIMIT && completed_tasks < task_list.length){
        for(i=0;i<task_list.length;i++){
            if(task_list.task_list[i].time <= (TIME_LIMIT - current_time)){
                printf("Task %d completed\n", task_list.task_list[i].id);
                current_time += task_list.task_list[i].time;
                completed_tasks++;
            }
        }
    }
    printf("\n");
}