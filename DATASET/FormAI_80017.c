//FormAI DATASET v1.0 Category: Task Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100
#define NAME_LEN 30

//Task structure
typedef struct {
    char name[NAME_LEN];
    int priority;
    time_t time_created;
    time_t time_completed;
} Task;

//Scheduler structure
typedef struct {
    Task tasks[MAX_TASKS];
    int num_tasks;
} Scheduler;

//Function to create a new task
Task create_task(char* name, int priority) {
    Task t;
    strncpy(t.name, name, NAME_LEN);
    t.priority = priority;
    t.time_created = time(NULL);
    t.time_completed = 0;
    return t;
}

//Function to add task to scheduler
void add_task(Scheduler* s, Task t) {
    if(s->num_tasks >= MAX_TASKS) {
        printf("Scheduler is full!\n");
        return;
    }
    s->tasks[s->num_tasks++] = t;
}

//Function to print all tasks in scheduler
void print_tasks(Scheduler* s) {
    if(s->num_tasks == 0) {
        printf("No tasks in scheduler!\n");
        return;
    }
    printf("TASK NAME\tPRIORITY\tTIME CREATED\tTIME COMPLETED\n");
    for(int i=0; i<s->num_tasks; i++) {
        printf("%s\t\t%d\t\t%ld\t\t", s->tasks[i].name, s->tasks[i].priority, s->tasks[i].time_created);
        if(s->tasks[i].time_completed == 0)
            printf("Not Completed\n");
        else
            printf("%ld\n", s->tasks[i].time_completed);
    }
}

//Function to mark task as completed
void complete_task(Scheduler* s, char* name) {
    for(int i=0; i<s->num_tasks; i++) {
        if(strcmp(s->tasks[i].name, name) == 0) {
            s->tasks[i].time_completed = time(NULL);
            printf("Task '%s' completed at %ld\n", name, s->tasks[i].time_completed);
            return;
        }
    }
    printf("Task '%s' not found!\n", name);
}

int main() {
    Scheduler s;
    s.num_tasks = 0;

    //Create and add some tasks
    add_task(&s, create_task("Check email", 3));
    add_task(&s, create_task("Finish report", 1));
    add_task(&s, create_task("Read book", 2));
    add_task(&s, create_task("Go for a run", 4));

    //Print all tasks in scheduler
    print_tasks(&s);

    //Complete a task
    complete_task(&s, "Read book");

    //Print all tasks again
    print_tasks(&s);

    return 0;
}