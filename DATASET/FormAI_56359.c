//FormAI DATASET v1.0 Category: System administration ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]) {
  
  //Checking arguments and displaying usage information 
  if (argc < 3) {
    printf("Usage: %s logfile command\n", argv[0]);
    printf("  logfile: Path to the logfile\n");
    printf("  command: Command to be logged\n");
    return 1;
  }
  
  //Reading arguments and opening the logfile
  char *logfile_path = argv[1];
  char *command = argv[2];
  int fd = open(logfile_path, O_WRONLY|O_APPEND|O_CREAT, 0666);
  if (fd < 0) {
    printf("Error: Could not open log file %s\n", logfile_path);
    return 1;
  }
  
  //Writing current time and command to the logfile
  time_t now;
  char buffer[26];
  struct tm* info;
  time(&now);
  info = localtime(&now);
  strftime(buffer, 26, "%Y-%m-%d %H:%M:%S\n", info);
  
  char *log_msg = malloc( strlen(buffer) + strlen(command) + 2 ); //extra characters are for separator and null terminator
  sprintf(log_msg, "%s %s\n", buffer, command);
  
  write(fd, log_msg, strlen(log_msg));
  
  close(fd);
  free(log_msg);
  
  return 0;
}