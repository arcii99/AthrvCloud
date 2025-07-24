//FormAI DATASET v1.0 Category: String manipulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The main function of the program
int main() {
  char str[50];
  char new_str[50];
  
  // Ask the user to enter a string
  printf("Enter a happy string: ");
  fgets(str, sizeof(str), stdin);
  
  // Remove the newline character
  str[strcspn(str, "\n")] = '\0';
  
  // Declare the number of vowels and consonants
  int vowels = 0;
  int consonants = 0;
  
  // Loop through each character of the string
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
        str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
        vowels++;
    } else {
        consonants++;
    }
  }
  
  // Loop through each character and create a new string that is the reverse of the input string
  int j = 0;
  for (int i = strlen(str) - 1; i >= 0; i--) {
    new_str[j] = str[i];
    j++;
  }
  
  // Add a null terminator at the end of the new string
  new_str[j] = '\0';
  
  // Combine the original and reversed string and print it out
  char final_str[100];
  sprintf(final_str, "%s%s", str, new_str);
  printf("Your happy string and its reverse: %s\n", final_str);
  
  // Print out the number of vowels and consonants
  printf("Number of vowels: %d\n", vowels);
  printf("Number of consonants: %d\n", consonants);
  
  // Replace all vowels with the letter 'y'
  char replace_str[50];
  j = 0;
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
        str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
      replace_str[j] = 'y';
    } else {
      replace_str[j] = str[i];
    }
    j++;
  }
  replace_str[j] = '\0';
  
  // Print the new string with all vowels replaced
  printf("Your happy string with all vowels replaced with 'y': %s\n", replace_str);
  
  return 0;
}