//FormAI DATASET v1.0 Category: Data mining ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_SIZE 1000
#define DATA_RANGE 100

int main()
{
     int data[ARRAY_SIZE];
     int frequency[DATA_RANGE] = {0};
     int mean = 0, median = 0, mode = 0;
     int max_frequency = 0;

     // Generate random data values and calculate frequency
     for (int i = 0; i < ARRAY_SIZE; i++)
     {
          data[i] = rand() % DATA_RANGE;
          frequency[data[i]]++;
          mean += data[i];
     }
     
     // Calculate the mean (average)
     mean /= ARRAY_SIZE;

     // Sort the data
     for (int i = 0; i < ARRAY_SIZE; i++)
     {
          for (int j = i + 1; j < ARRAY_SIZE; j++)
          {
               if (data[i] > data[j])
               {
                    int temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
               }
          }
     }

     // Calculate the median
     if (ARRAY_SIZE % 2 == 0)
     {
          median = (data[ARRAY_SIZE / 2] + data[(ARRAY_SIZE / 2) - 1]) / 2;
     }
     else
     {
          median = data[ARRAY_SIZE / 2];
     }

     // Calculate the mode
     for (int i = 0; i < DATA_RANGE; i++)
     {
          if (frequency[i] > max_frequency)
          {
               max_frequency = frequency[i];
               mode = i;
          }
     }

     // Print out the results
     printf("Mean: %d\n", mean);
     printf("Median: %d\n", median);
     printf("Mode: %d\n", mode);

     return 0;
}