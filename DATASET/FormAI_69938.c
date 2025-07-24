//FormAI DATASET v1.0 Category: Math exercise ; Style: multivariable
#include <stdio.h>
#include <math.h>

int main() {
   double x, y, z, result;
   printf("Enter the value of x: ");
   scanf("%lf", &x);
   printf("Enter the value of y: ");
   scanf("%lf", &y);
   printf("Enter the value of z: ");
   scanf("%lf", &z);

   result = pow(x,2) + pow(y,2) + pow(z,2) + 2*x*y + 2*y*z + 2*z*x;

   printf("The value of F(x, y, z) = x^2 + y^2 + z^2 + 2xy + 2yz + 2zx is: %lf\n\n", result);

   double a, b, c, dis, r1, r2;
   printf("Enter the value of a: ");
   scanf("%lf", &a);
   printf("Enter the value of b: ");
   scanf("%lf", &b);
   printf("Enter the value of c: ");
   scanf("%lf", &c);

   dis = pow(b,2) - 4*a*c;

   if (dis > 0) {
      r1 = (-b + sqrt(dis)) / (2*a);
      r2 = (-b - sqrt(dis)) / (2*a);
      printf("The roots are real and different.\n");
      printf("Root1 = %.2lf and Root2 = %.2lf\n\n", r1, r2);
   }
   else if (dis == 0) {
      r1 = r2 = -b / (2*a);
      printf("The roots are real and same.\n");
      printf("Root1 = Root2 = %.2lf\n\n", r1);
   }
   else {
      double realPart = -b / (2*a);
      double imaginaryPart = sqrt(-dis) / (2*a);
      printf("The roots are complex and different.\n");
      printf("Root1 = %.2lf + %.2lfi and Root2 = %.2lf - %.2lfi\n\n", realPart, imaginaryPart, realPart, imaginaryPart);
   }

   double hyp, opp, adj, perimeter, area;
   printf("Enter the value of hypotenuse: ");
   scanf("%lf", &hyp);
   printf("Enter the value of opposite: ");
   scanf("%lf", &opp);
   printf("Enter the value of adjacent: ");
   scanf("%lf", &adj);

   perimeter = hyp + opp + adj;
   double s = perimeter / 2;
   area = sqrt(s*(s-hyp)*(s-opp)*(s-adj));

   printf("The perimeter of the triangle is: %lf\n", perimeter);
   printf("The area of the triangle is: %lf\n\n", area);

   return 0;
}