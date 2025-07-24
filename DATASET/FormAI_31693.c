//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: enthusiastic
#include <stdio.h>
#include <math.h>

int main() {
  printf("Let's calculate the area and perimeter of a circle!\n");
  
  float radius;
  printf("Enter the radius of the circle: ");
  scanf("%f", &radius);

  float area = M_PI * pow(radius, 2);
  printf("The area of the circle is: %f\n", area);

  float perimeter = 2 * M_PI * radius;
  printf("The perimeter of the circle is: %f\n", perimeter);

  printf("Now let's calculate the distance between two points!\n");
  
  float x1, y1, x2, y2;
  printf("Enter the coordinates of Point 1 (x1, y1): ");
  scanf("%f %f", &x1, &y1);
  
  printf("Enter the coordinates of Point 2 (x2, y2): ");
  scanf("%f %f", &x2, &y2);

  float distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
  printf("The distance between Point 1 and Point 2 is: %f\n", distance);
  
  printf("That was fun! Let's calculate one more thing.\n");
  
  float side;
  printf("Enter the length of one side of a square: ");
  scanf("%f", &side);

  float diagonal = sqrt(2 * pow(side, 2));
  printf("The diagonal of the square is: %f\n", diagonal);

  printf("Thanks for calculating with me! Have a great day!\n");

  return 0;
}