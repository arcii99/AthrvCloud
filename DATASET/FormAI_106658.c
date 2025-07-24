//FormAI DATASET v1.0 Category: Task Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int priority;
  int burst_time;
} Task;

int main() {
  int num_tasks, quantum_time, total_burst_time = 0;
  printf("Enter the number of tasks: ");
  scanf("%d", &num_tasks);
  Task tasks[num_tasks];
  for(int i = 0; i < num_tasks; i++) {
    printf("\nEnter Priority of Task %d: ", i+1);
    scanf("%d", &tasks[i].priority);
    printf("Enter Burst Time of Task %d: ", i+1);
    scanf("%d", &tasks[i].burst_time);
    total_burst_time += tasks[i].burst_time;
  }
  printf("\nEnter the quantum time: ");
  scanf("%d", &quantum_time);
  Task completed_tasks[num_tasks];
  int current_time = 0, completed = 0;
  while(completed < num_tasks) {
    for(int i = 0; i < num_tasks; i++) {
      if(tasks[i].burst_time > 0 && tasks[i].priority <= current_time) {
        if(quantum_time < tasks[i].burst_time) {
          current_time += quantum_time;
          tasks[i].burst_time -= quantum_time;
        }
        else {
          current_time += tasks[i].burst_time;
          completed_tasks[completed] = tasks[i];
          tasks[i].burst_time = 0;
          completed++;
        }
      }
    }
  }
  printf("\nTask Execution Order: ");
  for(int i = 0; i < num_tasks; i++) {
    printf("T%d ", completed_tasks[i].priority);
  }
  printf("\nAverage Waiting Time: %d\n", ((current_time-total_burst_time)/num_tasks));
  return 0;
}