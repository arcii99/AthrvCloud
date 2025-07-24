//FormAI DATASET v1.0 Category: String manipulation ; Style: automated
#include <stdio.h>

int main() {
  char str1[100] = "Hello";
  char str2[100] = " World!";
  char str3[100];
  
  // Concatenate two strings
  sprintf(str3, "%s%s", str1, str2);
  
  printf("Concatenated string: %s\n", str3);
  
  // Get length of string
  int length = 0;
  while (str3[length] != '\0') {
    length++;
  }
  printf("Length of string: %d\n", length);
  
  // Convert string to uppercase
  for (int i = 0; str3[i] != '\0'; i++) {
    if(str3[i] >= 'a' && str3[i] <= 'z') {
      str3[i] = str3[i] -32; // ASCII code for uppercase letters
    }
  }
  printf("Uppercase string: %s\n", str3);
  
  // Reverse the string
  char temp;
  int i = 0, j = length-1;
  
  while (i<j) {
    temp = str3[i];
    str3[i] = str3[j];
    str3[j] = temp;
    i++;
    j--;
  }
  printf("Reversed string: %s\n", str3);
  
  // Find substring
  char substring[50] = "WOR";
  int sub_length = 0;
  while (substring[sub_length] != '\0') {
    sub_length++;
  }
  
  int count = 0;
  for (int i = 0; str3[i] != '\0'; i++) {
    int j = 0;
    while (j < sub_length && str3[i+j] == substring[j]) {
      j++;
    }
    if (j == sub_length) {
      count++;
    }
  }
  printf("Substring '%s' found %d times.\n", substring, count);
  
  return 0;
}