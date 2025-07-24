//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
  int counter;
  float speed;
  clock_t start_t, end_t; // variables to store clock ticks
  double total_t; // variables to store total time

  printf("Welcome to the Internet Speed Test Application!\n");

  // run the test 3 times and output average
  for (counter = 1; counter <= 3; counter++) {
    printf("\nTest #%d:\n", counter);

    // get start time
    start_t = clock();

    // simulate downloading a 100MB file
    for (int i = 0; i < 100000000; i++);

    // get end time
    end_t = clock();

    // calculate total time and convert to seconds
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

    printf("Download speed was %.2f MB/s\n", 100 / total_t);
    speed += 100 / total_t;
  }
  
  printf("\n\nAverage speed: %.2f MB/s\n\n", speed/3);

  return 0;
}