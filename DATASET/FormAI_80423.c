//FormAI DATASET v1.0 Category: Data validation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char name[20], email[40], password[20], confirm_password[20], phone_number[20];
  
  // Input name
  printf("Hello! Welcome to our happy data validation program!\n");
  printf("Please enter your name: ");
  fgets(name, 20, stdin);
  name[strcspn(name, "\n")] = '\0'; // Remove newline character
  
  // Input email
  printf("Great, %s! Please enter your email: ", name);
  fgets(email, 40, stdin);
  email[strcspn(email, "\n")] = '\0'; // Remove newline character
  
  // Validate email
  int email_length = strlen(email);
  int at_sign_index = -1, period_index = -1;
  for (int i = 0; i < email_length; i++) {
    if (email[i] == '@') {
      at_sign_index = i;
    } else if (email[i] == '.') {
      period_index = i;
    }
  }
  if (at_sign_index < 1 || period_index < at_sign_index + 2 || period_index == email_length - 1) {
    printf("Oops, something went wrong! Please enter a valid email.\n");
    printf("Don't worry, %s, we won't give up until we get it right!\n", name);
    return 1; // Error code
  }
  
  // Input password
  printf("Excellent, %s! Please enter a password: ", name);
  fgets(password, 20, stdin);
  password[strcspn(password, "\n")] = '\0'; // Remove newline character
  
  // Input confirm password
  printf("Good job, %s! Please confirm your password: ", name);
  fgets(confirm_password, 20, stdin);
  confirm_password[strcspn(confirm_password, "\n")] = '\0'; // Remove newline character
  
  // Verify password match
  if (strcmp(password, confirm_password) != 0) {
    printf("Sorry, %s, but your passwords do not match!\n", name);
    printf("But we are not giving up, are we? Please try again!\n");
    return 1; // Error code
  }
  
  // Input phone number
  printf("Almost there, %s! Please enter your phone number: ", name);
  fgets(phone_number, 20, stdin);
  phone_number[strcspn(phone_number, "\n")] = '\0'; // Remove newline character
  
  // Validate phone number
  int phone_length = strlen(phone_number);
  for (int i = 0; i < phone_length; i++) {
    if (phone_number[i] < '0' || phone_number[i] > '9') {
      printf("Sorry, %s, but your phone number is not valid!\n", name);
      printf("Don't worry, cheer up, and give it another shot!\n");
      return 1; // Error code
    }
  }
  
  // Success!
  printf("Congratulations, %s! You have successfully completed our happy data validation program!\n", name);
  printf("Your email is %s, your password is %s, and your phone number is %s.\n", email, password, phone_number);
  printf("We are very happy to have you join our program, %s! Have a great day!\n", name);
  
  return 0; // Success code
}