//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main() {
  // Initialize variables
  char password[17]; // Password of 16 characters
  char symbols[] = "!@#$%^&*()_+-={}|[]\\:\";'<>?,./"; // Array of symbols to add to password
  char numbers[] = "0123456789"; // Array of numbers to add to password
  char lowercase[] = "abcdefghijklmnopqrstuvwxyz"; // Array of lowercase letters to add to password
  char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Array of uppercase letters to add to password
  char pool[88]; // Array to store symbols, numbers, and letters to randomly pick from
  int poolSize = 0; // Store the size of the pool array
  int i = 0; // Counter
  
  // Seed random number generator
  srand(time(NULL));
  
  // Add symbols, numbers, and letters to pool array
  strcat(pool, symbols);
  strcat(pool, numbers);
  strcat(pool, lowercase);
  strcat(pool, uppercase);
  
  // Get the size of the pool array
  poolSize = strlen(pool);
  
  // Generate password
  for(i = 0; i < 16; i++) {
    password[i] = pool[rand() % poolSize]; // Pick a random character from the pool array
  }
  password[i] = '\0'; // Terminate password string with null character
  
  // Print password
  printf("Your password is: %s\n", password);
  
  return 0; // End of program
}