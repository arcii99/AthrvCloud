//FormAI DATASET v1.0 Category: System administration ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  printf("Welcome to the SysAdmin tool!\n");
  char command[1000];
  while(1){
    printf("Please enter a command (or press q to quit): ");
    fgets(command, 1000, stdin);
    if(command[0] == 'q'){
      printf("Goodbye!\n");
      break;
    }
    int ret = system(command);
    if(ret == 0){
      printf("Command executed successfully.\n");
    } else {
      printf("Error executing command. Error code: %d\n", ret);
    }
  }
  return 0;
}