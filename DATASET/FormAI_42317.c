//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
   int signal = 0;
   printf("Traffic Light Controller\n\n");

   while(1) {
      if(signal == 0) {
         printf("Red signal on\n");
         sleep(10); // wait for 10 seconds
         signal++;
      }
      else if(signal == 1) {
         printf("Green signal on\n");
         sleep(5); // wait for 5 seconds
         signal++;
      }
      else {
         printf("Yellow signal on\n");
         sleep(2); // wait for 2 seconds
         signal = 0;
      }
   }
   return 0;
}