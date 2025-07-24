//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: synchronous
#include<stdio.h>
#include<math.h>

int main()
{
  int a,b,radius;
  float area,perimeter;
  printf("Enter sides of rectangle: ");
  scanf("%d%d",&a,&b);
  
  printf("Enter radius of circle: ");
  scanf("%d",&radius);
  
  // Area of rectangle
  area = a*b;
  printf("\nArea of rectangle is: %.2f",area);
  
  // Perimeter of rectangle
  perimeter = 2*(a+b);
  printf("\nPerimeter of rectangle is: %.2f",perimeter);
  
  // Area of Circle
  area = 3.14*radius*radius;
  printf("\nArea of circle is: %.2f",area);
  
  // Circumference of Circle
  perimeter = 2*3.14*radius;
  printf("\nCircumference of circle is: %.2f",perimeter);
  
  // Length of diagonal of rectangle
  printf("\nLength of diagonal of rectangle is: %.2f",sqrt(a*a+b*b));
  
  return 0;
}