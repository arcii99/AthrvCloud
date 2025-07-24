//FormAI DATASET v1.0 Category: Benchmarking ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

// function to calculate difference between two timevals in milliseconds 
double getTimeDiff(struct timeval t1, struct timeval t2) {
  return (double)(t2.tv_sec - t1.tv_sec) * 1000 + (double)(t2.tv_usec - t1.tv_usec) / 1000;
}


// asynchronous function that increments a value after a certain delay
void asyncIncrement(int* value, int incrementValue, int delay) {
  // delay execution for specified time in milliseconds
  struct timespec sleepTime = {0, delay * 1000000};
  nanosleep(&sleepTime, NULL);
  *value += incrementValue;
}


// benchmark function to test asynchronous performance
void benchmarkAsync() {
  int iterations = 100000;
  int asyncValue = 0;
  
  // start timer
  struct timeval start, end;
  gettimeofday(&start, NULL);
  
  // loop through asyncIncrement function asynchronously
  for (int i = 0; i < iterations; i++) {
    asyncIncrement(&asyncValue, 1, 1);
  }
  
  // stop timer
  gettimeofday(&end, NULL);
  
  // calculate time taken and print result
  double timeTaken = getTimeDiff(start, end);
  printf("Async benchmark completed in %0.3f ms\n", timeTaken);
}


// synchronous function that increments a value
void syncIncrement(int* value, int incrementValue) {
  *value += incrementValue;
}


// benchmark function to test synchronous performance
void benchmarkSync() {
  int iterations = 100000;
  int syncValue = 0;
  
  // start timer
  struct timeval start, end;
  gettimeofday(&start, NULL);
  
  // loop through syncIncrement function synchronously
  for (int i = 0; i < iterations; i++) {
    syncIncrement(&syncValue, 1);
  }
  
  // stop timer
  gettimeofday(&end, NULL);
  
  // calculate time taken and print result
  double timeTaken = getTimeDiff(start, end);
  printf("Sync benchmark completed in %0.3f ms\n", timeTaken);
}


int main() {
  // run both benchmarks and compare results
  benchmarkSync();
  benchmarkAsync();
  
  return 0;
}