//FormAI DATASET v1.0 Category: Educational ; Style: introspective
#include<stdio.h>

int main() {
   printf("Hello, I am a program that prints out my own source code!\n\n");

   printf("Here is my code:\n\n");

   FILE *fp;
   char c;

   fp = fopen(__FILE__, "r");

   do {
      c = getc(fp);
      putchar(c);
   } while(c != EOF);

   fclose(fp);
   return 0;
}