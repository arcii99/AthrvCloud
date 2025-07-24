//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: grateful
#include <stdio.h>
#include <math.h>

//Constants
#define PI 3.14159265358979323846

//Structure to represent a point in 2D space
struct Point 
{
   int x, y;
};

//Function to calculate distance between two points
float distance(struct Point p1, struct Point p2) 
{
   float dist = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
   return dist;
}

//Function to calculate area of triangle
float area(struct Point p1, struct Point p2, struct Point p3) 
{
   float a = distance(p1, p2);
   float b = distance(p2, p3);
   float c = distance(p3, p1);
   float s = (a + b + c) / 2;
   float area = sqrt(s * (s - a) * (s - b) * (s - c));
   return area;
}

//Function to calculate angle between three points
float angle(struct Point p1, struct Point p2, struct Point p3)
{
   float dx1 = p1.x - p2.x;
   float dy1 = p1.y - p2.y;
   float dx2 = p3.x - p2.x;
   float dy2 = p3.y - p2.y;
   float dot = dx1*dx2 + dy1*dy2;
   float det = dx1*dy2 - dy1*dx2;
   float rad = atan2(det, dot); 
   float angle = rad*180.0/PI; 
   return angle;
}

//Function to check if 3 points are colinear or not
int colinear(struct Point p1, struct Point p2, struct Point p3)
{
   int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
   if (val == 0)
      return 1;  //Points are colinear
   else 
      return 0;  //Points are not colinear
}

//Function to check if a point lies inside a triangle or not
int insideTriangle(struct Point p1, struct Point p2, struct Point p3, struct Point p)
{
   // Calculate area of triangle ABC 
   float A = area (p1, p2, p3);
  
   // Calculate area of triangle PBC 
   float A1 = area (p, p2, p3);
  
   // Calculate area of triangle PAC 
   float A2 = area (p1, p, p3);
  
   // Calculate area of triangle PAB  
   float A3 = area (p1, p2, p);

   // Check if sum of A1, A2 and A3 is same as A
   return A == A1 + A2 + A3;
}

//Main function
int main() 
{
   //Create points
   struct Point p1, p2, p3, p4;
   p1.x = 0; p1.y = 0;
   p2.x = 5; p2.y = 0;
   p3.x = 0; p3.y = 5;
   p4.x = 2; p4.y = 2;

   //Distance between p1 and p2
   float dist = distance(p1, p2);
   printf("Distance between (%d,%d) and (%d,%d) is %f\n", p1.x, p1.y, p2.x, p2.y, dist);

   //Area of triangle formed by p1, p2 and p3
   float a = area(p1, p2, p3);
   printf("Area of triangle formed by points (%d,%d), (%d,%d) and (%d,%d) is %f\n", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, a);

   //Angle between p1-p2-p3
   float ang = angle(p1, p2, p3);
   printf("Angle between points (%d,%d), (%d,%d) and (%d,%d) is %f degrees\n", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, ang);

   //Check if p1, p2 and p3 are colinear
   int coll = colinear(p1, p2, p3);
   if(coll)
      printf("Points (%d,%d), (%d,%d) and (%d,%d) are colinear\n", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
   else
      printf("Points (%d,%d), (%d,%d) and (%d,%d) are not colinear\n", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);

   //Check if point p4 lies inside triangle p1, p2 and p3
   int inside = insideTriangle(p1, p2, p3, p4);
   if(inside)
      printf("Point (%d,%d) lies inside  triangle formed by points (%d,%d), (%d,%d) and (%d,%d)\n", p4.x, p4.y, p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
   else
      printf("Point (%d,%d) lies outside triangle formed by points (%d,%d), (%d,%d) and (%d,%d)\n", p4.x, p4.y, p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);

   return 0;
}