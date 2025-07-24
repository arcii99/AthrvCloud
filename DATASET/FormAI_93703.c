//FormAI DATASET v1.0 Category: Date and time ; Style: inquisitive
#include <stdio.h>
#include <time.h>
#include <string.h>

int main() {
  time_t current_time;
  struct tm * time_info;
  char time_char[50];
  char input_str[50];
  struct tm input_time;
  double diff;

  // Get current time
  time(&current_time);
  time_info = localtime(&current_time);

  // Convert time to string and print
  strftime(time_char, 50, "Current time: %Y-%m-%d %H:%M:%S %Z", time_info);
  printf("%s\n", time_char);

  // Get user input
  printf("Enter a date and time to compare with current time (YYYY-MM-DD HH:MM:SS): ");
  fgets(input_str, 50, stdin);
  sscanf(input_str, "%d-%d-%d %d:%d:%d", &input_time.tm_year, &input_time.tm_mon, &input_time.tm_mday, &input_time.tm_hour, &input_time.tm_min, &input_time.tm_sec);

  // Adjust user input to match struct tm
  input_time.tm_year -= 1900;
  input_time.tm_mon -= 1;

  // Convert user input time to seconds and compare with current time
  diff = difftime(mktime(&input_time), current_time);
  if (diff > 0) {
    printf("Input time is in the future by %.f seconds\n", diff);
  } else if (diff < 0) {
    printf("Input time is in the past by %.f seconds\n", -diff);
  } else {
    printf("Input time is the same as current time\n");
  }

  return 0;
}