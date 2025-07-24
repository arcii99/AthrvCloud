//FormAI DATASET v1.0 Category: System administration ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void execute_server_command(char *command) {
   system(command);
}

void execute_local_command(char *command) {
   char buffer[256];
 
   printf("Want to execute locally: %s ? (y\\n): ", command);
   scanf("%s", buffer);
   
   if (strcmp(buffer, "y") == 0) {
      system(command);
   }
}

int main(int argc, char *argv[]) {
   if (argc <= 1) {
      printf("Usage: %s [server | local] <commands>\n", argv[0]);
      exit(0);
   }
 
   if (strcmp(argv[1], "server") == 0) {
      printf("Executing command on server:\n");
      for (int i = 2; i < argc; i++) {
         execute_server_command(argv[i]);
      }
   } else if (strcmp(argv[1], "local") == 0) {
      printf("Executing command locally:\n");
      for (int i = 2; i < argc; i++) {
         execute_local_command(argv[i]);
      }
   } else {
      printf("Unknown command %s\n", argv[1]);
   }
 
   return 0;
}