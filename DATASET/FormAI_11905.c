//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: surprised
#include<stdio.h>
#include<math.h>

int main(){

   printf("Welcome to the Geometric Algorithms Surprise Example!\n\n");

   double x1, y1, x2, y2, d;

   printf("Enter coordinates of Point 1: ");
   scanf("%lf %lf", &x1, &y1);

   printf("Enter coordinates of Point 2: ");
   scanf("%lf %lf", &x2, &y2);

   //Euclidean Distance Calculation
   d = sqrt(pow(x2-x1,2) + pow(y2-y1,2));

   printf("\nThe Euclidean Distance between Point 1 and Point 2 is: %lf\n", d);

   int n;
   printf("\nEnter the number of sides for the regular polygon: ");
   scanf("%d", &n);

   double r, apothem, perimeter, area;

   printf("Enter the length of the apothem: ");
   scanf("%lf", &apothem);

   //Radius Calculation
   r = apothem/cos(3.14159/n);

   //Perimeter Calculation
   perimeter = 2*n*r*sin(3.14159/n);

   //Area Calculation
   area = 0.5*n*r*r*sin((2*3.14159)/n);

   printf("\nThe radius of the regular polygon is: %lf\n", r);
   printf("The perimeter of the regular polygon is: %lf\n", perimeter);
   printf("The area of the regular polygon is: %lf\n", area);

   printf("\nThank you for using the Geometric Algorithms Surprise Example! Hope you enjoyed it\n");

   return 0;
}