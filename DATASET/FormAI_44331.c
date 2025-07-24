//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Donald Knuth
/* Traffic Light Controller Program */
#include<stdio.h>

int main(){
  int green_time, yellow_time, red_time;
  int cycle_time = 60; // Total cycle time is 60 seconds
  
  printf("Enter green time: ");
  scanf("%d", &green_time); // Input green time in seconds
  
  printf("Enter yellow time: ");
  scanf("%d", &yellow_time); // Input yellow time in seconds
  
  red_time = cycle_time - green_time - yellow_time; // Calculate red time
  
  while(1){ // Loop infinitely
    printf("\nGREEN Light ON for %d seconds.\n", green_time);
    delay(green_time);
    
    printf("\nYELLOW Light ON for %d seconds.\n", yellow_time);
    delay(yellow_time);
    
    printf("\nRED Light ON for %d seconds.\n", red_time);
    delay(red_time);
  }
  
  return 0;
}

/* Function to simulate delay */
void delay(int seconds){
  int i, j;
  for(i = 0; i < seconds; i++){
    for(j = 0; j < 10000000; j++);
  }
}