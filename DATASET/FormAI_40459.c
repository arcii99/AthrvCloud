//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: detailed
#include <stdio.h>

int main() {
   int x1, y1, x2, y2, distance;
   
   printf("Enter the current position of the RC vehicle (x1, y1): ");
   scanf("%d %d", &x1, &y1);
   
   printf("Enter the destination position of the RC vehicle (x2, y2): ");
   scanf("%d %d", &x2, &y2);
   
   distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
   
   printf("The distance between the current position and destination is: %d", distance);
   
   return 0;
}