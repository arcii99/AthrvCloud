//FormAI DATASET v1.0 Category: Ebook reader ; Style: mathematical
#include <stdio.h>

int main() {
   FILE *fp;
   char str[1000];

   fp = fopen("myfile.txt", "r");
   if (fp == NULL){
       printf("Error opening file\n");
       return 0;
    }

   while (fgets(str, 1000, fp) != NULL)
       printf("%s", str);

   fclose(fp);
   return 0;
}