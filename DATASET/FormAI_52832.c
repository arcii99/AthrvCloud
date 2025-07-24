//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: innovative
#include <stdio.h>

int main() {
  int n;

  printf("Enter the number of points: ");
  scanf("%d", &n);

  int x[n], y[n];

  for (int i = 0; i < n; i++) {
    printf("Enter coordinates of point %d (x, y):\n", i+1);
    scanf("%d %d", &x[i], &y[i]);
  }

  int max_dist = 0, p1 = 0, p2 = 1;

  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      int dist = (x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]);

      if (dist > max_dist) {
        max_dist = dist;
        p1 = i;
        p2 = j;
      }
    }
  }

  printf("The farthest points are (%d, %d) and (%d, %d)\n", x[p1], y[p1], x[p2], y[p2]);
  printf("The distance between them is %d\n", max_dist);

  return 0;
}