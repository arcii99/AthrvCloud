//FormAI DATASET v1.0 Category: Smart home light control ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); //initialize random seed
  int num_lights = rand() % 16 + 1; //generate random number of lights from 1-16
  int light_array[num_lights]; //create array with size of number of lights

  //initialize all lights to off
  for(int i=0; i<num_lights; i++) {
    light_array[i] = 0;
  }

  printf("Welcome to the Surrealist Smart Home Light Control Program\n");
  printf("You have %d lights in your home. Press 1 to turn on a light, 0 to turn it off\n", num_lights);

  //loop through each light until user quits
  int running = 1;
  while(running) {
    printf("\n");
    for(int i=0; i<num_lights; i++) {
      printf("%d ", light_array[i]);
    }
    printf("\n");

    //get user input and validate
    int input;
    do {
      printf("Enter a valid light number (1-%d) or press 0 to quit: ", num_lights);
      scanf("%d", &input);
    } while(input < 0 || input > num_lights);

    //exit program if user inputs 0
    if(input == 0) {
      printf("Exiting program...\n");
      running = 0;
    } else {
      //toggle light on/off
      light_array[input-1] = !light_array[input-1];
      printf("Light %d is now %s\n", input, light_array[input-1] ? "on" : "off");
    }
  }
  return 0;
}