//FormAI DATASET v1.0 Category: Date and time ; Style: portable
#include <stdio.h>
#include <time.h>

int main() {
  time_t current_time;
  char* c_time_string;

  /* Obtain current time. */
  current_time = time(NULL);

  if (current_time == ((time_t)-1)) {
    (void) fprintf(stderr, "Failure to obtain the current time.\n");
    return 1;
  }

  /* Convert to local time format. */
  c_time_string = ctime(&current_time);

  if (c_time_string == NULL) {
    (void) fprintf(stderr, "Failure to convert the current time.\n");
    return 1;
  }

  /* Print to stdout. */
  (void) printf("Current time is: %s", c_time_string);

  return 0;
}