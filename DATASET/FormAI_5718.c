//FormAI DATASET v1.0 Category: Text processing ; Style: portable
#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Function prototypes
void countChars(char* str);
void reverseString(char* str);

int main() {
  char str[MAX_LENGTH];

  printf("Enter a string: ");
  fgets(str, MAX_LENGTH, stdin);

  // Count the number of characters in the string
  countChars(str);

  // Reverse the string
  reverseString(str);

  // Print the reversed string
  printf("The reversed string is: %s", str);

  return 0;
}

void countChars(char* str) {
  int i = 0, upperCount = 0, lowerCount = 0, digitCount = 0, spaceCount = 0;
  while (str[i] != '\0') {
    if (isupper(str[i]))
      upperCount++;
    else if (islower(str[i]))
      lowerCount++;
    else if (isdigit(str[i]))
      digitCount++;
    else if (isspace(str[i]))
      spaceCount++;
    i++;
  }
  printf("The string contains:\n");
  printf("%d uppercase characters.\n", upperCount);
  printf("%d lowercase characters.\n", lowerCount);
  printf("%d digits.\n", digitCount);
  printf("%d spaces.\n", spaceCount);
}

void reverseString(char* str) {
  int i = 0, j = 0, length = 0;
  char temp;

  // Find the length of the string
  while (str[length] != '\0')
    length++;

  // Reverse the string
  j = length - 1;
  while (i < j) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i++;
    j--;
  }
}