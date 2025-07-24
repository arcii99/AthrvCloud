//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: relaxed
#include<stdio.h>
#include<math.h>
int main()
{
 int ch;
 double a,b;
 printf("Welcome to my scientific calculator!\n");
 printf("Enter the operation to perform:\n");
 printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exponential\n6. Logarithmic\n7. Square root\n8. Sine\n9. Cosine\n10. Tangent\n");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:
   printf("Enter two numbers:\n");
   scanf("%lf%lf",&a,&b);
   printf("%.2lf + %.2lf = %.2lf\n",a,b,a+b);
   break;
  case 2:
   printf("Enter two numbers:\n");
   scanf("%lf%lf",&a,&b);
   printf("%.2lf - %.2lf = %.2lf\n",a,b,a-b);
   break;
  case 3:
   printf("Enter two numbers:\n");
   scanf("%lf%lf",&a,&b);
   printf("%.2lf * %.2lf = %.2lf\n",a,b,a*b);
   break;
  case 4:
   printf("Enter two numbers:\n");
   scanf("%lf%lf",&a,&b);
   printf("%.2lf / %.2lf = %.2lf\n",a,b,a/b);
   break;
  case 5:
   printf("Enter the base and exponent:\n");
   scanf("%lf%lf",&a,&b);
   printf("%.2lf^%.2lf = %.2lf\n",a,b,pow(a,b));
   break;
  case 6:
   printf("Enter the number:\n");
   scanf("%lf",&a);
   printf("log(%.2lf) = %.2lf\n",a,log10(a));
   break;
  case 7:
   printf("Enter the number:\n");
   scanf("%lf",&a);
   printf("sqrt(%.2lf) = %.2lf\n",a,sqrt(a));
   break;
  case 8:
   printf("Enter the angle in degrees:\n");
   scanf("%lf",&a);
   printf("sin(%.2lf) = %.2lf\n",a,sin(a*M_PI/180));
   break;
  case 9:
   printf("Enter the angle in degrees:\n");
   scanf("%lf",&a);
   printf("cos(%.2lf) = %.2lf\n",a,cos(a*M_PI/180));
   break;
  case 10:
   printf("Enter the angle in degrees:\n");
   scanf("%lf",&a);
   printf("tan(%.2lf) = %.2lf\n",a,tan(a*M_PI/180));
   break;
  default:
   printf("Invalid operation!\n");
   break;
 }
 return 0;
}