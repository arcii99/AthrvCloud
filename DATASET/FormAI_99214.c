//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JAN 1
#define FEB 2
#define MAR 3
#define APR 4
#define MAY 5
#define JUN 6
#define JUL 7
#define AUG 8
#define SEP 9
#define OCT 10
#define NOV 11
#define DEC 12

void print_error() {
  printf("Invalid date input.\n");
}

int is_leap_year(int year) {
  if (year % 4 == 0) {
    if (year % 100 == 0) {
      if (year % 400 == 0) {
        return 1;
      } else {
        return 0;
      }
    } else {
      return 1;
    }
  } else {
    return 0;
  }
}

int convert_month_to_number(char* month) {
  if (strcmp(month, "january") == 0 || strcmp(month, "jan") == 0) {
    return JAN;
  } else if (strcmp(month, "february") == 0 || strcmp(month, "feb") == 0) {
    return FEB;
  } else if (strcmp(month, "march") == 0 || strcmp(month, "mar") == 0) {
    return MAR;
  } else if (strcmp(month, "april") == 0 || strcmp(month, "apr") == 0) {
    return APR;
  } else if (strcmp(month, "may") == 0) {
    return MAY;
  } else if (strcmp(month, "june") == 0 || strcmp(month, "jun") == 0) {
    return JUN;
  } else if (strcmp(month, "july") == 0 || strcmp(month, "jul") == 0) {
    return JUL;
  } else if (strcmp(month, "august") == 0 || strcmp(month, "aug") == 0) {
    return AUG;
  } else if (strcmp(month, "september") == 0 || strcmp(month, "sep") == 0) {
    return SEP;
  } else if (strcmp(month, "october") == 0 || strcmp(month, "oct") == 0) {
    return OCT;
  } else if (strcmp(month, "november") == 0 || strcmp(month, "nov") == 0) {
    return NOV;
  } else if (strcmp(month, "december") == 0 || strcmp(month, "dec") == 0) {
    return DEC;
  } else {
    return -1;
  }
}

void convert_date(char* date_string) {
  char month_string[16];
  int month_number, day, year, hours, minutes, seconds;

  if (sscanf(date_string, "%d %s %d %d:%d:%d", &day, month_string, &year, &hours, &minutes, &seconds) != 6) {
    print_error();
    return;
  }

  month_number = convert_month_to_number(month_string);
  if (month_number == -1) {
    print_error();
    return;
  }

  if (day < 1 || day > 31 ||
      month_number == FEB && (day < 1 || day > 29 || !is_leap_year(year)) ||
      (month_number == APR || month_number == JUN || month_number == SEP || month_number == NOV) && (day < 1 || day > 30) ||
      year < 0 ||
      hours < 0 || hours > 23 ||
      minutes < 0 || minutes > 59 ||
      seconds < 0 || seconds > 59) {
    print_error();
    return;
  }

  printf("Date: %02d/%02d/%d\n", day, month_number, year);
  printf("Time: %02d:%02d:%02d\n", hours, minutes, seconds);
}

int main() {
  char date_string[32];

  printf("Please enter a date and time in the following format: d MMM yyyy hh:mm:ss\n");
  printf("Example: 15 Apr 2022 13:30:00\n");
  scanf("%[^\n]%*c", date_string);

  convert_date(date_string);

  return 0;
}