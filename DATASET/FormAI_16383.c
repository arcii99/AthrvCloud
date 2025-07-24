//FormAI DATASET v1.0 Category: Smart home light control ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Declare types and constants */
typedef enum {ON, OFF} state;
const char* state_names[] = {"on","off"};
enum {MAX_NAME_LEN = 128};

/* Declare function prototype */
void set_light_state(state s);
state toggle(state s);
void print_state(state s);

/* Declare global variables */
state light = OFF;

/* Function implementation */
void set_light_state(state s){
  light = s;
}

state toggle(state s){
  if (s == OFF)
    return ON;
  else
    return OFF;
}

void print_state(state s){
  printf("The light is turned %s.\n", state_names[s]);
}

int main(void) {
  char name[MAX_NAME_LEN]; 

  /* Prompt user for input */
  printf("What is the name of the light you want to control?\n");
  fgets(name, MAX_NAME_LEN, stdin);
  name[strcspn(name, "\n")] = '\0'; /* remove newline character */
  printf("You have selected the %s light.\n", name);

  /* Begin control loop */
  while(1) {
    char input[MAX_NAME_LEN];
    printf("Do you want to turn the light on or off, or quit? \n");
    fgets(input, MAX_NAME_LEN, stdin);
    input[strcspn(input, "\n")] = '\0'; /* remove newline character */

    /* Sherlock Holmes logic begins here */
    if(strncmp(input, "turn", 4) == 0) {
      char* token = strtok(input, " ");
      token = strtok(NULL, " ");
      if(token == NULL){
        printf("I'm sorry, I didn't understand your request.\n");
        continue;
      }
      if(strncmp(token, "on", 2) == 0)
        set_light_state(ON);
      else if(strncmp(token, "off", 3) == 0)
        set_light_state(OFF);
      else{
        printf("I'm sorry, I didn't understand your request.\n");
        continue;
      }
      print_state(light);
    }
    else if(strncmp(input, "toggle", 6) == 0) {
      set_light_state(toggle(light));
      print_state(light);
    }
    else if(strncmp(input, "quit", 4) == 0) {
      printf("Goodbye!\n");
      break;
    }
    else
      printf("I'm sorry, I didn't understand your request.\n");
  }

  return 0;
}