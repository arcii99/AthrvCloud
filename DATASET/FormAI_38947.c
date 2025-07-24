//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  printf("Wow! You are about to analyze your C Disk space...\n\n");
  printf("Please provide the path of the directory you want to analyze: "); 

  char directory_path[100]; // maximum directory path length limit
  scanf("%s", directory_path); // get directory path from user

  printf("\nScanning C Disk at directory %s...\n", directory_path);

  // We will use popen() method to execute 'du' command to get disk usage statistics
  char command[1000];
  sprintf(command, "du -sh %s/*", directory_path);

  // Open the command for reading
  FILE *fp = popen(command, "r");
  if (fp == NULL) {
    printf("ERROR: Failed to get disk usage data for %s...\n", directory_path);
    exit(1);
  }

  // parse the output of the command to get individual files/directories usage information
  char result[1000];
  int total_usage = 0;
  printf("\nDirectory\tSize\n");
  while (fgets(result, sizeof(result), fp) != NULL) {
    char *size_str = strtok(result, "\t"); // get only the size section
    printf("%s\n", size_str);
    total_usage += atoi(size_str); // add file size to total usage
  }

  printf("Total disk usage: %.2f GB\n", (float) total_usage / 1024 / 1024 / 1024); // print total disk usage in GB

  // close the popen file pointer
  pclose(fp);

  printf("\nYay! C Disk space analysis successfully completed.\n");
  return 0;
}