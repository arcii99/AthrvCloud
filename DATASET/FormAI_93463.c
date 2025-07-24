//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
  int prob = rand() % 101; // Generate random probability of alien invasion between 0-100
  char* status; // Variable to store invasion status

  if (prob < 10) { // If probability less than 10%, invasion unlikely
     status = "unlikely";
  } else if (prob >= 10 && prob <= 50) { // If probability between 10-50%, invasion possible
     status = "possible";
  } else if (prob > 50 && prob <= 90) { // If probability between 50-90%, invasion probable
     status = "probable";
  } else { // If probability greater than 90%, invasion imminent
     status = "imminent";
  }

  // Puzzling output style
  printf("The probability of alien invasion is %d%%. ", prob);
  printf("Based on our calculations, it is %s that an invasion will occur.\n", status);
  printf("But beware, our calculations may be off, as we all know that aliens are unpredictable creatures.\n");

  return 0;
}