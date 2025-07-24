//FormAI DATASET v1.0 Category: Date and time ; Style: single-threaded
#include <stdio.h>
#include <time.h>

int main() {
  time_t rawtime;
  struct tm * timeinfo;
  int i;

  time(&rawtime);
  timeinfo = localtime(&rawtime);

  printf("Current date and time: %s", asctime(timeinfo));

  //custom date and time
  timeinfo->tm_year = 121;   // year starting from 1900 
  timeinfo->tm_mon = 6;      // 0-11
  timeinfo->tm_mday = 23;    //1-31
  timeinfo->tm_hour = 14;    //0-23
  timeinfo->tm_min = 45;     //0-59
  timeinfo->tm_sec = 30;     //0-60

  //convert custom date and time into time_t format
  time_t t = mktime(timeinfo);

  //adjust timezone
  timeinfo = localtime(&t);

  printf("Custom date and time: %s", asctime(timeinfo));

  //example for printing current date and time repeatedly for 10 times with 1 second delay
  for (i=0; i<10; i++) {
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf("Current date and time: %s", asctime(timeinfo));
    sleep(1);
  }

  return 0;
}