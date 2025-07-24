//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct point {
   int x, y;
};

double getDistance(struct point a,struct point b) {
   double distance;
   distance = sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
   return distance;
}

int orientation(struct point a,struct point b,struct point c) {
   float orientation = (b.y-a.y)*(c.x-b.x)-(c.y-b.y)*(b.x-a.x);
   if(orientation == 0) {
      return 0;
   } else if(orientation > 0) {
      return 1;
   } else {
      return -1;
   }
}

void convexHull(struct point points[],int n) {
   if(n < 3) {
      printf("Convex Hull not possible\n");
      return;
   }
   int hull[n];
   for(int i=0; i<n; i++) {
      hull[i] = -1;
   }

   int leftMost = 0;
   for(int i=1; i<n; i++) {
      if(points[i].x < points[leftMost].x) {
         leftMost = i;
      }
   }

   int p = leftMost;
   int q;
   int k = 0;
   do {
      hull[k] = p;
      q = (p+1)%n;
      for(int i=0; i<n; i++) {
         if(orientation(points[p],points[i],points[q]) == -1) {
            q = i;
         }
      }
      p = q;
      k++;
   } while(p != leftMost);

   printf("Convex Hull Points: \n");
   for(int i=0; i<k; i++) {
      printf("(%d,%d)\n",points[hull[i]].x,points[hull[i]].y);
   }
}

int main() {
   struct point points[] = {{0,0}, {0,4}, {2,2}, {4,4}, {4,0}, {1,2}};
   int n = sizeof(points)/sizeof(points[0]);
   convexHull(points, n);
   return 0;
}