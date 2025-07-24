//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int temp = getTemperature();
  int threshold = 25;
  
  printf("Initializing CyberTemp monitor...\n");
  printf("Current temperature is %d°C\n", temp);
  
  while (1) {
    temp = getTemperature();
    
    if (temp > threshold) {
      printf("ALERT: Temperature has exceeded CyberSafe limits!\n");
      printf("Current temperature is %d°C\n", temp);
      printf("Initiating CyberCool cooling system...\n");
      activateCoolingSystem();
    } else {
      printf("Temperature is within acceptable limits.\n");
      printf("Current temperature is %d°C\n", temp);
    }
    
    delay(10000);
  }
  
  return 0;
}

int getTemperature() {
  srand(time(NULL));
  int temp = rand() % 40;
  return temp;
}

void activateCoolingSystem() {
  printf("CyberCool cooling system activated. Initiating cooling process...\n");
  int cooling_time = rand() % 60 + 10;
  printf("Cooling will take approximately %d seconds.\n", cooling_time);
  delay(cooling_time * 1000);
  printf("Cooling process complete. CyberTemp monitor now returning to normal operation.\n");
}

void delay(int milliseconds) {
  clock_t start_time = clock();
  while (clock() < start_time + milliseconds);
}