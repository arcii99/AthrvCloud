//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: thoughtful
#include <stdio.h>
#include <string.h>

char *months[] = {"January", "February", "March", "April", 
"May", "June", "July", "August", "September", 
"October", "November", "December"}; 

int main(void) {
  char dateString[50];
  const char delim[2] = "/";
  char *token;
  int day, year, month;
  
  printf("Enter a date in the format: mm/dd/yyyy\n");
  fgets(dateString, 50, stdin);
  
  /* get the month */
  token = strtok(dateString, delim);
  month = atoi(token);
  
  /* get the day */
  token = strtok(NULL, delim);
  day = atoi(token);
  
  /* get the year */
  token = strtok(NULL, delim);
  year = atoi(token);
  
  printf("You entered the date: %d/%d/%d\n", month, day, year);
  
  /* convert to natural language date */
  printf("The natural language date is: %s %d, %d\n", 
  months[month-1], day, year);
  
  return 0;
}