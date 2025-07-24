//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: intelligent
#include <stdio.h>

int main(){
   int time = 0;
   char color = 'R';
   
   while(1){
      if(color == 'R'){
         printf("Red light for %d seconds\n", time);
         while(time < 20){ // red light for 20 seconds
            time++;
         }
         time = 0; // reset time
         color = 'G'; // switch to green
      }
      else if(color == 'G'){
         printf("Green light for %d seconds\n", time);
         while(time < 30){ // green light for 30 seconds
            time++;
         }
         time = 0; // reset time
         color = 'Y'; // switch to yellow
      }
      else if(color == 'Y'){
         printf("Yellow light for %d seconds\n", time);
         while(time < 5){ // yellow light for 5 seconds
            time++;
         }
         time = 0; // reset time
         color = 'R'; // switch to red
      }
   }
   
   return 0;
}