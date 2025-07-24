//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: thoughtful
#include <stdio.h> 
#include <string.h> 

#define MAX_STRING_LENGTH 100

void getAsciiArt(char string[]) {
  int n = strlen(string);
  int i, j; 
  
  for(i = 0; i < n; i++) { 
    switch(string[i]) {
      case ' ': 
        printf("     "); 
        break;
      case 'a':
      case 'A':
        printf("   /\\"); 
        printf("  /  \\"); 
        printf(" / /\\ \\");
        printf("/ ____ \\");
        printf("\\/    \\/");
        break; 
      case 'b':
      case 'B':
        printf(" |-----\\"); 
        printf(" |      \\"); 
        printf(" |-----/"); 
        printf(" |      \\"); 
        printf(" |______/"); 
        break;
      case 'c': 
      case 'C':
        printf("   ----"); 
        printf(" /      \\"); 
        printf("|         "); 
        printf("|         "); 
        printf(" \\_____/");
        break; 
      // add more cases for ascii art characters
      default: 
        printf("%c is not supported!", string[i]); 
        break; 
    }
    printf("\n"); 
  } 
}

int main() { 
  char string[MAX_STRING_LENGTH];
  
  printf("Enter a string in all caps: "); 
  fgets(string, MAX_STRING_LENGTH, stdin); 

  getAsciiArt(string); 
  
  return 0; 
}