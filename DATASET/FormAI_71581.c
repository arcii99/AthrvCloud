//FormAI DATASET v1.0 Category: Smart home light control ; Style: standalone
#include <stdio.h>
#include <string.h>

int main(void) {
  int light_on = 0;
  char input[10];

  printf("Welcome to Smart Home Light Control!\n");
  printf("Enter 'on' to turn on the lights or 'off' to turn them off.\n");

  while(1) {
    printf("> ");
    fgets(input, 10, stdin);
    strtok(input, "\n"); // remove trailing newline character

    if(strcmp(input, "on") == 0) {
      if(light_on == 1) {
        printf("The lights are already on!\n");
      } else {
        light_on = 1;
        printf("Turning on the lights.\n");
      }
    } else if(strcmp(input, "off") == 0) {
      if(light_on == 0) {
        printf("The lights are already off!\n");
      } else {
        light_on = 0;
        printf("Turning off the lights.\n");
      }
    } else {
      printf("Invalid input. Enter 'on' or 'off'.\n");
    }
  }

  return 0;
}