//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

int main() {
  time_t current_time;
  int response_code;
  int count = 0;
  bool is_up = false;
  while (true) {
    system("clear"); // Clear the console for better visibility
    printf("Checking website uptime...\n");
    current_time = time(NULL);
    printf("Current time: %s\n", ctime(&current_time));
    response_code = system("curl -Is https://www.example.com | head -n 1 | cut -d ' ' -f 2");
    if (response_code == 200) {
      if (!is_up) {
        printf("Website is now up!\n");
        is_up = true;
        count = 0;
      }
      else {
        printf("Website is still up!\n");
      }
    }
    else {
      printf("Oops! Website is down!\n");
      count++;
    }
    printf("Number of consecutive failed checks: %d\n", count);
    sleep(60); // Wait for 60 seconds before checking again
  }
  return 0;
}