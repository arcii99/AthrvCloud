//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char command[100];

  // Open log file
  FILE *fptr;
  fptr = fopen("log.txt", "a");

  while(1) {

    printf("Enter a command: ");
    fgets(command, sizeof(command), stdin);

    // Check for intrusion keywords
    if(strstr(command, "sudo") || strstr(command, "rm -rf") || strstr(command, "shutdown")) {
      printf("INTRUSION DETECTED!"); // Print message to user
      fprintf(fptr, "Intrusion detected! Command executed: %s\n", command); // Log intrusion to file
      exit(0); // Exit program
    } else {
      fprintf(fptr, "Command executed: %s\n", command); // Log command to file
    }
  }

  fclose(fptr);
  return 0;

}