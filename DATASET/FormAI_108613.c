//FormAI DATASET v1.0 Category: System boot optimizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

/* This program is a C System boot optimizer that optimizes and speeds up the boot process
   by analyzing statistical data and making adjustments to the system startup sequence.*/

int main(){

  srand(time(0));   // initialize random seed

  int bootOrder[10] = {1,2,3,4,5,6,7,8,9,10};  // array of boot order sequence
  int bootTime[10] = {10,15,20,25,30,35,40,45,50,55}; // array of boot times in seconds
  int totalBootTime = 0;
  int i, j;

  // Display original boot sequence and times
  printf("Original Boot Sequence: \n");
  for (i = 0; i < 10; i++){
    printf("%d. Boot time: %d seconds \n", bootOrder[i], bootTime[i]);
    totalBootTime += bootTime[i];
  }

  printf("Total boot time: %d seconds \n", totalBootTime);
  printf("\n");

  // Statistical analysis - assess the average and standard deviation of the boot times 
  int sum = 0;
  double mean, variance, std_deviation;
  for (i = 0; i < 10; i++){
    sum += bootTime[i];
  }

  mean = (double) sum / 10;

  for (i = 0; i < 10; i++){
    variance += (bootTime[i] - mean)*(bootTime[i] - mean);
  }

  variance = variance/10;
  std_deviation = sqrt(variance);

  printf("Statistical Analysis: \n");
  printf("Mean: %lf \n", mean);
  printf("Variance : %lf \n", variance);
  printf("Standard Deviation: %lf \n", std_deviation);
  printf("\n");

  // Optimization - re-arrange the boot order sequence based on a randomized algorithm that minimizes the standard deviation
  int temp, min_deviation = std_deviation;
  int optimizedBootOrder[10];
  for (i = 0; i < 100; i++){
    for (j = 0; j < 10; j++){
      int k = rand() % 10;
      temp = bootOrder[j];
      bootOrder[j] = bootOrder[k];
      bootOrder[k] = temp;
    }

    double deviation = 0;
    for (j = 0; j < 10; j++){
      optimizedBootOrder[j] = bootOrder[j];
      deviation += (bootTime[j] - mean)*(bootTime[j] - mean);
    }

    deviation /= 10;
    deviation = sqrt(deviation);

    if(deviation < min_deviation){
      min_deviation = deviation;
      for(j = 0; j < 10; j++){
        bootOrder[j] = optimizedBootOrder[j];
      }
    }
  }

  // Display optimized boot sequence and times
  printf("Optimized Boot Sequence: \n");
  for (i = 0; i < 10; i++){
    printf("%d. Boot time: %d seconds \n", bootOrder[i], bootTime[bootOrder[i]-1]);
  }

  printf("Total boot time: %d seconds \n", totalBootTime);
  printf("Optimized boot time: %d seconds \n", totalBootTime-std_deviation);
  
  return 0;
}