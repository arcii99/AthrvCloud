//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: complete
#include<stdio.h>
#include<math.h>

typedef struct {
  double x;
  double y;
} point;

double distance(point a, point b){
  return sqrt(pow(a.x - b.x,2) + pow(a.y - b.y,2));
}

double triangle_area(point a, point b, point c){
  double s, sideA, sideB, sideC;

  sideA = distance(a,b);
  sideB = distance(b,c);
  sideC = distance(c,a);
  s = (sideA + sideB + sideC) / 2.0;

  return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

int main(){
  point a, b, c;
  printf("Enter coordinates of point A: ");
  scanf("%lf%lf", &a.x, &a.y);
  printf("Enter coordinates of point B: ");
  scanf("%lf%lf", &b.x, &b.y);
  printf("Enter coordinates of point C: ");
  scanf("%lf%lf", &c.x, &c.y);

  double area = triangle_area(a,b,c);
  printf("Area of triangle ABC is: %lf\n", area);

  return 0;
}