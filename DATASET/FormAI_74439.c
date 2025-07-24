//FormAI DATASET v1.0 Category: Smart home light control ; Style: cheerful
#include <stdio.h>
#include <stdbool.h>

int main(){
  printf("Welcome to Smart Home Light Control!\n");
  
  bool isDaytime = false;
  int time = 8;
  bool motionDetected = false;
  bool lightsOn = false;
  
  printf("Is it daytime? (0 for no, 1 for yes): ");
  scanf("%d", &isDaytime);
  
  printf("What time is it? (24 hour format): ");
  scanf("%d", &time);
  
  if (isDaytime || (time >= 7 && time <= 21)){
    printf("It's daytime, lights are OFF\n");
  } else {
    printf("It's nighttime, lights are ON\n");
    lightsOn = true;
  }
  
  printf("Is motion detected? (0 for no, 1 for yes): ");
  scanf("%d", &motionDetected);
  
  if (motionDetected && !lightsOn){
    printf("Motion detected! Lights are turning ON\n");
    lightsOn = true;
  } else if (!motionDetected && lightsOn) {
    printf("No motion detected for 5 minutes. Lights are turning OFF\n");
    lightsOn = false;
  } else {
    printf("No change to lights\n");
  }
  
  return 0;
}