//FormAI DATASET v1.0 Category: Date and time ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayTime(void);

int main(void)
{
  printf("\n\n\t\t***CURRENT DATE AND TIME***\n\n");
  displayTime();
  return 0;
}

void displayTime(void)
{
  time_t currentTime;
  char formattedTime[128], formattedDate[128];

  /* Get the current time */
  time(&currentTime);

  /* Format and print the current time */
  strftime(formattedTime, 128, "%I:%M:%S %p", localtime(&currentTime));
  printf("\nCurrent time: %s", formattedTime);

  /* Format and print the current date */
  strftime(formattedDate, 128, "%A, %B %d, %Y", localtime(&currentTime));
  printf("\nCurrent date: %s\n\n", formattedDate);

  return;
}