//FormAI DATASET v1.0 Category: Date and time ; Style: synchronous
#include <stdio.h>
#include <time.h>

int main() {
  time_t rawtime;
  struct tm * timeinfo;

  time(&rawtime);
  timeinfo = localtime(&rawtime);
  char* monthNames[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

  printf("The current date and time is: %s", asctime(timeinfo)); // print current date and time

  printf("\nToday's date is: ");
  printf("%02d %s %d\n", timeinfo->tm_mday, monthNames[timeinfo->tm_mon], 1900 + timeinfo->tm_year); // print today's date in dd Month YYYY format

  printf("\nCurrent time is: ");
  printf("%02d:%02d:%02d\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec); // print current time in HH:MM:SS format

  printf("\nYou can also represent the date and time in your preferred format.\n");
  printf("For example, let's represent the date and time in DD/MM/YYYY HH:MM:SS format.\n");

  char formattedDate[20];
  char formattedTime[20];

  sprintf(formattedDate, "%02d/%02d/%d", timeinfo->tm_mday, timeinfo->tm_mon + 1, 1900 + timeinfo->tm_year); // format date in DD/MM/YYYY
  sprintf(formattedTime, "%02d:%02d:%02d", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec); // format time in HH:MM:SS

  printf("Formatted date and time: %s %s\n", formattedDate, formattedTime); // print formatted date and time

  return 0;
}