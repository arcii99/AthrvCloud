//FormAI DATASET v1.0 Category: Data mining ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the data mining statistical example program.\n");

  int num_data_points;
  printf("How many data points do you have? ");
  scanf("%d", &num_data_points);

  int *data = (int*) malloc(num_data_points * sizeof(int));

  printf("Please input your data points:\n");
  for(int i=0; i<num_data_points; i++) {
    scanf("%d", &data[i]);
  }

  // calculate mean
  double sum = 0.0;
  for(int i=0; i<num_data_points; i++) {
    sum += data[i];
  }
  double mean = sum / num_data_points;

  printf("The mean of your data points is: %f\n", mean);

  // calculate standard deviation
  double variance = 0.0;
  for(int i=0; i<num_data_points; i++) {
    variance += (data[i] - mean) * (data[i] - mean);
  }
  double std_dev = sqrt(variance / num_data_points);

  printf("The standard deviation of your data points is: %f\n", std_dev);

  // find outliers
  printf("The following data points are outliers (more than 2 standard deviations from the mean):\n");
  for(int i=0; i<num_data_points; i++) {
    if(abs(data[i] - mean) > 2*std_dev) {
      printf("%d ", data[i]);
    }
  }

  free(data);
  return 0;
}