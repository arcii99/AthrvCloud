//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: multi-threaded
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define NUM_THREADS 4

typedef struct {
  double x;
  double y;
} Point;

typedef struct {
  Point a;
  Point b;
  Point c;
} Triangle;

void *calculate_perimeter(void *input_triangle) {
  Triangle *triangle = (Triangle *) input_triangle;
  double side_one = sqrt(pow((triangle->a.x - triangle->b.x), 2) + pow((triangle->a.y - triangle->b.y), 2));
  double side_two = sqrt(pow((triangle->a.x - triangle->c.x), 2) + pow((triangle->a.y - triangle->c.y), 2));
  double side_three = sqrt(pow((triangle->b.x - triangle->c.x), 2) + pow((triangle->b.y - triangle->c.y), 2));
  double perimeter = side_one + side_two + side_three;
  printf("Thread %ld: Perimeter of the triangle is %.2f\n", pthread_self(), perimeter);
  pthread_exit(NULL);
}

int main() {
  Triangle t1, t2, t3, t4;
  t1.a.x = 0.0;
  t1.a.y = 0.0;
  t1.b.x = 4.0;
  t1.b.y = 0.0;
  t1.c.x = 0.0;
  t1.c.y = 3.0;

  t2.a.x = 0.0;
  t2.a.y = 0.0;
  t2.b.x = 5.0;
  t2.b.y = -1.0;
  t2.c.x = -2.0;
  t2.c.y = -3.0;

  t3.a.x = 1.0;
  t3.a.y = 2.0;
  t3.b.x = 3.0;
  t3.b.y = 5.0;
  t3.c.x = 7.0;
  t3.c.y = 2.0;

  t4.a.x = 2.0;
  t4.a.y = 1.0;
  t4.b.x = -3.0;
  t4.b.y = 2.0;
  t4.c.x = 1.0;
  t4.c.y = -4.0;

  pthread_t threads[NUM_THREADS];
  int rc;

  /* Calculate perimeter of each triangle using multi-threading */
  rc = pthread_create(&threads[0], NULL, calculate_perimeter, (void *) &t1);
  rc = pthread_create(&threads[1], NULL, calculate_perimeter, (void *) &t2);
  rc = pthread_create(&threads[2], NULL, calculate_perimeter, (void *) &t3);
  rc = pthread_create(&threads[3], NULL, calculate_perimeter, (void *) &t4);

  /* Wait for all threads to finish */
  for (int i = 0; i < NUM_THREADS; i++) {
    rc = pthread_join(threads[i], NULL);
  }

  pthread_exit(NULL);
}