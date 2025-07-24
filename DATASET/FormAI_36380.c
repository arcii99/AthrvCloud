//FormAI DATASET v1.0 Category: Temperature monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  float temp;
  int count = 0;
  time_t now;
  struct tm *current;
  
  printf("Welcome to the Temperature Monitor!\n");

  while (count < 10) {
    time(&now);
    current = localtime(&now);

    srand((unsigned int) time(NULL));
    temp = (rand() % 100) - 40;
    
    printf("Temperature at %d:%d:%d is %.2f degrees Celsius.\n", current->tm_hour, current->tm_min, current->tm_sec, temp);

    if (temp > 30) {
      printf("*** WARNING: Temperature is above 30 degrees Celsius! ***\n");
    }
    
    count++;
    sleep(1); // wait 1 second before next temperature reading
  }
  
  printf("Thank you for using the Temperature Monitor!\n");

  return 0;
}