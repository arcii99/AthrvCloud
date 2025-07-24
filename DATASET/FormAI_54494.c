//FormAI DATASET v1.0 Category: Syntax parsing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char input[] = "int add(int x, int y){ int z; z = x + y; return z; }";
  char buffer[256], *ptr1, *ptr2;
  char *name = NULL, *type = NULL;
  
  ptr1 = input;
  while(*ptr1 != '\0') {
    ptr2 = buffer;
    while(*ptr1 != '\n') {
      *ptr2++ = *ptr1++;
    }
    *ptr2 = '\0';
    
    // check if the line is a variable declaration
    if (strstr(buffer, "int ") || strstr(buffer, "char ")) {
      type = strtok(buffer, " ");
      name = strtok(NULL, ";");
      printf("%s %s;\n", type, name);
    }
    // check if the line is the function name
    else if (strstr(buffer, "int ") || strstr(buffer, "char ")) {
      type = strtok(buffer, " ");
      name = strtok(NULL, "(");
      printf("%s %s(", type, name);
    }
    ptr1++;
  }
  printf(");\n");
  
  return 0;
}