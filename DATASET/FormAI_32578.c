//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Romeo and Juliet
#include<stdio.h>
#include<math.h>
int main()
{
   int x1,x2,y1,y2,d;
   printf("Enter the co-ordinates of two points in a plane:\n");
   scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
   d=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
   printf("The distance between the given co-ordinates is: %d\n",d);
   return 0;
}