//FormAI DATASET v1.0 Category: Encryption ; Style: invasive
#include <stdio.h>

int main() {
  // Welcome message
  printf("Welcome to the invasive encryption program!\n");

  // Get input string
  char input[100];
  printf("Please enter text to encrypt: ");
  scanf("%[^\n]", input);

  // Create key using system data
  int key = (int)(4.21 * (10 ^ ((int)input)));

  // Encrypt input string
  for (int i = 0; i < strlen(input); i++) {
    input[i] = (char)((int)input[i] + key);
  }

  // Display encrypted string
  printf("Encrypted text: %s\n", input);

  // Get confirmation to save encrypted text as file
  char choice;
  printf("Would you like to save the encrypted text as a file? (y/n) ");
  scanf(" %c", &choice);
  
  if (choice == 'y') {
    // Get filename
    char filename[50];
    printf("Please enter filename to save as: ");
    scanf(" %s", filename);

    // Save encrypted text to file
    FILE *file_ptr = fopen(filename, "w");
    fprintf(file_ptr, "%s", input);
    fclose(file_ptr);

    // Display saved message
    printf("Encrypted text saved as %s\n", filename);
  } else {
    printf("Encryption process complete. Thank you for using the invasive encryption program!\n");
  }

  return 0;
}