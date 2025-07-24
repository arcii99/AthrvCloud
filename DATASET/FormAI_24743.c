//FormAI DATASET v1.0 Category: Data mining ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#define ROWS 4
#define COLS 3

int main()
{
  int i, j, k, count;
  float data[ROWS][COLS] = {{1.2, 2.3, 3.4}, {4.5, 5.6, 6.7}, {7.8, 8.9, 9.0}, {2.9, 5.9, 7.1}};
  float sum[COLS] = {0.0};

  printf("Data Matrix\n");
  printf("-------------------\n");
  for(i=0; i<ROWS; i++)
  {
    for(j=0; j<COLS; j++)
    {
      printf("%.2f\t", data[i][j]);
      sum[j] += data[i][j];
    }
    printf("\n");
  }
  printf("-------------------\n");
  float mean[COLS];
  for(k=0; k<COLS; k++)
  {
    mean[k] = sum[k]/ROWS;
    printf("Mean of Column %d: %.2f\n", k+1, mean[k]);
  }

  float std_dev[COLS];
  for(k=0; k<COLS; k++)
  {
    count = 0;
    for(i=0; i<ROWS; i++)
    {
      if(data[i][k]<=mean[k])
        count++;
    }
    float p = (float)count/(float)ROWS;
    float q = 1 - p;
    std_dev[k] = sqrt(p*q);
    printf("Standard Deviation of Column %d: %.2f\n", k+1, std_dev[k]);
  }
  return 0;
}