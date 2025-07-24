//FormAI DATASET v1.0 Category: Scientific ; Style: thoughtful
#include <stdio.h>
#include <math.h>

int main() {
   float n;
   
   printf("Please enter a number: ");
   scanf("%f", &n);
   
   printf("\nTrigonometric functions of %f:\n", n);
   
   printf("\nsine of %f = %f", n, sin(n));
   printf("\ncosine of %f = %f", n, cos(n));
   printf("\ntangent of %f = %f", n, tan(n));
   printf("\nsecant of %f = %f", n, 1/cos(n));
   printf("\ncosecant of %f = %f", n, 1/sin(n));
   printf("\ncotangent of %f = %f\n", n, 1/tan(n));
   
   printf("\nHyperbolic functions of %f:\n", n);
   
   printf("\nsineh of %f = %f", n, sinh(n));
   printf("\ncosineh of %f = %f", n, cosh(n));
   printf("\ntangenth of %f = %f", n, tanh(n));
   printf("\nsecanth of %f = %f", n, 1/cosh(n));
   printf("\ncosecanth of %f = %f", n, 1/sinh(n));
   printf("\ncotangenth of %f = %f\n\n", n, 1/tanh(n));
      
   return 0;
}