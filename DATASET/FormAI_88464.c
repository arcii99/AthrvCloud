//FormAI DATASET v1.0 Category: Text processing ; Style: sophisticated
#include <stdio.h>
#include <string.h>

// Function to count the number of vowels in a given string
int count_vowels(char str[]) {
  int vowels = 0;
  // Loop through each character in the string
  for (int i = 0; i < strlen(str); i++) {
    // Check if the character is a vowel or not
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
        str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
    {
      // If it is a vowel, increment the counter
      vowels++;
    }
  }
  // Return the number of vowels
  return vowels;
}

int main() {
  char str[100];
  printf("Enter a string: ");
  // Read user input
  fgets(str, sizeof(str), stdin);
  // Remove newline character at the end of the input string
  str[strcspn(str, "\n")] = '\0';
  // Call function to count the number of vowels in the string
  int num_vowels = count_vowels(str);
  printf("The number of vowels in the string \"%s\" is %d\n", str, num_vowels);

  return 0;
}