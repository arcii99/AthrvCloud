//FormAI DATASET v1.0 Category: System administration ; Style: happy
#include <stdio.h>

int main() {
  printf("Welcome to the Happy System Administration Example Program!\n");
  printf("Today we will be checking the disk space usage on our server.\n");

  int totalSpace = 100;
  int usedSpace = 32;
  int freeSpace = totalSpace - usedSpace;

  printf("Total disk space: %d GB\n", totalSpace);
  printf("Used disk space: %d GB\n", usedSpace);
  printf("Free disk space: %d GB\n", freeSpace);

  if (freeSpace >= 50) {
    printf("Great news! We have plenty of free disk space.\n");
  } else if (freeSpace > 20) {
    printf("We could use a little more free disk space, but we're still doing pretty good.\n");
  } else {
    printf("Uh oh, we're running low on disk space. Time to do some cleanup!\n");
  }

  printf("Thanks for using the Happy System Administration Example Program. Have a great day!\n");

  return 0;
}