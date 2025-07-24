//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
  // Welcome message
  printf("Greetings, my dear Watson. Today, we shall investigate the strength of this curious Wi-Fi signal that has been troubling our client.\n");
  
  // Wi-Fi signal strength analyzer
  int signal_strength;
  printf("Please, Watson, tell me the signal strength in dBm that you see on your device: ");
  scanf("%d", &signal_strength);
  
  if (signal_strength >= -50) {
    printf("Excellent signal strength, Watson. This is a strong and stable connection.\n");
  } else if (signal_strength >= -70) {
    printf("Good signal strength, Watson. This connection should be reliable for standard usage.\n");
  } else if (signal_strength >= -80) {
    printf("Fair signal strength, Watson. This connection may experience occasional interruptions or slow speeds.\n");
  } else if (signal_strength >= -90) {
    printf("Poor signal strength, Watson. This connection is likely to drop frequently and experience slow speeds.\n");
  } else {
    printf("Very poor signal strength, Watson. This connection is essentially unusable.\n");
  }
  
  // Farewell message
  printf("Well done, Watson. Our client will surely appreciate our findings. Until next time!\n");
  
  return 0;
}