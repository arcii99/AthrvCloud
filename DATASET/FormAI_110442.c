//FormAI DATASET v1.0 Category: Date and time ; Style: creative
#include <stdio.h>
#include <time.h>

int main() {
  time_t t = time(NULL); // get current time
  struct tm tm = *localtime(&t); // get local time struct

  printf("Today is %d-%02d-%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday); // print date in yyyy-mm-dd format
  printf("The time is %02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec); // print time in hh:mm:ss format

  tm.tm_mday++; // add one day to the date
  mktime(&tm); // update struct tm

  printf("Tomorrow is %d-%02d-%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday); // print tomorrow's date

  return 0;
}