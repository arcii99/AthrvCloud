//FormAI DATASET v1.0 Category: Syntax parsing ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 100

char* parse_c_syntax(char* input){
  char* output = (char*) malloc(MAX_LENGTH * sizeof(char));
  int len = strlen(input);
  int idx = 0;

  for(int i=0; i<len; i++){
    if(input[i] == '('){
      output[idx++] = input[i];
      output[idx++] = ' ';
    }
    else if(input[i] == ')'){
      output[idx++] = ' ';
      output[idx++] = input[i];
    }
    else if(input[i] == '{'){
      output[idx++] = '\n';
      output[idx++] = input[i];
      output[idx++] = '\n';
    }
    else if(input[i] == '}'){
      output[idx++] = '\n';
      output[idx++] = input[i];
      output[idx++] = '\n';
    }
    else{
      output[idx++] = input[i];
    }
  }

  return output;
}

int main(){
  char input[MAX_LENGTH];
  printf("Enter C Syntax: ");
  fgets(input, MAX_LENGTH, stdin);

  char* output = parse_c_syntax(input);
  printf("Parsed C Syntax: %s", output);

  free(output);
  return 0;
}