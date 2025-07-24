//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Dennis Ritchie
#include <stdio.h>   //include standard input/output library
#include <sys/time.h> //include time library
#include <unistd.h>  //include UNIX standard library

int main() {
  struct timeval start, end; //initialize start and end times
  long int used; //initialize long integer used

  gettimeofday(&start, NULL); //get start time

  //perform CPU intensive task
  int a = 0;
  for (int i = 0; i < 1000000000; i++) {
    a += i;
  }

  gettimeofday(&end, NULL); //get end time

  //calculate CPU usage percentage
  used = ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec));
  float cpu_usage = ((float)used / 1000000) * 100;

  //print CPU usage percentage
  printf("CPU Usage: %.2f%%\n", cpu_usage);

  return 0; //exit program
}