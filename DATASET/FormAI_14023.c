//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

typedef struct {
  double x;
  double y;
  double z;
} Vec3;

double dot(Vec3 v1, Vec3 v2) {
  return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vec3 cross(Vec3 v1, Vec3 v2) {
  Vec3 result;
  result.x = v1.y * v2.z - v2.y * v1.z;
  result.y = v2.x * v1.z - v1.x * v2.z;
  result.z = v1.x * v2.y - v2.x * v1.y;
  return result;
}

Vec3 normalize(Vec3 v) {
  double length = sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
  Vec3 result = {v.x/length, v.y/length, v.z/length};
  return result;
}

void printVec3(Vec3 v) {
  printf("(%lf, %lf, %lf)\n", v.x, v.y, v.z);
}

int main() {
  Vec3 v1 = {1.0, 2.0, 3.0};
  Vec3 v2 = {4.0, 5.0, 6.0};

  printf("v1: ");
  printVec3(v1);
  printf("v2: ");
  printVec3(v2);

  double dot_product = dot(v1, v2);
  printf("Dot product: %lf\n", dot_product);

  Vec3 cross_product = cross(v1, v2);
  printf("Cross product: ");
  printVec3(cross_product);

  Vec3 normalized_v1 = normalize(v1);
  printf("Normalized v1: ");
  printVec3(normalized_v1);

  double angle_in_radians = acos(dot_product / (sqrt(pow(v1.x, 2) + pow(v1.y, 2) + pow(v1.z, 2)) * sqrt(pow(v2.x, 2) + pow(v2.y, 2) + pow(v2.z, 2))));
  double angle_in_degrees = angle_in_radians * 180.0 / PI;
  printf("The angle between v1 and v2 is %lf degrees\n", angle_in_degrees);

  return 0;
}