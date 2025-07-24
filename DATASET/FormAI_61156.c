//FormAI DATASET v1.0 Category: Syntax parsing ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
  char* input = malloc(sizeof(char)*100);
  char* variable1 = malloc(sizeof(char)*20);
  char* operator = malloc(sizeof(char)*2);
  char* variable2 = malloc(sizeof(char)*20);
  printf("Enter the expression: ");
  scanf("%s %s %s", variable1, operator, variable2);
  if(strcmp(operator, "+")==0){
    printf("%s %s %s = %d", variable1, operator, variable2, (atoi(variable1)+atoi(variable2)));
  }
  else if(strcmp(operator, "-")==0){
    printf("%s %s %s = %d", variable1, operator, variable2, (atoi(variable1)-atoi(variable2)));
  }
  else if(strcmp(operator, "*")==0){
    printf("%s %s %s = %d", variable1, operator, variable2, (atoi(variable1)*atoi(variable2)));
  }
  else if(strcmp(operator, "/")==0){
    printf("%s %s %s = %d", variable1, operator, variable2, (atoi(variable1)/atoi(variable2)));
  }
  else{
    printf("Invalid operator");
  }
  return 0;
}