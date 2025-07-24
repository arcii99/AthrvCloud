//FormAI DATASET v1.0 Category: System administration ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handle_alarm(int sig) {
  printf("It's time to wake up and stretch!\n");
}

int main() {
  printf("Welcome to Mind-Bending System Administration Program\n\n");

  time_t start_time = time(NULL);
  int pid = getpid();

  printf("Program started at %s\n", ctime(&start_time));
  printf("PID: %d\n", pid);

  printf("\nSetting alarm for 10 seconds...\n");
  signal(SIGALRM, handle_alarm);
  alarm(10);

  printf("\nSleeping...\n");
  sleep(20);

  printf("\nChanging permissions of file 'secret.txt' to 400...\n");
  int result = system("chmod 400 secret.txt");
  if (result != 0) {
    printf("Failed to change file permission.\n");
    exit(1);
  }

  printf("\nKilling program with PID %d...\n", pid);
  kill(pid, SIGINT);

  printf("\nProgram terminated.\n");

  return 0;
}