//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  printf("Welcome to the Subnet Calculator!\n");

  int choice = 0;
  printf("Enter a number between 1 and 10 to determine the level of subnetting:\n");
  scanf("%d", &choice);

  if (choice > 10) {
    printf("Sorry, your choice must be between 1 and 10. Try again later.\n");
  } else {
    printf("Calculating subnets...\n");

    srand(time(NULL));
    int subnet = 256 / choice;

    for (int i = 1; i <= choice; i++) {
      int network = i * subnet;
      printf("Subnet #%d: 192.168.1.%d\n", i, network);

      int host1 = rand() % subnet + network;
      int host2 = rand() % subnet + network;
      int host3 = rand() % subnet + network;
      int host4 = rand() % subnet + network;

      printf("Hosts within this subnet:\n");
      printf("192.168.1.%d\n", host1);
      printf("192.168.1.%d\n", host2);
      printf("192.168.1.%d\n", host3);
      printf("192.168.1.%d\n\n", host4);
    }
  }

  printf("Thank you for using the Subnet Calculator. Goodbye!\n");

  return 0;
}