//FormAI DATASET v1.0 Category: Scientific ; Style: thoughtful
#include<stdio.h>
#include<math.h>

int main() {
   float a, b, c, discriminant, root1, root2, realPart, imaginaryPart;

   printf("Enter coefficients a, b, and c: ");
   scanf("%f %f %f",&a, &b, &c);

   // calculate discriminant
   discriminant = b*b - 4*a*c;

   // check if discriminant is positive, negative, or zero and calculate roots accordingly
   if (discriminant > 0) {
      root1 = (-b + sqrt(discriminant))/(2*a);
      root2 = (-b - sqrt(discriminant))/(2*a);
      printf("Roots are real and different: %.2f and %.2f", root1, root2);
   }
   else if (discriminant == 0) {
      root1 = root2 = -b/(2*a);
      printf("Roots are real and same: %.2f and %.2f", root1, root2);
   }
   else {
      realPart = -b/(2*a);
      imaginaryPart = sqrt(-discriminant)/(2*a);
      printf("Roots are complex and different: %.2f + %.2fi and %.2f - %.2fi", realPart, imaginaryPart, realPart, imaginaryPart);
   }

   return 0;
}