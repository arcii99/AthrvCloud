//FormAI DATASET v1.0 Category: Task Scheduler ; Style: shocked
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

void handle_sigint(int sig) {
  printf("Received SIGINT, exiting.\n");
  exit(0);
}

void task1() {
  printf("Running task 1...\n");
  sleep(5);
}

void task2() {
  printf("Running task 2...\n");
  sleep(10);
}

int main() {
  signal(SIGINT, handle_sigint);

  printf("Task Scheduler starting...\n");
  
  while (1) {
    time_t current_time = time(NULL);
    printf("Current time: %s", ctime(&current_time));

    if (current_time % 10 == 0) {
        task1();
    }

    if (current_time % 20 == 0) {
        task2();
    }

    sleep(1);
  }

  return 0;
}