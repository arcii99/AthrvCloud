//FormAI DATASET v1.0 Category: Math exercise ; Style: relaxed
#include <stdio.h>
#include <math.h>

int main() {
   // greeting message
   printf("Welcome to our algebraic equations exercise program!\n\n");
   
   // declaring variables
   float a, b, c, x1, x2, x3, discriminant, realPart, imaginaryPart;
   
   // receiving input from user
   printf("Please enter the coefficient 'a': ");
   scanf("%f", &a);
   
   printf("Please enter the coefficient 'b': ");
   scanf("%f", &b);
   
   printf("Please enter the coefficient 'c': ");
   scanf("%f", &c);
   
   // calculating discriminant
   discriminant = (b * b) - (4 * a * c);
   
   // checking discriminant and solving equations accordingly
   if (discriminant > 0) {
      x1 = (-b+sqrt(discriminant))/(2*a);
      x2 = (-b-sqrt(discriminant))/(2*a);
      printf("\nThere are two real roots: x = %.2f and x = %.2f\n", x1, x2);
   } else if (discriminant == 0) {
      x1 = (-b)/(2*a);
      printf("\nThere is one real root: x = %.2f\n", x1);
   } else {
      realPart = (-b)/(2*a);
      imaginaryPart = sqrt(-discriminant)/(2*a);
      printf("\nThere are two complex roots: x = %.2f + %.2fi and x = %.2f - %.2fi\n", realPart, imaginaryPart, realPart, imaginaryPart);
   }
   
   // solving for x3 using the previous solutions
   x3 = pow(x1, 2) + pow(x2, 2);
   printf("\nNow, solve for x3 given that x1 = %.2f and x2 = %.2f\n", x1, x2);
   
   // receiving input from user for x3
   float userAnswer;
   printf("x3 = ");
   scanf("%f", &userAnswer);
   
   // checking user's answer
   if (userAnswer == x3) {
      printf("\nCongratulations! You solved the equation correctly.\n");
   } else {
      printf("\nSorry, your answer is incorrect. The correct answer is x3 = %.2f\n", x3);
   }
  
   return 0;
}