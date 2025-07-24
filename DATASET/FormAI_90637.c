//FormAI DATASET v1.0 Category: Syntax parsing ; Style: retro
#include<stdio.h>

int main(){
  char program[] = "PRINT 'Hello, World!'\n", token[7][20];
  int i=0, j=0;

  while(program[i] != '\0'){
    if(program[i] == ' ' || program[i] == '\n'){
      token[j][0] = '\0';
      j++;
    }
    else{
      token[j][i%20] = program[i];
    }
    i++;
  }
  token[j][i%20] = '\0';

  if(strcmp(token[0], "PRINT") == 0){
    printf("%s\n", token[1]);
  }
  else{
    printf("Syntax Error\n");
  }

  return 0;
}