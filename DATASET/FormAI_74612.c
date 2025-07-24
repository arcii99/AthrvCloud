//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: active
#include <stdio.h>
#include <math.h>

int main() {
   // Initializing the variables
   int numSides, i;
   float sideLen, area;

   // User input for number of sides and side length
   printf("Enter the number of sides in the polygon: ");
   scanf("%d", &numSides);
   printf("Enter the length of one side of the polygon: ");
   scanf("%f", &sideLen);

   // Checking if polygon has at least 3 sides
   if(numSides < 3){
       printf("Error: The polygon must have at least 3 sides!\n");
   }
   else{
       // Calculating the area of the polygon
       area = (numSides * sideLen * sideLen) / (4 * tan(M_PI / numSides));
       printf("The area of the polygon with %d sides and %.2f length of side is: %.2f\n", numSides, sideLen, area);
   }

   // Checking if the polygon is regular or irregular
   if(numSides == 3){
       printf("It is a triangle.");
   }
   else if(numSides == 4){
       printf("It is a quadrilateral.");
   }
   else if(numSides == 5){
       printf("It is a pentagon.");
   }
   else if(numSides == 6){
       printf("It is a hexagon.");
   }
   else if(numSides == 7){
       printf("It is a heptagon.");
   }
   else if(numSides == 8){
       printf("It is a octagon.");
   }
   else if(numSides > 8){
       printf("It is a polygon with %d sides.", numSides);
   }
   
   return 0;
}