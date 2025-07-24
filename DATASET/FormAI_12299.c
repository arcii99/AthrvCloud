//FormAI DATASET v1.0 Category: Task Scheduler ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Function to print the current time
void print_time() {
  time_t now = time(NULL);
  printf("Current time is: %s\n", ctime(&now));
}

// Function to execute Task 1
void task1() {
  printf("Executing Task 1...\n");
  print_time();
  // Add task logic here
  
}

// Function to execute Task 2
void task2() {
  printf("Executing Task 2...\n");
  print_time();
  // Add task logic here
}

// Function to execute Task 3
void task3() {
  printf("Executing Task 3...\n");
  print_time();
  // Add task logic here
}

// Function to handle SIGALRM signal
void signal_handler(int sig) {
  switch(sig) {
    case SIGALRM:
      // Execute Task 1
      task1();
      // Set the alarm for 20 seconds
      alarm(20);
      break;
    case SIGINT:
      printf("Terminating...\n");
      exit(0);
      break;
  }
}

int main() {
  // Set the signal handler for SIGALRM and SIGINT
  signal(SIGALRM, signal_handler);
  signal(SIGINT, signal_handler);

  printf("Task scheduler started...\n");

  // Set the alarm for the first task
  alarm(5);

  // Loop indefinitely
  while(1) {
    // Execute Task 2
    task2();
    // Sleep for 3 seconds
    sleep(3);
    // Execute Task 3
    task3();
    // Sleep for 3 seconds
    sleep(3);
  }

  return 0;
}