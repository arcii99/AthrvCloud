//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int signal_strength = 0;
  srand(time(NULL));
  signal_strength = rand() % 101;

  printf("Thou hast found a Wi-Fi signal strength of %d percent!\n", signal_strength);

  if (signal_strength >= 80) {
    printf("The Wi-Fi signal is strong, and would serve thee well for streaming videos!\n");
  } else if (signal_strength >= 50 && signal_strength < 80) {
    printf("The Wi-Fi signal is fair, but may not work well for streaming or downloading large files.\n");
  } else if (signal_strength >= 30 && signal_strength < 50) {
    printf("The Wi-Fi signal is poor, and may work slowly or not at all. Try moving closer to the router.\n");
  } else {
    printf("Alas, the Wi-Fi signal is very weak or nonexistent. Seek ye better options elsewhere.\n");
  }

  return 0;
}