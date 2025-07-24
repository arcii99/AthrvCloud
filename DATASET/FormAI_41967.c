//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
  int time_quantum = 30;
  int curr_time = 0;
  char curr_signal = 'G';

  while (1) {
    // Check if time quantum has passed
    if (curr_time == time_quantum) {
      // Swap signals
      if (curr_signal == 'G') {
        curr_signal = 'Y';
        curr_time = 0;
      } else if (curr_signal == 'Y') {
        curr_signal = 'R';
        curr_time = 0;
      } else if (curr_signal == 'R') {
        curr_signal = 'G';
        curr_time = 0;
      }
    }

    // Print current signal
    printf("%c\n", curr_signal);

    // Increment current time
    curr_time++;

    // Delay for 1 second
    sleep(1);
  }

  return 0;
}