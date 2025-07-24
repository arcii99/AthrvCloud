//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: surprised
#include <stdio.h>

int main() {
  printf("Welcome to the Internet Speed Test Application!\n");
  printf("Please wait while we test your internet speed...\n");

  // We will simulate the internet speed test by generating a random number between 1 and 100 Mbps
  int speed = rand() % 100 + 1;
  printf("Your internet speed is %d Mbps!\n", speed);

  if (speed < 10) {
    printf("Wow, your internet speed is really slow!\n");
  } else if (speed < 50) {
    printf("Your internet speed is decent!\n");
  } else {
    printf("Wow, your internet speed is really fast!\n");
  }

  printf("Do you want to test again? (y/n)\n");
  char response = getchar();
  
  if (response == 'y') {
    main(); // Recursive call to main function to run the application again
  } else {
    printf("Thank you for using our Internet Speed Test Application. Goodbye!\n");
  }

  return 0;
}