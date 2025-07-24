//FormAI DATASET v1.0 Category: Smart home light control ; Style: curious
#include <stdio.h>

int main() {
  
  int light_status = 0; //initialize light status to off
  int brightness = 0; //initialize brightness to low
  
  printf("Welcome to Smart Home Light Control System\n");
  
  while(1) { //infinite loop until user exits
    printf("Current Light Status: %s\n", light_status == 1 ? "On" : "Off");
    printf("Current Brightness Level: %d\n", brightness);
    
    printf("Enter 1 to turn on/off the light, 2 to increase brightness, 3 to decrease brightness, or 4 to exit: ");
    
    int input;
    scanf("%d", &input); //get user input
    
    switch(input) {
      
      case 1:
        light_status = 1 - light_status; //toggle light status between 0 and 1
        printf("Light %s\n", light_status == 1 ? "On" : "Off");
        break;
      
      case 2:
        if(brightness < 100) {
          brightness += 10; //increase brightness by 10%
        }
        printf("Brightness Increased to %d\n", brightness);
        break;
      
      case 3:
        if(brightness > 0) {
          brightness -= 10; //decrease brightness by 10%
        }
        printf("Brightness Decreased to %d\n", brightness);
        break;
      
      case 4:
        printf("Goodbye!\n");
        return 0;
        
      default:
        printf("Invalid Input. Please try again.\n");
        break;
    }
  }
}