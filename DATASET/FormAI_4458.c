//FormAI DATASET v1.0 Category: String manipulation ; Style: sophisticated
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100 // maximum length of string

int main() {

  char str[MAX_LEN]; // declare string variable
  char new_str[MAX_LEN]; // declare new string variable
  int len; // declare integer variable to store string length
  int i, j;

  printf("Enter a string: ");
  fgets(str, MAX_LEN, stdin); // get user input

  len = strlen(str); // get string length

  // reverse the string 
  for (i = 0, j = len - 2; j >= 0; i++, j--) {
    new_str[i] = str[j];
  }

  new_str[i] = '\0'; // add null terminator 

  // output the new string
  printf("The reversed string is: %s\n", new_str);

  // remove all vowels from the string 
  for (i = 0, j = 0; i < len; i++) {
    if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u'
        && str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
      new_str[j] = str[i];
      j++;
    }
  }

  new_str[j] = '\0'; // add null terminator

  // output the new string
  printf("The string with vowels removed is: %s\n", new_str);

  // find the frequency of each character in the string 
  int freq[26] = {0};

  for (i = 0; i < len - 1; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      freq[str[i] - 'a']++;
    } else if (str[i] >= 'A' && str[i] <= 'Z') {
      freq[str[i] - 'A']++;
    }
  }

  // output the frequency of each character
  printf("Frequency of each character:\n");

  for (i = 0; i < 26; i++) {
    if (freq[i] != 0) {
      printf("%c: %d\n", i + 'a', freq[i]);
    }
  }

  return 0;
}