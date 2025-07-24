//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
  char username[20];
  char password[20];
  
  printf("Enter your username: ");
  scanf("%s", username);

  printf("Enter your password: ");
  scanf("%s", password);

  // sanitize username input
  for(int i = 0; username[i]; i++){
    if(!isalpha(username[i])){
      printf("Invalid username, please use only letters (A-Z or a-z)\n");
      exit(EXIT_FAILURE);
    }
  }

  // sanitize password input
  for(int i = 0; password[i]; i++){
    if(!isalnum(password[i])){
      printf("Invalid password, please use only letters and numbers (A-Z or a-z, 0-9)\n");
      exit(EXIT_FAILURE);
    }
  }

  printf("Welcome, %s!\n", username);

  return 0;
}