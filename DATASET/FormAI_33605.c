//FormAI DATASET v1.0 Category: System administration ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main() {

   char *command = "ls -l /"; // set command string
   char buffer[256]; // buffer for captured output
   FILE *fp; // file pointer

   // open pipe connection to command
   fp = popen(command, "r");

   if (fp == NULL) { // check for errors opening pipe
      printf("Failed to run command\n");
      exit(1);
   }

   // read command output into buffer
   while (fgets(buffer, sizeof(buffer), fp) != NULL) {
      printf("%s", buffer);
   }

   // close the pipe
   pclose(fp);

   return 0;
}