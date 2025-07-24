//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: all-encompassing
#include <stdio.h>

int main() {
  int time, greenTime, yellowTime, redTime;
  char color[10];

  // Set initial values
  greenTime = 20;
  yellowTime = 5;
  redTime = 15;
  time = greenTime;

  while (1) {
    // Output current color
    if (time == greenTime) {
      printf("Green light\n");
      strcpy(color, "green");
    }
    else if (time == yellowTime) {
      printf("Yellow light\n");
      strcpy(color, "yellow");
    }
    else if (time == redTime) {
      printf("Red light\n");
      strcpy(color, "red");
    }

    // Update time
    time--;
    if (time < 0) {
      if (strcmp(color, "green") == 0) {
        time = yellowTime;
      }
      else if (strcmp(color, "yellow") == 0) {
        time = redTime;
      }
      else if (strcmp(color, "red") == 0) {
        time = greenTime;
      }
    }

    // Wait one second
    sleep(1);
  }
  
  return 0;
}