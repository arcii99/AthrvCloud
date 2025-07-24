//FormAI DATASET v1.0 Category: System event logger ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char* event) {
  time_t current_time;
  char* c_time_string;

  /* Obtain current time as seconds elapsed since the Epoch. */
  current_time = time(NULL);

  if (current_time == ((time_t)-1)) {
    (void) fprintf(stderr, "Failure to obtain the current time.\n");
    exit(EXIT_FAILURE);
  }

  /* Convert to local time format. */
  c_time_string = ctime(&current_time);

  if (c_time_string == NULL) {
    (void) fprintf(stderr, "Failure to convert the current time.\n");
    exit(EXIT_FAILURE);
  }

  /* Remove the newline character from the string. */
  c_time_string[strlen(c_time_string)-1] = '\0';

  /* Log the event with the timestamp. */
  printf("%s: %s\n", c_time_string, event);
}

int main(void) {
  printf("Type 'exit' to quit.\n");

  while(1) {
    char input[50];
    printf("Enter an event: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if (strcmp(input, "exit") == 0) {
      break;
    }

    logEvent(input);
  }

  return 0;
}