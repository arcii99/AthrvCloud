//FormAI DATASET v1.0 Category: Date and time ; Style: thoughtful
#include <stdio.h>
#include <time.h>

int main() {
  time_t rawtime; //Creating a variable to store the current time
  struct tm * timeinfo; //Creating a pointer to a time structure

  time ( &rawtime ); //Getting the current time
  timeinfo = localtime ( &rawtime ); //Converting the current time to local time

  printf ( "Current local time and date: %s", asctime(timeinfo) ); //Printing the current time and date

  //Creating a new date and time structure
  struct tm newtime;
  newtime.tm_year = 2021;
  newtime.tm_mon = 9;
  newtime.tm_mday = 24;
  newtime.tm_hour = 13;
  newtime.tm_min = 45;
  newtime.tm_sec = 0;

  //Converting the new date and time to a time_t variable
  time_t newrawtime = mktime(&newtime);

  printf("New date and time: %s", asctime(localtime(&newrawtime))); //Printing the new date and time in local time

  return 0;
}