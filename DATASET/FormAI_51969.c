//FormAI DATASET v1.0 Category: System boot optimizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void optimize_boot()
{
  printf("Starting system boot optimizer...\n");
  sleep(1);
  printf("Disabling unnecessary services...\n");
  system("systemctl disable cups.service");
  system("systemctl disable ssh.service");
  system("systemctl disable httpd.service");
  printf("Cleaning up the system...\n");
  system("yum clean all");
  system("rm -rf /var/tmp/*");
  system("rm -rf /var/cache/yum");
  printf("Compacting memory...\n");
  system("echo 1 > /proc/sys/vm/drop_caches");
  sleep(1);
  printf("All done! Rebooting...\n");
  sleep(1);
  system("reboot");
}

int main()
{
  int choice;
  printf("Welcome to the System Boot Optimizer\n");
  printf("1. Optimize System Boot\n");
  printf("2. Exit\n");
  printf("Enter choice: ");
  scanf("%d", &choice);
  switch(choice)
  {
    case 1:
      optimize_boot();
      break;
    case 2:
      printf("Exiting...Goodbye!\n");
      break;
    default:
      printf("Invalid choice, exiting...Goodbye!\n");
      break;
  }
  return 0;
}