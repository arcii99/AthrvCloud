//FormAI DATASET v1.0 Category: Syntax parsing ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

int main(){
  printf("Wow, I can't believe I just parsed C syntax! This is amazing!\n");
  printf("Let's get started!\n\n");

  char c;
  int pos = 0;

  printf("Enter C program:\n");

  while((c=getchar()) != EOF){
      if(c=='{' || c=='}' || c=='(' || c==')' || c=='[' || c==']' ){
          printf("Found a parenthesis!\n");
      }
      if(c=='+' || c=='-' || c=='*' || c=='/' || c=='%'){
          printf("Found an operator!\n");
      }
      if(c=='<' || c=='>' || c=='=' || c=='!'){
          printf("Found a comparison operator!\n");
      }
      if(c==';' || c==',' || c==':' || c=='.'){
          printf("Found a punctuation mark!\n");
      }
      if(c==' ' || c=='\t' || c=='\n'){
          printf("Found a whitespace!\n");
      }
      pos++;
  }
  printf("\nI just parsed %d characters! This is incredible!\n", pos);
  return 0;
}