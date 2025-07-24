//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Cyberpunk
#include <stdio.h>

int main() {
  // Initializing variables
  int money = 10000;
  int hack_chance = 50;
  char username[10];
  char password[10];

  // Getting user credentials
  printf("Enter username: ");
  scanf("%s", username);
  printf("Enter password: ");
  scanf("%s", password);

  // Attempting to hack into system
  if (hack_chance > 30) {
    printf("Successfully hacked into system!\n");
    printf("Accessing bank account...\n");

    // Checking bank account
    if (money > 1000000) {
      printf("You're rich! You have %d credits in your bank account.\n", money);
    } else {
      printf("You're poor! You only have %d credits in your bank account.\n", money);
    }
  } else {
    printf("Failed to hack into system. Better luck next time.\n");
  }

  return 0;
}