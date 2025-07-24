//FormAI DATASET v1.0 Category: String manipulation ; Style: unmistakable
#include <stdio.h>
#include <string.h>

int main() {
  // Declare a string variable 
  char name[20] = "John Doe";
  
  // Print the original string
  printf("Original name: %s\n", name);
  
  // Use strlen() function to obtain the length of the string
  int len = strlen(name);
  
  // Reverse the string
  char reversedName[20];
  int i, j;
  for (i = len - 1, j = 0; i >= 0; i--, j++) {
    reversedName[j] = name[i];
  }
  reversedName[j] = '\0';
  
  // Print the reversed string
  printf("Reversed name: %s\n", reversedName);
  
  // Copy a portion of the original string to a new string
  char copiedName[10];
  strncpy(copiedName, name, 4);
  copiedName[4] = '\0';
  
  // Print the copied string
  printf("Copied name: %s\n", copiedName);
  
  // Compare two strings
  char newName[20] = "Jane Doe";
  int compare = strcmp(name, newName);
  if (compare == 0) {
    printf("The names are the same.\n");
  } else {
    printf("The names are different.\n");
  }
  
  return 0;
}