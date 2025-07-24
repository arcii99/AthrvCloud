//FormAI DATASET v1.0 Category: Syntax parsing ; Style: real-life
#include <stdio.h>

int main() {
  char input[100];
  printf("Enter a C syntax statement: ");
  scanf("%s", input);

  int i = 0;
  int state = 0;
  while(input[i] != '\0') {
    switch(state) {
      case 0:
        if(input[i] == 'i') state = 1;
        else if(input[i] == 'f') state = 3;
        else if(input[i] == 'w') state = 5;
        else if(input[i] == 'e') state = 7;
        else if(input[i] == 's') state = 9;
        else if(input[i] == 'd') state = 13;
        else if(input[i] == 'l') state = 15;
        else if(input[i] == '{') state = 17;
        else if(input[i] == '}') state = 18;
        else if(input[i] == '(') state = 19;
        else if(input[i] == ')') state = 20;
        else if(input[i] == '=') state = 21;
        else if(input[i] == ';') state = 22;
        else if(input[i] == '+') state = 23;
        else if(input[i] == '-') state = 24;
        else if(input[i] == '*') state = 25;
        else if(input[i] == '/') state = 26;
        else{
          printf("Syntax Error!");
          return 0;
        }
        break;
      case 1:
        if(input[i] == 'n') state = 2;
        else{
          printf("Syntax Error!");
          return 0;
        }
        break;
      case 2:
        if(input[i] == 't') state = 18;
        else{
          printf("Syntax Error!");
          return 0;
        }
        break;
      case 3:
        if(input[i] == 'o') state = 4;
        else{
          printf("Syntax Error!");
          return 0;
        }
        break;
      case 4:
        if(input[i] == 18) state = 18;
        else{
          printf("Syntax Error!");
          return 0;
        }
        break;
      case 5:
        if(input[i] == 'h') state = 6;
        else{
          printf("Syntax Error!");
          return 0;
        }
        break;
      case 6:
        if(input[i] == 'i') state = 7;
        else{
          printf("Syntax Error!");
          return 0;
        }
        break;
      case 7:
        if(input[i] == 'l') state = 8;
        else{
          printf("Syntax Error!");
          return 0;
        }
        break;
      case 8:
        if(input[i] == 'e') state = 18;
        else{
          printf("Syntax Error!");
          return 0;
        }
        break;
      case 9:
        if(input[i] == 't') state = 10;
        else{
          printf("Syntax Error!");
          return 0;
        }
        break;
      case 10:
        if(input[i] == 'w') state = 11;
        else{
          printf("Syntax Error!");
          return 0;
        }
        break;
      case 11:
        if(input[i] == 'c') state = 12;
        else{
          printf("Syntax Error!");
          return 0;
        }
        break;
      case 12:
        if(input[i] == 'h') state = 18;
        else{
          printf("Syntax Error!");
          return 0;
        }
        break;
      case 13:
        if(input[i] == 'o') state = 14;
        else{
          printf("Syntax Error!");
          return 0;
        }
        break;
      case 14:
        if(input[i] == 'u') state = 15;
        else{
          printf("Syntax Error!");
          return 0;
        }
        break;
      case 15:
        if(input[i] == 'p') state = 16;
        else{
          printf("Syntax Error!");
          return 0;
        }
        break;
      case 16:
        if(input[i] == '-') state = 17;
        else{
          printf("Syntax Error!");
          return 0;
        }
        break;
      case 17:
        printf("Valid C syntax");
        return 0;
      case 18:
        if(input[i] == '{' || input[i] == ';' || input[i] == '}'){
          state = 0;
        }
        else{
          printf("Syntax Error!");
          return 0;
        }
        break;
      case 19:
        if(input[i] == ')'){
          state = 0;
        }
        else{
          printf("Syntax Error!");
          return 0;
        }
        break;
      case 20:
        if(input[i] == ';'){
          state = 0;
        }
        else{
          printf("Syntax Error!");
          return 0;
        }
        break;
      case 21:
        if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
          state = 0;
        }
        else{
          printf("Syntax Error!");
          return 0;
        }
        break;
      case 22:
        printf("Valid C syntax");
        return 0;
      case 23:
        if(input[i] == '+'){
          state = 0;
        }
        else{
          printf("Syntax Error!");
          return 0;
        }
        break;
      case 24:
        if(input[i] == '-'){
          state = 0;
        }
        else{
          printf("Syntax Error!");
          return 0;
        }
        break;
      case 25:
        if(input[i] == '*'){
          state = 0;
        }
        else{
          printf("Syntax Error!");
          return 0;
        }
        break;
      case 26:
        if(input[i] == '/'){
          state = 0;
        }
        else{
          printf("Syntax Error!");
          return 0;
        }
        break;
    }
    i++;
  }
  printf("Valid C syntax");
  return 0;
}