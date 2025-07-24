//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
   int red_light = 10, green_light = 20, yellow_light = 5;
   int car_count = 0;
   srand(time(0));
   
   printf("\n\n****Traffic Simulation is starting!****\n\n");
   
   while(1){
       int random = rand()%3;
       if(random == 0){
           printf("Green Light On!!!\n");
           for(int i=0;i<green_light;i++){
               car_count++;
               printf("%d Cars crossed the intersection!\n", car_count);
               sleep(1);
           }
       }
       else if(random == 1){
           printf("Yellow Light On!!!\n");
           for(int i=0;i<yellow_light;i++){
               car_count++;
               printf("%d Cars crossed the intersection!\n", car_count);
               sleep(1);
           }
       }
       else{
           printf("Red Light On!!\n");
           sleep(1);
       }
   }
   
   return 0;
}