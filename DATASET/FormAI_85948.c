//FormAI DATASET v1.0 Category: Smart home light control ; Style: rigorous
#include <stdio.h>

/* Function to turn on the light */
void turnOn(int lightNum){
  printf("Light %d is now on.\n", lightNum);
}

/* Function to turn off the light */
void turnOff(int lightNum){
  printf("Light %d is now off.\n", lightNum);
}

int main(){
  int option, lightNum;
  
  /* Infinite Loop to simulate Smart Home Light Control */
  while(1){
    /* Prompt user for input */
    printf("Enter 1 to turn on light. Enter 2 to turn off light. Enter 0 to exit.\n");
    scanf("%d", &option);
    
    /* Check user input */
    if(option == 0){
      break;
    }
    
    /* Prompt user for light number */
    printf("Enter the number of the light you want to control.\n");
    scanf("%d", &lightNum);
    
    /* Control Light Based on User's Input */
    switch(option){
      case 1:
        turnOn(lightNum);
        break;
      case 2:
        turnOff(lightNum);
        break;
      default:
        printf("Invalid input. Please try again.\n");
    }
  }
  
  return 0;
}