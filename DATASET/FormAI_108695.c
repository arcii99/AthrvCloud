//FormAI DATASET v1.0 Category: Syntax parsing ; Style: complex
#include<stdio.h>
int main(){
  char input[1000];
  printf("Enter the C Syntax Code:\n");
  fgets(input, 1000, stdin);
  int i=0, open_parentheses=0, close_parentheses=0, open_bracket=0, close_bracket=0, open_curly=0, close_curly=0,colon=0,semicolon=0;
  while(input[i]!='\0'){
    switch(input[i]) {
      case '(':
        open_parentheses++;
        break;
      case ')':
        close_parentheses++;
        break;
      case '[':
        open_bracket++;
        break;
      case ']':
        close_bracket++;
        break;
      case '{':
        open_curly++;
        break;
      case '}':
        close_curly++;
        break;
      case ':':
        colon++;
        break;
      case ';':
        semicolon++;
        break;
    }
    i++;
  }
  if(open_parentheses==close_parentheses && open_bracket==close_bracket && open_curly==close_curly && colon==semicolon){
    printf("The entered C syntax code is correct!");
  }
  else{
    printf("The entered C syntax code is incorrect!");
  }
  return 0;
}