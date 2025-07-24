//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>
#define ALIEN_ALPHABET "gtdbfphjklmnaeiouqcrvxzyw"

void translate_alien(char* input);
char alien_alphabet[26];

int main(){
  strcpy(alien_alphabet, ALIEN_ALPHABET);
  char input[256];
  printf("Enter the alien language sentence to be translated:\n");
  fgets(input, sizeof(input), stdin);
  translate_alien(input);
  return 0;
}

void translate_alien(char* input){
  int i, j, len = strlen(input);
  for(i=0; i<len; i++){
    if(input[i] != ' ' && input[i] != '\n'){
      j = input[i] - 'A';    
      printf("%c", alien_alphabet[j]);
    }else{
      printf(" ");
    }
  }
}