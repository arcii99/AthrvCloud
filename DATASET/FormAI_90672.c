//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void printCurrentRAMUsage(){
  char command[MAX_BUFFER_SIZE];
  sprintf(command, "ps -o rss -p %d | sed -n '2p'", getpid()); // format the command to get RSS of current process
  FILE* fp = popen(command, "r"); // open read pipe with the command
  if(fp == NULL){
    printf("Error in opening pipe for the command: %s\n", command);
    return;
  }
  char buffer[MAX_BUFFER_SIZE];
  fgets(buffer, MAX_BUFFER_SIZE, fp); // read output into buffer
  pclose(fp); // closing the pipe
  int rss = atoi(buffer) * 1024; // convert to integer and convert from KB to bytes
  printf("Current RAM usage: %d bytes\n", rss);
}

int main(){
  printf("**** C RAM Usage Monitor ****\n");
  int count = 1;
  while(1){
    printf("\n------ Iteration %d ------\n", count);
    printCurrentRAMUsage(); // print current RAM usage
    sleep(2); // sleep for 2 seconds
    count += 1;
  }
  return 0;
}