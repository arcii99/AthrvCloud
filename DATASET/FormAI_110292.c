//FormAI DATASET v1.0 Category: Data mining ; Style: high level of detail
#include<stdio.h>

int main()
{
  int data[10] = {54, 23, 65, 78, 12, 45, 67, 23, 90, 83};
  int total = 0, max = data[0], min = data[0];
  float average;

  // Loop through the data to find the total, maximum and minimum values
  for(int i = 0; i < 10; i++)
  {
    total += data[i];
    if(data[i] > max)
    {
      max = data[i];
    }
    if(data[i] < min)
    {
      min = data[i];
    }
  }

  // Find the average value by dividing the total by the number of elements
  average = (float) total / 10;

  // Print out the results
  printf("Total = %d\n", total);
  printf("Maximum = %d\n", max);
  printf("Minimum = %d\n", min);
  printf("Average = %f\n", average);

  return 0;
}