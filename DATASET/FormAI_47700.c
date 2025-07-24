//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: innovative
#include<stdio.h>

struct Point{
  int x;
  int y;
};

int main(){
  struct Point p1, p2, p3;
  printf("Enter the coordinates of point 1: ");
  scanf("%d %d", &p1.x, &p1.y);
  printf("Enter the coordinates of point 2: ");
  scanf("%d %d", &p2.x, &p2.y);
  printf("Enter the coordinates of point 3: ");
  scanf("%d %d", &p3.x, &p3.y);

  // Calculating the distance between p1 and p2
  int dx1 = p2.x - p1.x;
  int dy1 = p2.y - p1.y;
  int d1 = dx1*dx1 + dy1*dy1;

  // Calculating the distance between p2 and p3
  int dx2 = p3.x - p2.x;
  int dy2 = p3.y - p2.y;
  int d2 = dx2*dx2 + dy2*dy2;

  // Calculating the distance between p1 and p3
  int dx3 = p3.x - p1.x;
  int dy3 = p3.y - p1.y;
  int d3 = dx3*dx3 + dy3*dy3;

  // Check if the triangle is valid
  if(d1+d2 == d3 || d2+d3 == d1 || d1+d3 == d2){
    printf("The triangle is a right angled triangle.\n");
  }else{
    printf("The triangle is not a right angled triangle.\n");
  }

  return 0;
}