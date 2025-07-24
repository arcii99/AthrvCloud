//FormAI DATASET v1.0 Category: String manipulation ; Style: expert-level
#include <stdio.h>
#include <string.h>

int main() {
  char str1[50], str2[50], str3[100];
  int len1, len2, i, j;
 
  printf("Enter the first string: ");
  fgets(str1, 50, stdin);
  len1 = strlen(str1);
  str1[len1 - 1] = '\0'; // remove newline character
 
  printf("Enter the second string: ");
  fgets(str2, 50, stdin);
  len2 = strlen(str2);
  str2[len2 - 1] = '\0'; // remove newline character
 
  // concatenate two strings into a new string
  for (i = 0; str1[i] != '\0'; i++) {
    str3[i] = str1[i];
  }
  for (j = 0; str2[j] != '\0'; j++) {
    str3[i + j] = str2[j];
  }
  str3[i + j] = '\0';
  printf("Concatenated string: %s\n", str3);
 
  // reverse the first string
  for (i = 0, j = len1 - 1; i < j; i++, j--) {
    char temp = str1[i];
    str1[i] = str1[j];
    str1[j] = temp;
  }
  printf("Reversed first string: %s\n", str1);
 
  // count the number of vowels in the second string
  int vowel_count = 0;
  for (i = 0; str2[i] != '\0'; i++) {
    if (str2[i] == 'a' || str2[i] == 'e' || str2[i] == 'i' || str2[i] == 'o' || str2[i] == 'u') {
      vowel_count++;
    }
  }
  printf("Number of vowels in second string: %d\n", vowel_count);
 
  // check if the first string is a palindrome
  int is_palindrome = 1;
  for (i = 0, j = len1 - 1; i < j; i++, j--) {
    if (str1[i] != str1[j]) {
      is_palindrome = 0;
      break;
    }
  }
  if (is_palindrome) {
    printf("First string is a palindrome!\n");
  } else {
    printf("First string is not a palindrome.\n");
  }
 
  return 0;
}