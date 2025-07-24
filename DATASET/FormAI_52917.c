//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multivariable
#include <stdio.h>
#include <string.h>

int main()
{
  // declare variables
  char input_date[11], output_date[11];
  int day, month, year;
  char month_name[12][4] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                             "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
  
  // ask user for input date
  printf("Enter date in format DD/MM/YYYY: ");
  scanf("%s", input_date);
  
  // convert input string into separate day, month, year integers
  sscanf(input_date, "%d/%d/%d", &day, &month, &year);
  
  // calculate number of days in each month
  int num_days[12] = { 31, 28, 31, 30, 31, 30,
                       31, 31, 30, 31, 30, 31 };
  
  // check if leap year and adjust number of days in February
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
    num_days[1] = 29;
  }
  
  // check if input date is valid
  if (day < 1 || day > num_days[month-1] || month < 1 || month > 12) {
    printf("Invalid date input.\n");
    return 1;
  }
  
  // convert month number to month name
  char month_buffer[4];
  strncpy(month_buffer, month_name[month-1], 4);
  
  // format output date string
  sprintf(output_date, "%d %s %d", day, month_buffer, year);
  
  // display output date
  printf("Output date: %s\n", output_date);
  
  return 0;
}