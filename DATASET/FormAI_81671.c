//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: grateful
#include <stdio.h>
#include <time.h>

int main() {
  time_t currentTime;
  struct tm *localTime;
  int year, month, day, hour, minute, second;
  float time_travel;

  // Get current time
  currentTime = time(NULL);
  localTime = localtime(&currentTime);

  // Display current time
  printf("Current Time: %02d/%02d/%04d %02d:%02d:%02d\n",
         localTime->tm_mon + 1, localTime->tm_mday, localTime->tm_year + 1900,
         localTime->tm_hour, localTime->tm_min, localTime->tm_sec);

  // Prompt user to enter time travel amount
  printf("\nHow many years do you want to travel back or forward in time? ");
  scanf("%f", &time_travel);

  // Calculate new time
  year = localTime->tm_year + (int) time_travel;
  month = localTime->tm_mon;
  day = localTime->tm_mday;
  hour = localTime->tm_hour;
  minute = localTime->tm_min;
  second = localTime->tm_sec;

  // Adjust new time if needed
  if (year < 0) {
    year = 0;
    printf("\nSorry, time travel is only possible up to year 1900.\n");
  } else if (year > 120) {
    year = 120;
    printf("\nSorry, time travel is only possible up to year 2120.\n");
  } else {
    year += 1900;
    month -= (int) time_travel * 12;
    if (month < 0) {
      month += 12;
      year--;
    }
    if (month > 11) {
      month -= 12;
      year++;
    }
    day -= (int) time_travel * 365;
    if (day < 1) {
      month--;
      if (month < 0) {
        month += 12;
        year--;
      }
      if (month == 2) {
        day += (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 29 : 28;
      } else if (month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11) {
        day += 31;
      } else {
        day += 30;
      }
    }
    if (day > 31) {
      month++;
      if (month > 11) {
        month -= 12;
        year++;
      }
      if (month == 2) {
        day -= (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 29 : 28;
      } else if (month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11) {
        day -= 31;
      } else {
        day -= 30;
      }
    }
    hour -= (int) time_travel * 8760;
    if (hour < 0) {
      day--;
      if (day < 1) {
        month--;
        if (month < 0) {
          month += 12;
          year--;
        }
        if (month == 2) {
          day += (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 29 : 28;
        } else if (month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11) {
          day += 31;
        } else {
          day += 30;
        }
      }
      hour += 24;
    }
    if (hour > 23) {
      day++;
      if (day > 31) {
        month++;
        if (month > 11) {
          month -= 12;
          year++;
        }
        if (month == 2) {
          day -= (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 29 : 28;
        } else if (month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11) {
          day -= 31;
        } else {
          day -= 30;
        }
      }
      hour -= 24;
    }
    minute -= (int) time_travel * 525600;
    if (minute < 0) {
      hour--;
      if (hour < 0) {
        day--;
        if (day < 1) {
          month--;
          if (month < 0) {
            month += 12;
            year--;
          }
          if (month == 2) {
            day += (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 29 : 28;
          } else if (month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11) {
            day += 31;
          } else {
            day += 30;
          }
        }
        hour += 24;
      }
      minute += 60;
    }
    if (minute > 59) {
      hour++;
      if (hour > 23) {
        day++;
        if (day > 31) {
          month++;
          if (month > 11) {
            month -= 12;
            year++;
          }
          if (month == 2) {
            day -= (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 29 : 28;
          } else if (month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11) {
            day -= 31;
          } else {
            day -= 30;
          }
        }
        hour -= 24;
      }
      minute -= 60;
    }
    second -= (int) time_travel * 31536000;
    if (second < 0) {
      minute--;
      if (minute < 0) {
        hour--;
        if (hour < 0) {
          day--;
          if (day < 1) {
            month--;
            if (month < 0) {
              month += 12;
              year--;
            }
            if (month == 2) {
              day += (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 29 : 28;
            } else if (month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11) {
              day += 31;
            } else {
              day += 30;
            }
          }
          hour += 24;
        }
        minute += 60;
      }
      second += 60;
    }
    if (second > 59) {
      minute++;
      if (minute > 59) {
        hour++;
        if (hour > 23) {
          day++;
          if (day > 31) {
            month++;
            if (month > 11) {
              month -= 12;
              year++;
            }
            if (month == 2) {
              day -= (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 29 : 28;
            } else if (month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11) {
              day -= 31;
            } else {
              day -= 30;
            }
          }
          hour -= 24;
        }
        minute -= 60;
      }
      second -= 60;
    }
  }

  // Display new time
  printf("\nNew Time:     %02d/%02d/%04d %02d:%02d:%02d\n",
         month + 1, day, year, hour, minute, second);

  return 0;
}