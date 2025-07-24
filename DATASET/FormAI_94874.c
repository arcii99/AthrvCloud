//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a secure password
void generate_password(int length) {
  char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%&";
  int characters_length = sizeof(characters) - 1;
  char password[length];
  srand((unsigned int)time(NULL));
  
  // Generate random password
  for (int i = 0; i < length; i++) {
    password[i] = characters[rand() % characters_length];
  }
  
  // Print generated password
  printf("Your secure password is: %s\n", password);
}

int main() {
  int length;
  
  printf("Welcome to the Cyberpunk Secure Password Generator!\n");
  printf("How long would you like your password to be?\n");
  
  // Get password length from user
  scanf("%d", &length);
  
  // Generate and print secure password
  generate_password(length);
  
  return 0;
}