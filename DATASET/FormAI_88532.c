//FormAI DATASET v1.0 Category: File Synchronizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  srand(time(NULL)); // Initialize the random seed using current time
  
  // Storage directory paths
  char dir1[] = "/home/user/Documents";
  char dir2[] = "/media/external/Documents";
  
  // File names and extensions to be synchronized
  char file1[] = "notes";
  char file2[] = "journal";
  char ext[] = ".txt";
  
  // Generate random number to determine which directory to copy to
  int randomNumber = rand() % 2;
  
  // Copy file from one directory to another
  if (randomNumber == 0) {
    char command[100];
    sprintf(command, "cp %s/%s%s %s/backup/%s%s", dir1, file1, ext, dir2, file1, ext);
    system(command);
    printf("File %s%s synchronized from %s to %s.\n", file1, ext, dir1, dir2);
  } else {
    char command[100];
    sprintf(command, "cp %s/%s%s %s/backup/%s%s", dir2, file2, ext, dir1, file2, ext);
    system(command);
    printf("File %s%s synchronized from %s to %s.\n", file2, ext, dir2, dir1);
  }

  return 0;
}