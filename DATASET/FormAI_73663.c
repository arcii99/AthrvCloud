//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n\n");
  printf("Initializing...\n\n");
  
  // initialize variables
  int signal_strength = rand() % 100 + 1;
  int quality = signal_strength / 10;
  int errors = rand() % 10;
  
  printf("Connected!\n\n");
  printf("Signal strength: %d%%\n", signal_strength);
  
  // generate random error messages
  if (errors > 0) {
    printf("\n");
    
    for (int i = 0; i < errors; i++) {
      int error_type = rand() % 3;
      
      switch (error_type) {
        case 0:
          printf("ERROR: Disconnected from server!\n");
          break;
        case 1:
          printf("ERROR: Lost connection to router!\n");
          break;
        case 2:
          printf("ERROR: Weak signal strength detected!\n");
          break;
      }
    }
    
    printf("\n");
  }
  
  // determine signal quality
  if (quality == 10) {
    printf("Excellent signal quality!\n");
  } else if (quality >= 7) {
    printf("Good signal quality.\n");
  } else if (quality >= 5) {
    printf("Average signal quality.\n");
  } else if (quality >= 3) {
    printf("Poor signal quality.\n");
  } else {
    printf("Very poor signal quality.\n");
  }
  
  return 0;
}