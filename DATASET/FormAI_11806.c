//FormAI DATASET v1.0 Category: Robot movement control ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

/* Movement control program in Romeo and Juliet Style */

int main() {
  // Declare variables
  char direction[10];
  int distance = 0;
  
  // Greet the user
  printf("My dear Romeo, I am your faithful servant and your mechanical companion!\n");
  
  // Start the movement control loop
  while(1) {
    // Prompt for user input
    printf("Whither shall I go? North, south, east, or west?\n");
    scanf("%s", direction);
    
    // Check for valid input
    if(strcmp(direction, "north") != 0 && strcmp(direction, "south") != 0 && strcmp(direction, "east") != 0 && strcmp(direction, "west") != 0) {
      printf("Alas, my sweet Romeo, I know not of such a direction!\n");
      continue;
    }
    
    // Prompt for user input
    printf("How far shall I travel?\n");
    scanf("%d", &distance);
    
    // Check for valid input
    if(distance <= 0) {
      printf("Oh, my dearest Romeo! Thou art most inconsiderate! I cannot travel a distance of zero or less!\n");
      continue;
    }
    
    // Print out movement instruction in a poetic manner
    printf("Onward, my love! To the %s we go, a distance of %d leagues!\n", direction, distance);
    
    // Break the loop if the user says goodbye
    if(strcmp(direction, "goodbye") == 0) {
      printf("Farewell, my sweet Romeo! T'was an honour to serve thee!\n");
      break;
    }
  }
  
  return 0;
}