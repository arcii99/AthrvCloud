//FormAI DATASET v1.0 Category: String manipulation ; Style: futuristic
#include <stdio.h>
#include <string.h>

int main() {
  char str1[50] = "Greetings";
  char str2[50] = " from the future!";
  
  // Concatenate two strings
  strcat(str1, str2);
  
  // Print the concatenated string
  printf("Concatenated string: %s\n", str1);
  
  // Replace a substring in a string
  char str3[50] = "The year is 2050";
  char* search = "2050";
  char* replace = "2100";
  char* pos = strstr(str3, search);
  
  while(pos) {
    // Move the characters after the search to new memory locations
    memmove(pos+strlen(replace), pos+strlen(search), strlen(pos+strlen(search))+1);
    
    // Replace the search with the replace string
    memcpy(pos, replace, strlen(replace));
    
    // Search for the next occurrence of the search string
    pos = strstr(pos+strlen(replace), search);
  }
  
  // Print the string after replacement
  printf("Replaced string: %s\n", str3);
  
  // Reverse a string
  char str4[50] = "Madam, I'm Adam!";
  int i, j;
  
  for(i=0, j=strlen(str4)-1; i<j; i++, j--) {
    char temp = str4[i];
    str4[i] = str4[j];
    str4[j] = temp;
  }
  
  // Print the reversed string
  printf("Reversed string: %s\n", str4);
  
  return 0;
}