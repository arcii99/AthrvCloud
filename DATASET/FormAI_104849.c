//FormAI DATASET v1.0 Category: System administration ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the Surprised System Administration Example Program!\n");

  printf("Initializing the system...\n");
  system("init_system");

  printf("Checking system performance...\n");
  if(system("check_performance") != 0) {
    printf("Oh no! The system is not performing well!\n");
    printf("Trying to fix the issue...\n");
    system("fix_performance");
    printf("System performance has been improved!\n");
  } else {
    printf("The system is performing well!\n");
  }

  printf("Checking disk usage...\n");
  FILE *disk_usage = popen("df -h /", "r");
  char buffer[512];
  while (fgets(buffer, sizeof(buffer), disk_usage)) {
    printf("%s", buffer);
  }
  pclose(disk_usage);

  printf("Checking network connectivity...\n");
  if(system("ping -c 4 google.com") != 0) {
    printf("Uh oh! Could not connect to the internet!\n");
    printf("Trying to fix the issue...\n");
    system("restart_networking");
    printf("Network connectivity has been restored!\n");
  } else {
    printf("Internet connection is working!\n");
  }

  printf("Analyzing system logs...\n");
  FILE *system_logs = popen("tail -n 10 /var/log/syslog", "r");
  while (fgets(buffer, sizeof(buffer), system_logs)) {
    printf("%s", buffer);
  }
  pclose(system_logs);

  printf("System administration has been successfully completed! Enjoy the surprising results!\n");

  return 0;
}