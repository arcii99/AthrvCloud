//FormAI DATASET v1.0 Category: String manipulation ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {
  char message[100] = "Happy ";
  char occasion[50] = "Birthday!";
  char full_message[150];
  
  // Concatenate two strings
  strcat(full_message, message);
  strcat(full_message, occasion);
  
  // Print the message
  printf("%s\n", full_message);
  
  // Replace a letter in the string
  char replace_char = 'i';
  char new_char = 'y';
  for (int i = 0; i < strlen(full_message); i++) {
    if (full_message[i] == replace_char) {
      full_message[i] = new_char;
    }
  }
  
  // Print the updated message
  printf("%s\n", full_message);
  
  // Count the number of vowels in the string
  int vowel_count = 0;
  for (int i = 0; i < strlen(full_message); i++) {
    char c = full_message[i];
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      vowel_count++;
    }
  }
  
  // Print the number of vowels
  printf("There are %d vowels in the message.\n", vowel_count);
  
  return 0;
}