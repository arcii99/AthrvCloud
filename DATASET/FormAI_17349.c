//FormAI DATASET v1.0 Category: Educational ; Style: Cyberpunk
#include<stdio.h>

int main() {

  printf("Welcome to the Cyberpunk C Programming Tutorial\n");
  printf("We will teach you how to hack with C\n");

  int accessLevel = 0;

  printf("\nEnter your access level (1-3): ");
  scanf("%d", &accessLevel);

  if(accessLevel >= 1 && accessLevel <= 3) {

    printf("\nAccess granted!\n");

    if(accessLevel == 3) {
      printf("\nYou are a level 3 hacker. Welcome to the club!\n");
    }

    int password = 0;

    printf("\nEnter the code to unlock the mainframe: ");
    scanf("%d", &password);

    if(password == 6654) {

      printf("\nAccessing mainframe...\n");
      printf("Downloading data...\n");
      printf("Encryption level: high\n");
      printf("Access logs erased.\n");

    } else {

      printf("\nAccess denied!\n");
      printf("Disconnecting...\n");

    }

  } else {

    printf("\nAccess denied!\n");
    printf("Disconnecting...\n");

  }

  return 0;
}