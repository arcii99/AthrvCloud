//FormAI DATASET v1.0 Category: Syntax parsing ; Style: peaceful
#include <stdio.h>

/* peaceful syntax parsing example */

int main() {
  char code[] = "int n = 5;\nif(n > 3) {\n  printf(\"n is greater than 3\\n\");\n}\nelse {\n  printf(\"n is not greater than 3\\n\");\n}";
  int i, tabCount = 0;
  printf("The code to be parsed: \n%s\n", code);

  for (i = 0; code[i]; i++) {
    if (code[i] == '{') {
      printf("{\n");
      tabCount++;
      printTabs(tabCount);
    }
    else if (code[i] == '}') {
      printf("\n");
      tabCount--;
      printTabs(tabCount);
      printf("}");
    }
    else if (code[i] == '\n') {
      printf("\n");
      printTabs(tabCount);
    }
    else {
      printf("%c", code[i]);
    }
  }
  printf("\n");

  return 0;
}

void printTabs(int tabs) {
  int i = 0;
  for (i = 0; i < tabs; i++) {
    printf("  ");
  }
}