//FormAI DATASET v1.0 Category: Text processing ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char string[100];
  char c;
  int i,j;

  printf("Enter a string:\n");
  scanf("%s",string);
  printf("Enter a character to search for:\n");
  scanf(" %c",&c);

  for(i=0;i<strlen(string);i++) {
    if(string[i]==c) {
      printf("The character '%c' is found at position %d of the string.\n",c,i+1);
      j++;
    }
  }

  if(j==0) {
    printf("The character '%c' is not found in the string.\n",c);
  }

  return 0;
}