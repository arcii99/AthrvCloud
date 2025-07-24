//FormAI DATASET v1.0 Category: Error handling ; Style: immersive
#include <stdio.h>

int main() {
  printf("Welcome to the secret vault.\n");
  
  int password = 1234;
  int user_input;
  
  printf("Enter the password to access the vault: ");
  scanf("%d", &user_input);
  
  if(user_input == password) {
    printf("Access granted. Welcome to the vault.\n");
    int top_secret_files = 1000;
    
    // Access top secret files
    for(int i = 0; i < top_secret_files; i++) {
      printf("Reading top secret file %d...\n", i);
      // Simulating some complex operation with a sleep function
      sleep(1);
    }
    
    printf("All top secret files read successfully.\n");
  } else {
    printf("ERROR: Access denied. Incorrect password.\n");
    printf("Please try again later.\n");
  }
  
  return 0;
}