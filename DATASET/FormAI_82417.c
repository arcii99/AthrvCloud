//FormAI DATASET v1.0 Category: Date and time ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_time(struct tm* timeinfo) {
  char buffer[80];

  strftime(buffer, 80, "%I:%M:%S %p", timeinfo); // Formatting time
  printf("Time: %s\n", buffer); // Printing time
}

void print_date(struct tm* timeinfo) {
  char buffer[80];

  strftime(buffer, 80, "%A, %B %d, %Y", timeinfo); // Formatting date
  printf("Date: %s\n", buffer); // Printing date
}

int main() {
  time_t rawtime;
  struct tm *timeinfo;

  time(&rawtime); // Getting current time
  timeinfo = localtime(&rawtime); // Converting to local time

  printf("===================================\n");
  printf("   Welcome to my Date and Time App  \n");
  printf("===================================\n\n");

  printf("Today is "); // Printing the day of the week
  print_date(timeinfo);

  print_time(timeinfo); // Printing the current time

  return 0; // Exiting the program
}