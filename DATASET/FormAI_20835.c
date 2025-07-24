//FormAI DATASET v1.0 Category: Network Ping Test ; Style: happy
#include <stdio.h>

int main() {
  printf("\n\nHey there! I'm your program for network ping testing! Let's bring some joy to the world with this lovely ping test!\n\n");

  char ip_address[16];

  printf("Please enter an IP address to test: ");
  scanf("%s", ip_address);

  printf("\n\nAwesome! Let's get started with testing the ping for %s!\n\n", ip_address);

  int status = system("ping -c 5 -q %s", ip_address);

  if (status == 0) {
    printf("\n\nYay! The ping test for %s was successful! It's a happy day!\n\n", ip_address);
  } else {
    printf("\n\nOh no! The ping test for %s failed! Let's keep smiling and try again :)\n\n", ip_address);
  }

  return 0;
}