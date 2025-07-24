//FormAI DATASET v1.0 Category: Text processing ; Style: genious
#include <stdio.h>
#include <string.h>

int main() {
  char text[1000];

  printf("Enter some text: ");
  fgets(text, sizeof(text), stdin); // Get input from user

  int count = 0;
  for (int i=0; i<strlen(text); i++) {
    if (text[i] == ' ') { // Count number of words by counting spaces
      count++;
    }
  }

  printf("Original text:\n%s", text);

  // Reverse the text
  printf("Reversed text:\n");
  for (int i=strlen(text)-1; i>=0; i--) {
    printf("%c", text[i]);
  }

  // Count number of vowels
  int vowels = 0;
  for (int i=0; i<strlen(text); i++) {
    if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u') {
      vowels++;
    }
  }
  printf("Number of vowels: %d\n", vowels);

  // Remove spaces from text
  char newtext[1000];
  int j=0;
  for (int i=0; i<strlen(text); i++) {
    if (text[i] != ' ') {
      newtext[j] = text[i];
      j++;
    }
  }
  newtext[j] = '\0'; // Add null terminator
  printf("Text without spaces:\n%s", newtext);

  // Check if text is a palindrome
  int palindrome = 1; // Assume it's a palindrome
  for (int i=0; i<strlen(text)/2; i++) {
    if (text[i] != text[strlen(text)-i-1]) { 
      palindrome = 0; // Not a palindrome
      break;
    }
  }
  if (palindrome) {
    printf("The text is a palindrome.\n");
  } else {
    printf("The text is not a palindrome.\n");
  }

  // Encrypt the text
  char encrypted[1000];
  for (int i=0; i<strlen(text); i++) {
    if (text[i] >= 'a' && text[i] <= 'z') {
      encrypted[i] = 'a' + ('z' - text[i]); // Reverse the character
    } else if (text[i] >= 'A' && text[i] <= 'Z') {
      encrypted[i] = 'A' + ('Z' - text[i]); // Reverse the character
    } else {
      encrypted[i] = text[i]; // Leave non-alphabetic characters as is
    }
  }
  encrypted[strlen(text)] = '\0'; // Add null terminator
  printf("Encrypted text:\n%s", encrypted);

  return 0;
}