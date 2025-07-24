//FormAI DATASET v1.0 Category: Digital signal processing ; Style: surrealist
#include <stdio.h>

int main() {
  int surreal = 50;

  printf("Welcome to the surreal world of DSP!\n");

  while (surreal > 0) {
    printf("You are now entering a parallel universe...\n");
    printf("Please input a number to manipulate:");
    scanf("%d", &surreal);

    surreal = surreal * surreal + 1;

    printf("Your number has now been manipulated by the Surrealist DSP algorithm.\n");
    printf("Congratulations, your number is now: %d\n", surreal);

    printf("Would you like to continue exploring the surreal world of DSP?");
    printf("Please enter 'yes' to continue, or 'no' to exit: ");
    char ans[3];
    scanf("%s", ans);

    if (strncmp(ans, "yes", 3) == 0) {
      continue;
    }
    else if (strncmp(ans, "no", 2) == 0) {
      printf("Thank you for exploring the surreal world of DSP!\n");
      break;
    }
    else {
      printf("I'm sorry, I didn't understand your response. Please try again.\n");
      continue;
    }
  }

  return 0;
}