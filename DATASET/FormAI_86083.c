//FormAI DATASET v1.0 Category: Task Scheduler ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare a struct to hold information for each task
typedef struct {
  char name[20];
  int priority;
  int time_req;
  int is_completed;
} Task;

// Declare an array of tasks
Task tasks[10];

// Define a function to randomly generate tasks
void generate_tasks() {
  srand(time(NULL));
  char task_names[10][20] = {"Painting a Rainbow", "Flying with Mud Scorpions", "Thinking of Tomorrow", "Killing Time", "Playing with Dynamite", "Dancing with Bears", "Swimming in Lavender", "Fighting Evil Clouds", "Dreaming of Sunsets", "Tangling with Reality"};
  for(int i=0; i<10; i++) {
    // Set the task name
    strcpy(tasks[i].name, task_names[i]);

    // Set the task priority randomly from 1 to 10
    tasks[i].priority = rand() % 10 + 1;

    // Set the time required to complete the task randomly from 1 to 60 seconds
    tasks[i].time_req = rand() % 60 + 1;

    // Set is_completed to 0 initially (false)
    tasks[i].is_completed = 0;
  }
}

// Define a function to print the tasks
void print_tasks() {
  printf("\nTask Scheduler\n");
  printf("---------------\n\n");
  printf("Name\t\tPriority\tTime Required\n");
  printf("--------------------------------------------------------------\n");
  for(int i=0; i<10; i++) {
    printf("%-20s%-20d%d seconds\n", tasks[i].name, tasks[i].priority, tasks[i].time_req);
  }
}

// Define a function to schedule the tasks
void schedule_tasks() {
  int total_time = 0;
  while(1) {
    // Find the highest priority task that has not been completed
    int highest_priority = 0, highest_priority_index = -1;
    for(int i=0; i<10; i++) {
      if(tasks[i].priority > highest_priority && !tasks[i].is_completed) {
        highest_priority = tasks[i].priority;
        highest_priority_index = i;
      }
    }
    if(highest_priority_index == -1) {
      break; // All tasks have been completed
    }

    // Print the current task being executed
    printf("Executing task %s for %d seconds...\n", tasks[highest_priority_index].name, tasks[highest_priority_index].time_req);

    // Update the total time spent on tasks
    total_time += tasks[highest_priority_index].time_req;

    // Mark the task as completed
    tasks[highest_priority_index].is_completed = 1;
  }
  printf("\nTask scheduler completed all tasks in %d seconds!\n", total_time);
}

int main() {
  generate_tasks();
  print_tasks();
  schedule_tasks();
  return 0;
}