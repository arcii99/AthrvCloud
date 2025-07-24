//FormAI DATASET v1.0 Category: Syntax parsing ; Style: sophisticated
#include <stdio.h>
#include <string.h>

void parseSyntax(char *code) {
  int i, j, len = strlen(code);
  int flag = 0;

  for(i = 0; i < len; i++) {
    if(code[i] == '/') {
      if(i != len-1 && code[i+1] == '/') {
        printf("Single Line Comment: ");
        for(j = i+2; j < len && code[j] != '\n'; j++) {
          printf("%c", code[j]);
        }
        printf("\n");
      }
      else if(i != len-1 && code[i+1] == '*') {
        printf("Multi Line Comment: ");
        flag = 1;
      }
    }
    else if(code[i] == '*') {
      if(flag == 1 && i != len-1 && code[i+1] == '/') {
        printf("\n");
        flag = 0;
      }
      else if(flag == 1) {
        printf("%c", code[i]);
      }
    }
    else if(code[i] == '"' || code[i] == '\'') {
      printf("%c", code[i]); // print the opening quotation mark
      i++; //move to the next character
      while(i < len && code[i] != code[i-1]) {
        printf("%c", code[i]);
        i++;
      }
      printf("%c\n", code[i-1]); //print the closing quotation mark
    }
    else if(code[i] == '#') {
        printf("Pre-processor Directive: ");
        for(j = i+1; j < len && code[j] != '\n'; j++) {
          printf("%c", code[j]);
        }
        printf("\n");
    }
  }
}

int main() {
  char code[] = "#include <stdio.h>\n\nint main() {\n    //Single Line Comment\n    /*Multi Line Comment*/\n    printf(\"Hello World!\");\n    return 0;\n}\n";

  parseSyntax(code);

  return 0;
}