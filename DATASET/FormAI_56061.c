//FormAI DATASET v1.0 Category: HTML beautifier ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* beautify(char* code) {
  int indent = 0;
  int len = strlen(code);
  char* res = (char*)malloc(sizeof(char) * (len * 2));
  memset(res, 0, sizeof(res));
  for (int i = 0; i < len; i++) {
    if (code[i] == '{') {
      strcat(res, "{\n");
      indent++;
      for (int j = 0; j < indent; j++) {
        strcat(res, "  ");
      }
    } else if (code[i] == '}') {
      strcat(res, "\n");
      indent--;
      for (int j = 0; j < indent; j++) {
        strcat(res, "  ");
      }
      strcat(res, "}\n");
      for (int j = 0; j < indent; j++) {
        strcat(res, "  ");
      }
    } else if (code[i] == ';') {
      strcat(res, ";\n");
      for (int j = 0; j < indent; j++) {
        strcat(res, "  ");
      }
    } else {
      strncat(res, &code[i], 1);
    }
  }
  return res;
}

int main() {
  char* code = "<html><head><title>Test HTML page</title></head><body><h1>Hello, World!</h1></body></html>";
  char* beautified_code = beautify(code);
  printf("%s", beautified_code);
  free(beautified_code);
  return 0;
}