//FormAI DATASET v1.0 Category: Arithmetic ; Style: scientific
#include <stdio.h>
#include <math.h>

int main()
{
  float x,y,z;
  int n;
  printf("Enter n: ");
  scanf("%d",&n);
  printf("Enter x: ");
  scanf("%f",&x);
  y = pow(x,n);     
  printf("x raised to the power n is: %f\n",y);
  z = sqrt(x);
  printf("Square root of x is: %f\n",z);
  printf("\n------------------------\n");
  printf("Enter two numbers: ");
  scanf("%f %f",&x,&y);
  printf("\n------------------------\n");  
  printf("Addition: %f + %f = %f\n",x,y,x+y);
  printf("Subtraction: %f - %f = %f\n",x,y,x-y);
  printf("Multiplication: %f * %f = %f\n",x,y,x*y);
  printf("Division: %f / %f = %f\n",x,y,x/y);
  printf("x Modulus y: %f\n",fmod(x,y));
  printf("\n------------------------\n");  
  printf("Enter p: ");
  scanf("%f",&x);
  printf("Enter q: ");
  scanf("%f",&y);
  printf("Enter r: ");
  scanf("%f",&z);
  float t = pow(x,3) - sqrt(y) + pow(z,4);
  printf("The value of p^3 - q^(1/2) + r^4: %f",t);
  
  return 0;
}