//FormAI DATASET v1.0 Category: Task Scheduler ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

#define INTERVAL 1

void handle_signal(int);

void task1(void) {
  printf("Executing task 1\n");
}

void task2(void) {
  printf("Executing task 2\n");
}

void task3(void) {
  printf("Executing task 3\n");
}

void task4(void) {
  printf("Executing task 4\n");
}

void register_tasks(void) {
  signal(SIGALRM, handle_signal);
  alarm(INTERVAL);
}

int main() {
  register_tasks();

  while (1) {}
}

void handle_signal(int signal) {
  if (signal == SIGALRM) {
    // Schedule task 1
    task1();

    // Schedule task 2 after 2 seconds
    sleep(2);
    task2();

    // Schedule task 3 after 3 seconds
    sleep(3);
    task3();

    // Schedule task 4 after 4 seconds
    sleep(4);
    task4();

    // Set the alarm for the next task
    alarm(INTERVAL);
  }
}