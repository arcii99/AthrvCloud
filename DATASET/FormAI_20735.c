//FormAI DATASET v1.0 Category: Smart home light control ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char command[50] = "";
  int light_status = 0; //initially the light is off

  printf("Welcome to Smart Home Light Control Program!!\n\n");

  while (1){ //loop forever until the user stops the program
    printf("Type 'on' to turn on the light and 'off' to turn off the light: ");
    fgets(command, 50, stdin); //get user input

    if (strcmp(command, "on\n") == 0){ //user wants to turn on the light
      if (light_status == 0){ //light is currently off
        printf("\nTurning on the light...\n");
        light_status = 1; //update light status
      }
      else{ //light is already on
        printf("\nThe light is already on...\n");
      }
    }
    else if (strcmp(command, "off\n") == 0){ //user wants to turn off the light
      if (light_status == 1){ //light is currently on
        printf("\nTurning off the light...\n");
        light_status = 0; //update light status
      }
      else{ //light is already off
        printf("\nThe light is already off...\n");
      }
    }
    else{ //user entered an invalid command
      printf("\nInvalid command. Please try again...\n");
    }
  }

  return 0;
}