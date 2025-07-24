//FormAI DATASET v1.0 Category: Searching algorithm ; Style: happy
#include <stdio.h>

// This is a happy searching algorithm that looks for sunshine in our array of weather

int main() {
  int weather[7] = {70, 72, 69, 75, 72, 80, 82}; // array of the temperature in Fahrenheit for 7 days
  int i;
  int sunshine = 0; // assuming no sunshine initially
  
  printf("Let's find sunshine in our array of weather!\n\n");
  
  // Loop through the array and look for sunshine (temperature over 80F)
  for(i=0;i<7;i++) {
    if(weather[i] > 80) {
      sunshine = 1; // found sunshine!
      printf("We found sunshine on day %d with a temperature of %dF\n", i+1, weather[i]);
      break; // exit loop if sunshine is found
    }
  }

  if(sunshine == 0) { // if no sunshine is found
    printf("Unfortunately, we couldn't find any sunshine in our array of weather :(\n");
  }

  return 0;
}