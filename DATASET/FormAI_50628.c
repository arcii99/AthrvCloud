//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: medieval
#include <stdio.h>
#include <math.h>
 
float getArea(int x1, int y1, int x2, int y2, int x3, int y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}
 
int isInside(int x1, int y1, int x2, int y2, int x3, int y3, int px, int py)
{   
   float A = getArea (x1, y1, x2, y2, x3, y3);
   float A1 = getArea (px, py, x2, y2, x3, y3);
   float A2 = getArea (x1, y1, px, py, x3, y3);
   float A3 = getArea (x1, y1, x2, y2, px, py);
   return (A == A1 + A2 + A3);
}
 
int main()
{
   int x1,y1,x2,y2,x3,y3,px,py;

   printf("Enter the three vertices of the triangle:\n");
   scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);

   printf("Enter the coordinates of the point to check: ");
   scanf("%d %d",&px,&py);

   if(isInside(x1, y1, x2, y2, x3, y3, px, py))
      printf("The point is inside the triangle.\n");
   else
      printf("The point is outside the triangle.\n");
 
   return 0;
}