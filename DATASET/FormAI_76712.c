//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

void beautify_html(char* filename);
void indent(int cnt, FILE* output);

int main(int argc, char* argv[]) {
   if(argc != 2) {
      printf("Usage: %s filename.html\n", argv[0]);
      return 1;
   }
   beautify_html(argv[1]);
   printf("HTML code beautified successfully!\n");
   return 0;
}

void beautify_html(char* filename) {
   FILE* input = fopen(filename, "r");
   if(input == NULL) {
      printf("Error: Cannot open file %s\n", filename);
      exit(1);
   }

   char buffer[1024];
   int indent_count = 0;
   FILE* output = stdout;

   while(fgets(buffer, sizeof(buffer), input)) {
      for(char* p = buffer; *p; p++) {
         if(*p == '<') {
            fputs("\n", output);
            indent(indent_count, output);
            fputc('<', output);
            if(*(p + 1) == '/') indent_count--;
            else indent_count++;
         }
         fputc(*p, output);
         if(*p == '>') fputs("\n", output);
      }
   }
   fclose(input);
}

void indent(int cnt, FILE* output) {
   for(int i=0; i<cnt; i++) {
      fputs("   ", output);
   }
}