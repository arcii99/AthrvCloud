//FormAI DATASET v1.0 Category: Syntax parsing ; Style: portable
#include <stdio.h>

// Function to parse and print a C code syntax tree
void parseCCode(const char *code) {
   int level = 0;
   char prevChar = 0;
   while (*code) {
      if (prevChar == '/' && *code == '/') { // check for comment
         while (*code && *code != '\n') {
            putchar(*code++);
         }
         putchar(*code); // print the new line character
      } else if (*code == '{') {
         putchar(*code);
         putchar('\n');
         level++;
         for (int i = 0; i < level; i++) {
            putchar('\t');
         }
      } else if (*code == '}') {
         putchar('\n');
         level--;
         for (int i = 0; i < level; i++) {
            putchar('\t');
         }
         putchar(*code);
      } else if (*code == ';') {
         putchar(*code);
         putchar('\n');
         for (int i = 0; i < level; i++) {
            putchar('\t');
         }
      } else {
         putchar(*code);
      }
      prevChar = *code++;
   }
}

int main() {
   const char *code =
      "#include <stdio.h>\n"
      "\n"
      "int main() {\n"
      "   printf(\"Hello, world!\\n\");\n"
      "   return 0;\n"
      "}";
   parseCCode(code);
   return 0;
}