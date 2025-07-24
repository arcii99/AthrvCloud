//FormAI DATASET v1.0 Category: System process viewer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

void printHeader() {
  printf("%-15s%-10s%-10s%-10s\n", "Process Name", "PID", "PPID", "Status");
}

void printProcessInfo(const char* process, int pid, int ppid, const char* status) {
  printf("%-15s%-10d%-10d%-10s\n", process, pid, ppid, status);
}

int main() {
  printf("Welcome to the Process Viewer\n\n");

  // System call to retrieve process information
  system("ps axo comm,pid,ppid,state > processes.txt");

  // Open the file for reading
  FILE* file = fopen("processes.txt", "r");
  if (!file) {
    printf("Error opening file!\n");
    return 1;
  }

  // Print the header
  printHeader();

  // Read each line of the file and print the process info
  char process[16];
  int pid, ppid;
  char status[16];
  while (fscanf(file, "%s%d%d%s", process, &pid, &ppid, status) == 4) {
    printProcessInfo(process, pid, ppid, status);
  }

  // Close the file
  fclose(file);

  // Remove the temporary file
  system("rm processes.txt");

  return 0;
}