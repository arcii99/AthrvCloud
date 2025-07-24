//FormAI DATASET v1.0 Category: Smart home light control ; Style: happy
#include <stdio.h>
#include <string.h>

int main(){
  int light_control = 0;
  char command[100];
  
  printf("Welcome to Happy Home Light Control System!\n");
  
  while(1){
    printf("\nWhat do you want to do? (On/Off)\n");
    scanf("%s", command);
    
    if(strcmp(command, "On") == 0){
      light_control = 1;
      printf("Light is now ON! Enjoy your bright and happy room.\n");
    }
    else if(strcmp(command, "Off") == 0){
      light_control = 0;
      printf("Light is now OFF! It's time to rest and relax.\n");
    }
    else{
      printf("Invalid command! Please enter either 'On' or 'Off'.\n");
    }
  }
  
  return 0;
}