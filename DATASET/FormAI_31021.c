//FormAI DATASET v1.0 Category: Math exercise ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* The goal of this program is to generate a set of 10 random numbers
 * between 0 and 100, and then calculate their average, standard deviation,
 * and coefficient of variation. */

int main() {
  double num_list[10];
  double sum = 0.0, sum_squared = 0.0;
  srand((unsigned int) time(NULL));

  // Generate 10 random numbers between 0 and 100
  for (int i = 0; i < 10; i++) {
    double rand_num = (double) rand() / RAND_MAX * 100;
    num_list[i] = rand_num;
    sum += rand_num;
    sum_squared += pow(rand_num, 2.0);
  }

  double mean = sum / 10.0;  // Calculate mean
  double variance = sum_squared / 10.0 - pow(mean, 2.0);  // Calculate variance
  double stdev = sqrt(variance);  // Calculate standard deviation
  double cv = stdev / mean * 100.0;  // Calculate coefficient of variation

  // Print out the numbers and their statistics
  printf("The set of 10 random numbers is:\n");
  for (int i = 0; i < 10; i++) {
    printf("%d: %.2f\n", i+1, num_list[i]);
  }

  printf("\nThe mean is: %.2f\n", mean);
  printf("The standard deviation is: %.2f\n", stdev);
  printf("The coefficient of variation is: %.2f%%\n", cv);
  
  return 0;
}