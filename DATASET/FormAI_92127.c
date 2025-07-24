//FormAI DATASET v1.0 Category: Temperature monitor ; Style: relaxed
#include <stdio.h>

int main() {
  float temp[5];
  float avg = 0;
  int i;
  
  printf("Please enter 5 temperature readings:\n");
  
  for (i = 0; i < 5; i++) {
    printf("Temperature reading %d: ", i+1);
    scanf("%f", &temp[i]);
    avg += temp[i];
  }
  
  avg /= i;
  
  printf("\nAverage temperature: %.2f\n\n", avg);
  
  for (i = 0; i < 5; i++) {
    if (temp[i] > avg) {
      printf("Reading %d is higher than the average.\n", i+1);
    } else if (temp[i] < avg) {
      printf("Reading %d is lower than the average.\n", i+1);
    } else {
      printf("Reading %d is equal to the average.\n", i+1);
    }
  }
  
  return 0;
}