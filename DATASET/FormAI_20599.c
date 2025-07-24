//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  // Initialize random number generator
  srand(time(NULL));

  int alert_level = 0; // Set initial alert level to 0

  // Generate random network traffic
  int traffic = rand() % 100;

  // Determine if traffic level triggers an alert
  if (traffic < 30) {
    alert_level = 1;
  } else if (traffic < 70) {
    alert_level = 2;
  } else {
    alert_level = 3;
  }

  // Implement simple intrusion detection system logic
  switch(alert_level) {
    case 1:
      printf("No threats detected. Snack time!\n");
      break;
    case 2:
      printf("Possible intrusion detected. Time to wake up!\n");
      break;
    case 3:
      printf("Intrusion detected! Call the IT department! Panic! Panic!\n");
      break;
    default:
      printf("Error! Invalid alert level!\n");
      break;
  }

  return 0;
}