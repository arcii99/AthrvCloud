//FormAI DATASET v1.0 Category: String manipulation ; Style: expert-level
#include <stdio.h>
#include <string.h>

/* This program takes a C String and manipulates it in various ways */

int main() {

  char str1[20] = "Hello";
  char str2[20] = "World";
  char temp[20];
  
  /* Concatenating str1 and str2 */
  
  printf("Initial Strings:\nstr1 = %s\nstr2 = %s\n", str1, str2);
  
  strcat(str1, str2);
  
  printf("Concatenated String:\n%s\n", str1);
  
  /* Copying str1 into temp */

  strcpy(temp, str1);

  printf("Copy of str1 in temp:\n%s\n", temp);
  
  /* Reversing temp */
  
  int length = strlen(temp);
  
  for(int i = 0; i < length/2; i++) {
    char c = temp[i];
    temp[i] = temp[length-i-1];
    temp[length-i-1] = c;
  }
  
  printf("Reversed String:\n%s\n", temp);
  
  /* Finding the first occurrence of "o" in str1 */
  
  char* found = strchr(str1, 'o');
  
  printf("First Occurrence of 'o':\n%s\n", found);
  
  /* Counting the occurrences of "l" in str1 */
  
  int count = 0;
  char* ptr = str1;
  
  while((ptr = strchr(ptr, 'l')) != NULL) {
    count++;
    ptr++;
  }
  
  printf("Number of Occurrences of 'l':\n%i\n", count);
  
  return 0;
}