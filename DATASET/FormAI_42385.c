//FormAI DATASET v1.0 Category: Task Scheduler ; Style: real-life
/*
  This program is a simple example of a task scheduler for a real-life situation. 
  It creates a schedule for a busy executive to manage his tasks throughout the day.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char task_name[50];
    int start_time_hrs;
    int start_time_mins;
    int duration_mins;
} Task;

void schedule_task(Task *tasks, int length);
void print_task(Task *tasks, int length);

int main(){
    Task tasks[5];

    strcpy(tasks[0].task_name, "Check emails");
    tasks[0].start_time_hrs = 9;
    tasks[0].start_time_mins = 0;
    tasks[0].duration_mins = 30;

    strcpy(tasks[1].task_name, "Meeting with team");
    tasks[1].start_time_hrs = 10;
    tasks[1].start_time_mins = 0;
    tasks[1].duration_mins = 60;

    strcpy(tasks[2].task_name, "Lunch");
    tasks[2].start_time_hrs = 12;
    tasks[2].start_time_mins = 0;
    tasks[2].duration_mins = 45;

    strcpy(tasks[3].task_name, "Client call");
    tasks[3].start_time_hrs = 14;
    tasks[3].start_time_mins = 0;
    tasks[3].duration_mins = 30;

    strcpy(tasks[4].task_name, "Project planning");
    tasks[4].start_time_hrs = 15;
    tasks[4].start_time_mins = 0;
    tasks[4].duration_mins = 90;

  	int length = sizeof(tasks)/sizeof(Task); // get the length of the task array
    schedule_task(tasks, length); // schedule the tasks
    print_task(tasks, length); // print the tasks
    
    return 0;
}

// function to schedule the tasks
void schedule_task(Task *tasks, int length){
    for(int i=0; i<length; i++){
        if(i==0){ // if it's the first task
            tasks[i].start_time_hrs = 9;
            tasks[i].start_time_mins = 0;
        } else{ 
            tasks[i].start_time_hrs = tasks[i-1].start_time_hrs; // the task starts after the previous task ends
            tasks[i].start_time_mins = tasks[i-1].start_time_mins + tasks[i-1].duration_mins;
            if(tasks[i].start_time_mins >= 60){ // adjust the hours and minutes if necessary
                tasks[i].start_time_hrs += tasks[i].start_time_mins/60;
                tasks[i].start_time_mins = tasks[i].start_time_mins%60;
            }
        }
    }
}

// function to print the tasks
void print_task(Task *tasks, int length){
    printf("Task Schedule:\n");
    printf("-----------------\n");
    for(int i=0; i<length; i++){
        printf("%s - %d:%d for %d minutes\n", tasks[i].task_name, tasks[i].start_time_hrs, tasks[i].start_time_mins, tasks[i].duration_mins);
    }
    printf("-----------------\n");
}