//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define NUM_THREADS 4

// function to calculate area of a square
double area_of_square(double side) {
  return side * side;
}

// function to calculate area of a circle
double area_of_circle(double radius) {
  return M_PI * radius * radius;
}

// function to calculate perimeter of a rectangle
double perimeter_of_rectangle(double length, double breadth) {
  return 2 * (length + breadth);
}

// function to calculate perimeter of a triangle
double perimeter_of_triangle(double a, double b, double c) {
  return a + b + c;
}

// function to execute by each thread
void *thread_function(void *arg) {
  double arg1 = *(double *)arg; // get argument passed to the thread
  double result;

  // switch statements to determine which function to call
  switch((int)arg1) {
    case 0:
      result = area_of_square(5.0);
      printf("Area of square with side 5.0 is %lf\n", result);
      break;
    case 1:
      result = area_of_circle(6.0);
      printf("Area of circle with radius 6.0 is %lf\n", result);
      break;
    case 2:
      result = perimeter_of_rectangle(3.0, 4.0);
      printf("Perimeter of rectangle with length 3.0 and breadth 4.0 is %lf\n", result);
      break;
    case 3:
      result = perimeter_of_triangle(3.0, 4.0, 5.0);
      printf("Perimeter of triangle with sides 3.0, 4.0, and 5.0 is %lf\n", result);
      break;
    default:
      printf("Invalid argument passed\n");
      break;
  }
  pthread_exit(NULL); // exit thread
}

int main() {
  pthread_t threads[NUM_THREADS]; // create array of threads
  int rc, t;
  double args[NUM_THREADS] = {0, 1, 2, 3}; // arguments to be passed to each thread

  // create threads
  for(t=0; t<NUM_THREADS; t++) {
    rc = pthread_create(&threads[t], NULL, thread_function, (void *)&args[t]);
    if (rc) {
      printf("Error: return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }

  // join threads
  for(t=0; t<NUM_THREADS; t++) {
    rc = pthread_join(threads[t], NULL);
    if (rc) {
      printf("Error: return code from pthread_join() is %d\n", rc);
      exit(-1);
    }
  }

  pthread_exit(NULL); // exit main thread
  return 0;
}