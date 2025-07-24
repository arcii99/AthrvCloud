//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: surrealist
#include <stdio.h>
#include <string.h>

int main () {
  char str[100];
  printf("Enter a word: ");
  scanf("%s", str);
  int len = strlen(str);
  int pal = 1;
  for (int i = 0; i < len/2; i++){
    if (str[i] != str[len-i-1]){
      pal = 0;
      break;
    }
  }
  if (pal) {
    printf("%s is a C Palindrome!\n", str);
  } 
  else {
    printf("%s is not a C Palindrome. :(\n", str);
  }
  return 0;
}