//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){
  if(argc != 2){
    printf("Usage: %s <file>\n", argv[0]);
    return 1;
  }
  FILE *fp = fopen(argv[1], "r");
  if(fp == NULL){
    printf("Could not open file: %s\n", argv[1]);
    return 1;
  }
  int charCount = 0;
  int wordCount = 0;
  int lineCount = 0;
  int inWord = 0;
  int inLine = 0;
  char c = fgetc(fp);
  while(c != EOF){
    charCount++;
    if(isspace(c)){
      inWord = 0;
    } else{
      if(!inWord){
        inWord = 1;
        wordCount++;
      }
    }
    if(c == '\n'){
      lineCount++;
      inLine = 0;
    } else{
      inLine = 1;
    }
    c = fgetc(fp);
   }
  fclose(fp);

  printf("The file %s has:\n\n", argv[1]);
  printf("%d characters\n", charCount);
  printf("%d words\n", wordCount);
  printf("%d lines\n", lineCount);

  return 0;
}