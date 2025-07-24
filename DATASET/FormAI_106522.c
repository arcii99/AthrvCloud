//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: futuristic
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main() 
{ 
  //initialize variables
  int trafficLight = 0; 
  int countDownVal = 0; 
  
  //set up random values 
  srand(time(NULL)); 
  
  //run simulation 100 times
  for(int i = 0; i < 100; i++) 
  {     
    //choose a random value for countdown timer
    countDownVal = rand() % 10 + 1; 
    
    //switch traffic light based on countdown value
    if(countDownVal <= 3) 
    { 
      //turn red light on
      trafficLight = 0; 
      printf("Red Light On: %d\n", countDownVal); 
    } 
    else if(countDownVal <= 6) 
    { 
      //turn yellow light on
      trafficLight = 1; 
      printf("Yellow Light On: %d\n", countDownVal); 
    } 
    else 
    { 
      //turn green light on
      trafficLight = 2; 
      printf("Green Light On: %d\n", countDownVal); 
    } 
    
    //initialize countdown timer
    int countdown = countDownVal; 
    
    //countdown 
    while(countdown > 0) 
    { 
      countdown--; 
      printf("Countdown: %d\n", countdown); 
    } 
    
    //flip traffic light back to red
    trafficLight = 0; 
    printf("Red Light On: 0\n"); 
  } 
  
  return 0; 
}