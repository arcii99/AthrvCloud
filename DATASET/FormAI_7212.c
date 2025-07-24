//FormAI DATASET v1.0 Category: Smart home light control ; Style: Alan Touring
#include <stdio.h>

int main() {
   int light = 0;
   int brightness = 0;
   int desiredBrightness;
   
   printf("Smart Home Light Control\n\n");
   
   while(1) {
      printf("Current light status: %d\n", light);
      printf("Current light brightness: %d\n", brightness);
      printf("Enter desired brightness (0-100): ");
      scanf("%d", &desiredBrightness);
      
      if(desiredBrightness < 0 || desiredBrightness > 100) {
         printf("Invalid brightness level. Please enter a value between 0-100.\n\n");
      } else if(desiredBrightness == brightness) {
         printf("Light brightness is already set to %d.\n\n", brightness);
      } else {
         brightness = desiredBrightness;
         if(brightness > 50) {
            light = 1;
         } else {
            light = 0;
         }
         printf("Light brightness set to %d.\n", brightness);
         if(light) {
            printf("Light turned on.\n\n");
         } else {
            printf("Light turned off.\n\n");
         }
      }
   }
   return 0;
}