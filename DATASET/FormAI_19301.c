//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: mathematical
#include <stdio.h>

int main() {
   int traffic_light_state = 0;
   int time_elapsed = 0;
   int max_time = 60;
   while(time_elapsed < max_time) {
      printf("Elapsed Time: %d seconds\n", time_elapsed);
      switch (traffic_light_state) {
         case 0:
            printf("Red Light\n");
            printf("Stop!\n");
            traffic_light_state++;
            break;
         case 1:
            printf("Yellow Light\n");
            printf("Slow down!\n");
            traffic_light_state++;
            break;
         case 2:
            printf("Green Light\n");
            printf("Go!\n");
            traffic_light_state = 0;
            break;
         default:
            printf("Invalid Traffic Light State\n");
            break;
      }
      time_elapsed += 10;
   }
   return 0;
}