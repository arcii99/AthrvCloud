//FormAI DATASET v1.0 Category: Date and time ; Style: energetic
#include <stdio.h>
#include <time.h>

int main() {
  printf("Let's get energetic with C Date and Time!\n");
  
  // current time
  time_t now = time(NULL);
  printf("The current time is %s", ctime(&now));
  
  // formatted time
  char formatted_time[30];
  struct tm *time_info;
  
  time_info = localtime(&now);
  strftime(formatted_time, 30, "%Y-%m-%d %H:%M:%S", time_info);
  
  printf("The formatted time is %s\n", formatted_time);
  
  // time conversion
  char time_str[30] = "2022-02-22 22:22:22";
  struct tm to_convert;
  
  strptime(time_str, "%Y-%m-%d %H:%M:%S", &to_convert);
  
  time_t converted_time = mktime(&to_convert);
  
  printf("The converted time is %s", ctime(&converted_time));
  
  printf("That's all for now! Stay energized with C Date and Time.\n");
  
  return 0;
}