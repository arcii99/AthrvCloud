//FormAI DATASET v1.0 Category: File handling ; Style: enthusiastic
#include <stdio.h>

int main() {
   FILE *fp;

   fp = fopen("example.txt", "w+");
   fprintf(fp, "Let's write some cool stuff in a file!\n");
   fputs("I am so excited to learn file handling in C.\n", fp);

   fseek(fp, 0, SEEK_SET);

   char buffer[255];
   while (fgets(buffer, 255, fp)) {
      printf("%s", buffer);
   }

   fclose(fp);
   return 0;
}