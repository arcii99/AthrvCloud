//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.141592653589793

double randNum()
{
  return (double) rand() / (double) RAND_MAX;
}

double findArea(int numSims)
{
  double x, y, dist, area = 0;
  double r = 1.0;
  
  int numInCircle = 0, i;

  for (i = 0; i < numSims; i++) {
    x = randNum();
    y = randNum();

    dist = sqrt(pow(x, 2.0) + pow(y, 2.0));
    if (dist <= r) {
      numInCircle++;
    }
  }

  area = (numInCircle / (double) numSims) * pow(r, 2.0);

  return area;
}

int main()
{
  int numSims = 100000;
  double area;
  
  srand(time(NULL));

  area = findArea(numSims);

  printf("The area of the circle is approximately %lf\n", area * PI);

  return 0;
}