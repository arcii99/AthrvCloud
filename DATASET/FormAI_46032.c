//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: thoughtful
#include <stdio.h>
#include <math.h>

int main()
{
  double x1, y1, r1, x2, y2, r2, distance;

  //Get the coordinates and radii of both circles
  printf("Enter the coordinates and radius of circle 1: ");
  scanf("%lf %lf %lf", &x1, &y1, &r1);
  printf("Enter the coordinates and radius of circle 2: ");
  scanf("%lf %lf %lf", &x2, &y2, &r2);

  //Calculate the distance between the centers of the circles
  distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

  //Check if the circles intersect each other
  if (distance <= (r1 + r2))
  {
    //Find the area of intersection of the circles
    double d = distance;
    double r_1 = r1;
    double r_2 = r2;
    double A_r1 = (2*r_1*r_1*r_1)/3 - (d*d*d)/3 + d*d*r_1/2 - r_1*r_1*acos((d*d + r_1*r_1 - r_2*r_2)/(2*d*r_1))/2 - (d-r_1)*sqrt(r_1*r_1 - pow((d-r_1),2)/4);
    double A_r2 = (2*r_2*r_2*r_2)/3 - (d*d*d)/3 + d*d*r_2/2 - r_2*r_2*acos((d*d + r_2*r_2 - r_1*r_1)/(2*d*r_2))/2 - (d-r_2)*sqrt(r_2*r_2 - pow((d-r_2),2)/4);
    double A_intersection = A_r1 + A_r2;

    printf("The circles intersect each other and their intersection area is %lf\n", A_intersection);
  }
  else
  {
    printf("The circles do not intersect each other\n");
  }

  return 0;
}