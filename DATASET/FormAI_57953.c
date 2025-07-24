//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: creative
#include<stdio.h>

// This program will calculate the area of the irregular shape using the Shoelace formula

int main()
{
  int num_points;
  printf("Enter the number of points: ");
  scanf("%d", &num_points);
  
  if(num_points < 3)
  {
    printf("Invalid input, please enter at least 3 points.");
    return 0;
  }
  
  int x[num_points], y[num_points], i;
  printf("Enter the x and y coordinates of each point: \n");
  
  for(i=0; i<num_points; i++)
  {
    printf("Point %d: ", i+1);
    scanf("%d %d", &x[i], &y[i]);
  }
  
  // Calculate the area using the Shoelace formula
  int area = 0;
  for(i=0; i<num_points-1; i++)
  {
    area += x[i]*y[i+1] - x[i+1]*y[i];
  }
  area += x[num_points-1]*y[0] - x[0]*y[num_points-1];
  area = abs(area)/2;
  
  printf("The area of the irregular shape is %d.\n", area);
  
  return 0;
}