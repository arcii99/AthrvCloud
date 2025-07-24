//FormAI DATASET v1.0 Category: String manipulation ; Style: happy
#include <stdio.h>
#include <string.h>

int main() {
  char str1[50] = "Hello";
  char str2[50] = "World";
  
  // Concatenate Strings
  strcat(str1, str2);
  
  // Print concatenated String
  printf("%s\n", str1);
  
  // Convert String to Uppercase
  for(int i = 0; i < strlen(str1); i++) {
    if(str1[i] >= 'a' && str1[i] <= 'z') {
      str1[i] -= 32;
    }
  }
  
  // Print Uppercase String
  printf("%s\n", str1);
  
  // Convert String to Lowercase
  for(int i = 0; i < strlen(str1); i++) {
    if(str1[i] >= 'A' && str1[i] <= 'Z') {
      str1[i] += 32;
    }
  }
  
  // Print Lowercase String
  printf("%s\n", str1);
  
  // Reverse String
  char temp;
  int left = 0;
  int right = strlen(str1) - 1;
  
  while(left < right) {
    temp = str1[left];
    str1[left] = str1[right];
    str1[right] = temp;
    left++;
    right--;
  }
  
  // Print Reversed String
  printf("%s\n", str1);
  
  // Find Substring
  char substring[10] = "World";
  char *ptr = strstr(str1, substring);
  if(ptr != NULL) {
    printf("Substring found at index %ld!\n", ptr - str1);
  }
  else {
    printf("Substring not found.\n");
  }
  
  return 0;
}