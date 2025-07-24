//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 20
#define MIN_LENGTH 8

void generatePassword(int length);

int main() {
  int passwordLength;
  printf("Welcome to the Secure Password Generator!\n");
  printf("Please enter the desired password length (between %d-%d): ", MIN_LENGTH, MAX_LENGTH);
  scanf("%d", &passwordLength);

  while (passwordLength < MIN_LENGTH || passwordLength > MAX_LENGTH) {
    printf("Invalid length. Please enter a length between %d-%d: ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &passwordLength);
  }

  printf("Generating password...\n");
  generatePassword(passwordLength);
  printf("Password successfully generated. Thank you for using the Secure Password Generator!\n");
  
  return 0;
}

void generatePassword(int length) {
  char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890!@#$%^&*()_+-=";
  int numChars = strlen(chars);
  char password[MAX_LENGTH];
  srand(time(NULL)); // Initialize random seed

  for (int i = 0; i < length; i++) {
    password[i] = chars[rand() % numChars];
  }
  password[length] = '\0'; // Add null terminator to end of string

  printf("Your new password is: %s\n", password);
}