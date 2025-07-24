//FormAI DATASET v1.0 Category: Task Scheduler ; Style: recursive
#include <stdio.h>

void task1()
{
  printf("This is task 1\n");
}

void task2()
{
  printf("This is task 2\n");
}

void task3()
{
  printf("This is task 3\n");
}

void scheduler(int current_task, int total_tasks)
{
  if (current_task > total_tasks)
  {
    printf("All tasks complete\n");
    return;
  }

  switch (current_task)
  {
    case 1:
      task1();
      break;
    case 2:
      task2();
      break;
    case 3:
      task3();
      break;
    default:
      printf("Invalid task number\n");
      break;
  }

  scheduler(current_task + 1, total_tasks);
}

int main()
{
  printf("Task scheduler starting\n");
  
  scheduler(1, 3);

  return 0;
}