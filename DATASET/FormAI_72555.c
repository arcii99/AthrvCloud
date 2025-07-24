//FormAI DATASET v1.0 Category: Smart home automation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Function to switch lights on/off
void switchLights(int switchStatus){
   if(switchStatus==1){
      printf("Switching on lights...\n");
   }else{
      printf("Switching off lights...\n");
   }
}

int main(){
   int switchStatus, tempStatus, fanStatus;
   printf("Enter current switch status (0 for off, 1 for on):\n");
   scanf("%d",&switchStatus);
   printf("Enter current temperature status:\n");
   scanf("%d",&tempStatus);
   printf("Enter current fan status (0 for off, 1 for low, 2 for medium and 3 for high):\n");
   scanf("%d",&fanStatus);
   
   // Switch lights based on switch status
   switchLights(switchStatus);

   //Adjust temperature using AC
   if(tempStatus>30){
      printf("Adjusting AC to cool the room...\n");
   }else if(tempStatus<20){
      printf("Adjusting AC to heat the room...\n");
   }else{
      printf("Temperature is optimal...No action needed...\n");
   }

   //Switch fan based on fan speed status
   switch(fanStatus){
      case 0: printf("Switching off fan...\n");
              break;
      case 1: printf("Switching on fan in low speed...\n");
              break;
      case 2: printf("Switching on fan in medium speed...\n");
              break;
      case 3: printf("Switching on fan in high speed...\n");
              break;
      default: printf("Invalid fan status...\n");
               return 0;
   }
   return 0;
}