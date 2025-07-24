//FormAI DATASET v1.0 Category: HTML beautifier ; Style: secure
#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *fp;
   int indent = 0;
   char c, prev = '\0';
   int block_comment = 0;
   int line_comment = 0;
   int quot = 0;

   fp = fopen("input.html", "r");
   if (fp == NULL) {
      printf("Error opening file\n");
      exit(1);
   }

   while ((c = fgetc(fp)) != EOF) {
      if (line_comment) {
         if (c == '\n') {
            printf("%c", c);
            line_comment = 0;
            continue;
         }
         else {
            continue;
         }
      }
      if (block_comment) {
         if (prev == '*' && c == '/') {
            block_comment = 0;
            printf("*/");
            continue;
         }
         else {
            printf("%c", c);
            prev = c;
            continue;
         }
      }
      if (quot) {
         printf("%c", c);
         if (prev == '\\' && c == quot) {
            prev = c;
            continue;
         }
         if (c == quot) {
            quot = 0;
            prev = c;
            continue;
         }
         prev = c;
         continue;
      }
      switch (c) {
         case '<':
            indent++;
            printf("%c\n", c);
            for (int i = 0; i < indent; i++) { printf("\t"); }
            break;
         case '>':
            printf("%c\n", c);
            prev = c;
            continue;
         case '/':
            if (prev == '<') {
               printf("%c", c);
               break;
            }
            else {
               printf("%c\n", c);
               for (int i = 0; i < indent; i++) { printf("\t"); }
               break;
            }
         case '!':
            if (prev == '<') {
               printf("%c", c);
               break;
            }
            else {
               printf("%c\n", c);
               for (int i = 0; i < indent; i++) { printf("\t"); }
               break;
            }
         case '-':
            if (prev == '<') {
               if (getc(fp) == '-') {
                  line_comment = 1;
                  printf("<!--");
                  break;
               }
               else {
                  printf("%c", c);
                  printf("%c", prev);
                  break;
               }
            }
            else {
               printf("%c", c);
               break;
            }
         case '*':
            if (prev == '/') {
               block_comment = 1;
               printf("/*");
               break;
            }
            else {
               printf("%c", c);
               break;
            }
         case '\'':
            quot = '\'';
            printf("%c", c);
            break;
         case '"':
            quot = '"';
            printf("%c", c);
            break;
         case '\n':
            printf("\n");
            for (int i = 0; i < indent; i++) { printf("\t"); }
            break;
         default:
            printf("%c", c);
            break;
      }
      prev = c;
   }

   fclose(fp);
   return 0;
}