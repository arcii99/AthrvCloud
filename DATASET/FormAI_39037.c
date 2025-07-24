//FormAI DATASET v1.0 Category: Data recovery tool ; Style: funny
#include <stdio.h>

int main() {
  printf("Welcome to my data recovery tool!\n");
  printf("Please enter your password to begin: ");
  char password[10];
  scanf("%s", password);
  
  // Check the password
  if (strcmp(password, "open sesame") != 0) {
    printf("Incorrect password. Aborting data recovery...\n");
    return 0;
  }
  
  printf("Access granted. Commencing data recovery...\n");
  
  // Simulate data recovery process
  for (int i = 0; i < 100; i++) {
    printf("Scanning sector %d...\n", i);
    if (i % 20 == 0) {
      printf("Error encountered. Attempting to recover data...\n");
      printf("Data recovered!\n");
    }
    else {
      printf("No errors found.\n");
    }
  }
  
  printf("Data recovery complete. Would you like to save the data to a file? (y/n): ");
  char save_option;
  scanf(" %c", &save_option);
  
  if (save_option == 'y') {
    printf("Please enter a filename to save the data to: ");
    char filename[50];
    scanf("%s", filename);
    printf("Data saved to file %s.\n", filename);
  }
  else {
    printf("Data not saved.\n");
  }
  
  printf("Thank you for using my data recovery tool!\n");
  
  return 0;
}