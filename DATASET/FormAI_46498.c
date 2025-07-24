//FormAI DATASET v1.0 Category: Math exercise ; Style: authentic
#include<stdio.h>
#include<math.h>

int main()
{
  int x1, x2, y1, y2;
  float distance;
  
  // Input coordinates from user
  printf("Enter coordinates of point1: ");
  scanf("%d %d",&x1, &y1);
  
  printf("Enter coordinates of point2: ");
  scanf("%d %d",&x2, &y2);
  
  // Calculate distance between two points
  distance = sqrt( pow((x2-x1), 2) + pow((y2-y1),2) );
  
  // Print the calculated distance
  printf("\nDistance between point1(%d,%d) and point2(%d,%d) is: %.2f", x1,y1,x2,y2,distance);
  
  // Calculate midpoint between two points
  float mid_x, mid_y;
  mid_x = (x1+x2)/2.0;
  mid_y = (y1+y2)/2.0;
  
  // Print the midpoint coordinates
  printf("\nMidpoint between point1(%d,%d) and point2(%d,%d) is: (%.2f,%.2f)", x1,y1,x2,y2,mid_x,mid_y);
  
  // Calculate slope of the line passing through two points
  float slope;
  slope = (float)(y2-y1)/(x2-x1);
  
  // Print the slope of the line
  printf("\nThe slope of line passing through point1(%d,%d) and point2(%d,%d) is: %.2f", x1,y1,x2,y2,slope);
  
  // Calculate y-intercept of the line
  float y_intercept;
  y_intercept = y1 - slope*x1;
  
  // Print the y-intercept of the line
  printf("\nThe y-intercept of line passing through point1(%d,%d) and point2(%d,%d) is: %.2f", x1,y1,x2,y2,y_intercept);
  
  return 0;
}