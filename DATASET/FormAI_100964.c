//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: high level of detail
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main()
{
   /* Initialize variables */
   double radius, height, area, volume;
   double slantHeight, lateralArea, baseArea;

   /* Input radius and height from user */
   printf("Enter the radius of the cone: ");
   scanf("%lf", &radius);
   printf("Enter the height of the cone: ");
   scanf("%lf", &height);

   /* Calculate slant height, lateral area, base area, total surface area and volume of the cone */
   slantHeight = sqrt(pow(radius,2) + pow(height,2));
   lateralArea = PI * radius * slantHeight;
   baseArea = PI * pow(radius,2);
   area = lateralArea + baseArea;
   volume = (PI * pow(radius,2) * height) / 3;

   /* Output the results */
   printf("Slant height of the cone = %.2lf units\n", slantHeight);
   printf("Lateral area of the cone = %.2lf sq.units\n", lateralArea);
   printf("Base area of the cone = %.2lf sq.units\n", baseArea);
   printf("Total surface area of the cone = %.2lf sq.units\n", area);
   printf("Volume of the cone = %.2lf cubic units\n", volume);

   return 0;
}