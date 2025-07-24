//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a task
struct task {
    char taskName[50];
    int priority;
    int startTime;
};

// Define function to schedule and execute tasks
void scheduleTasks(struct task *taskList, int numTasks) {
    int totalDuration = 0;
    int i, j;

    // Calculate total duration of all tasks
    for (i = 0; i < numTasks; i++) {
        totalDuration += taskList[i].startTime;
    }

    // Sort the task list by priority (highest priority first) and start time (earliest start time first)
    for (i = 0; i < numTasks; i++) {
        for (j = i+1; j < numTasks; j++) {
            if (taskList[i].priority < taskList[j].priority) {
                struct task temp = taskList[i];
                taskList[i] = taskList[j];
                taskList[j] = temp;
            }
            else if (taskList[i].priority == taskList[j].priority && taskList[i].startTime > taskList[j].startTime) {
                struct task temp = taskList[i];
                taskList[i] = taskList[j];
                taskList[j] = temp;
            }
        }
    }

    // Execute tasks in order of priority and start time
    for (i = 0; i < numTasks; i++) {
        printf("%s scheduled...\n", taskList[i].taskName);
        printf("%s executing...\n", taskList[i].taskName);
        printf("%s complete!\n", taskList[i].taskName);
    }

    printf("All tasks complete!\n");
}

int main() {

    /* The case of the missing task scheduler */

    printf("Greetings, Dr. Watson. I have been tasked by the renowned detective Sherlock Holmes to solve the case of the missing task scheduler.\n\n");

    // Create task list
    int numTasks = 3;
    struct task taskList[3];

    // Populate task list
    strcpy(taskList[0].taskName, "Interview Suspect 1");
    taskList[0].priority = 2;
    taskList[0].startTime = 15;
    strcpy(taskList[1].taskName, "Gather Evidence");
    taskList[1].priority = 3;
    taskList[1].startTime = 20;
    strcpy(taskList[2].taskName, "Interview Suspect 2");
    taskList[2].priority = 1;
    taskList[2].startTime = 10;

    // Schedule tasks
    scheduleTasks(taskList, numTasks);

    printf("\nAs you can see, Dr. Watson, the task scheduler has been successfully found and utilized. If you encounter any further mysteries, do not hesitate to call upon me.\n");

    return 0;
}