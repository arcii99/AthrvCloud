//FormAI DATASET v1.0 Category: Smart home light control ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
   int light = 0;
   int temp = 25;
   int motion = 0;

   srand(time(NULL));

   printf("Smart Home Light Control\n");
   printf("Room temperature: %d degree Celsius\n", temp);

   while(1){
      motion = rand() % 2;

      if(motion == 1){
         printf("Motion detected!\n");
         if(light == 1){
            printf("Turning off lights.\n");
            light = 0; 
         }else{
            printf("Turning on lights.\n");
            light = 1;
         }
      }else{
         printf("No motion detected.\n");
      }

      if(light == 1){
         if(temp > 28){
            printf("Room temperature is too high. Turning off lights.\n");
            light = 0;
         }else{
            printf("Room temperature is normal.\n");
         }
      }
      printf("\n");
      sleep(1);
   }

   return 0;
}