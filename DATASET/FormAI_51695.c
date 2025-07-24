//FormAI DATASET v1.0 Category: Educational ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int i, j, n, sum;
  float mean, var, std_dev;
  int data[50];
  
  /* Generate Random Data */
  srand(time(NULL));
  for(i = 0; i < 50; i++)
    data[i] = rand() % 100;
  
  /* Calculate Mean */
  sum = 0;
  for(i = 0; i < 50; i++)
    sum += data[i];
  mean = (float) sum / 50;
  
  /* Calculate Variance */
  var = 0.0;
  for(i = 0; i < 50; i++)
    var += (data[i] - mean) * (data[i] - mean);
  var /= 50;
  
  /* Calculate Standard Deviation */
  std_dev = sqrt(var);
  
  /* Print Results */
  printf("Data:\n");
  for(i = 0; i < 50; i++)
    printf("%d, ", data[i]);
  printf("\n\n");
  
  printf("Mean: %.2f\n", mean);
  printf("Variance: %.2f\n", var);
  printf("Standard Deviation: %.2f\n", std_dev);
  
  return 0;
}