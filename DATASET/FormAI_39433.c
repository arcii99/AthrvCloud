//FormAI DATASET v1.0 Category: Smart home light control ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int main(){
  int lights = 0;
  int selection;
  int numLightsOn = 0;
  printf("Welcome to Smart Home Light Control System!\n");
  while(1){
    printf("Select an option:\n");
    printf("1. Turn on a light\n");
    printf("2. Turn off a light\n");
    printf("3. View number of lights currently on\n");
    printf("4. Exit\n");
    printf("Enter selection: ");
    scanf("%d", &selection);
    switch(selection){
      case 1:
        if(lights < 5){
          lights++;
          numLightsOn++;
          printf("A light has been turned on. There are now %d lights on.\n", numLightsOn);
        }
        else{
          printf("Sorry, you have reached the maximum number of lights.\n");
        }
        break;
      case 2:
        if(lights > 0){
          lights--;
          numLightsOn--;
          printf("A light has been turned off. There are now %d lights on.\n", numLightsOn);
        }
        else{
          printf("Sorry, there are no lights to turn off.\n");
        }
        break;
      case 3:
        printf("There are currently %d lights on.\n", numLightsOn);
        break;
      case 4:
        printf("Thank you for using the Smart Home Light Control System!\n");
        exit(0);
      default:
        printf("Invalid selection. Please try again.\n");
    }
  }
  return 0;
}