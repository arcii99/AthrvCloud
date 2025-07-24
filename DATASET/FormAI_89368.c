//FormAI DATASET v1.0 Category: Syntax parsing ; Style: light-weight
#include <stdio.h>

int main() {
  char str[100], token;
  int i = 0, state = 0;

  printf("Enter a C syntax statement: ");
  fgets(str, sizeof(str), stdin);

  while (str[i] != '\0') {
    token = str[i];

    switch (state) {
      case 0:
        if (token == '/') {
          state = 1;
        } else if (token == '"' || token == '\'') {
          state = 2;
        } else if (token == '(') {
          state = 3;
        } else if (token == ')') {
          state = 4;
        } else if (token == '{') {
          state = 5;
        } else if (token == '}') {
          state = 6;
        }
        break;
      
      case 1:
        if (token == '/') {
          state = 7;
        } else if (token == '*') {
          state = 8;
        } else {
          state = 0;
        }
        break;

      case 2:
        if (token == '"' || token == '\'') {
          state = 0;
        }
        break;

      case 3:
        if (token == ')') {
          state = 0;
        }
        break;

      case 4:
        break;

      case 5:
        if (token == '}') {
          state = 0;
        }
        break;

      case 6:
        break;

      case 7:
        state = 0;
        break;

      case 8:
        if (token == '*') {
          state = 9;
        }
        break;

      case 9:
        if (token == '/') {
          state = 0;
        } else {
          state = 8;
        }
        break;

      default:
        break;
    }

    i++;
  }

  if (state == 0) {
    printf("C syntax is correct.\n");
  } else {
    printf("C syntax is incorrect.\n");
  }

  return 0;
}