//FormAI DATASET v1.0 Category: Temperature monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int temperature;
  srand(time(NULL));
  printf("Initializing C Temperature Monitor v1.0...\n\n");
  for(int i = 1; i <= 10; i++) {
    temperature = rand() % 61 - 20;
    printf("Reading temperature: %dC\n", temperature);
    if(temperature > 30) {
      printf("*** WARNING: Temperature is above recommended threshold! ***\n\n");
    } else if(temperature < 0) {
      printf("*** WARNING: Temperature is below freezing point! ***\n\n");
    } else {
      printf("Temperature is within normal range.\n\n");
    }
    sleep(1);
  }
  printf("Shutting down C Temperature Monitor v1.0...\n");
  return 0;
}