//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: brave
#include <stdio.h>
#include <string.h>

// function to translate the given string from C Alien Language
void translate(char str[]) {
  int len = strlen(str);
  for(int i=0; i<len; i++){
    switch(str[i]){
      case 'C':
        printf("Ka");
        break;
      case 'A':
        printf("Di");
        break;
      case 'T':
        printf("Mo");
        break;
      case 'G':
        printf("Fu");
        break;
      default:
        printf("%c", str[i]);
    }
  }
}

int main() {
  char input[100];
  
  printf("Enter a string in C Alien Language: ");
  scanf("%s", input);
  
  printf("Translated string: ");
  translate(input);
  
  printf("\n");
  
  return 0;
}