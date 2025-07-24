//FormAI DATASET v1.0 Category: Task Scheduler ; Style: multivariable
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

//Structure for each task
struct Task {
    int id;
    char name[50];
    int priority;
    int duration;
    int frequency;
};

//Function to insert tasks into the schedule
void insertTask(struct Task *schedule, int *numTasks, struct Task newTask) {
    schedule[*numTasks] = newTask;
    (*numTasks)++;
}

//Function to display the schedule
void displaySchedule(struct Task *schedule, int numTasks) {
    printf("\nCurrent Schedule:\n");
    printf("ID\tPriority\tDuration\tFrequency\tName\n");
    for(int i=0;i<numTasks;i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%s\n", schedule[i].id, schedule[i].priority, schedule[i].duration, schedule[i].frequency, schedule[i].name);
    }
}

//Function to execute a task
void executeTask(struct Task task) {
    printf("\nExecuting task %d: %s\n", task.id, task.name);
    printf("Duration: %d seconds\n", task.duration);
    sleep(task.duration);
    printf("Task %d: %s execution completed\n", task.id, task.name);
}

//Function to reorder the schedule based on priority
void reorderSchedule(struct Task *schedule, int numTasks) {
    int swapped = 1;
    while(swapped) {
        swapped = 0;
        for(int i=0;i<numTasks-1;i++) {
            if(schedule[i].priority > schedule[i+1].priority) {
                struct Task temp = schedule[i];
                schedule[i] = schedule[i+1];
                schedule[i+1] = temp;
                swapped = 1;
            }
        }
    }
}

//Main function
int main() {
    struct Task schedule[100];
    int numTasks = 0;

    //Insert some initial tasks into the schedule
    struct Task t1 = {1, "Task A", 2, 5, 10};
    insertTask(schedule, &numTasks, t1);

    struct Task t2 = {2, "Task B", 1, 8, 5};
    insertTask(schedule, &numTasks, t2);

    struct Task t3 = {3, "Task C", 3, 3, 2};
    insertTask(schedule, &numTasks, t3);

    //Display the schedule
    displaySchedule(schedule, numTasks);

    //Reorder the schedule based on priority
    reorderSchedule(schedule, numTasks);

    //Display the reordered schedule
    displaySchedule(schedule, numTasks);

    //Execute the tasks in order
    for(int i=0;i<numTasks;i++) {
        executeTask(schedule[i]);
    }

    return 0;
}