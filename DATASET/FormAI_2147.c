//FormAI DATASET v1.0 Category: Ebook reader ; Style: invasive
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void loadEbook(char* filePath) {
   FILE* ebook = fopen(filePath, "r");
   if (ebook == NULL) {
      printf("Error: Cannot open file.");
   } else {
      char line[100];
      while (fgets(line, sizeof(line), ebook)) {
         printf("%s", line);
      }
      fclose(ebook);
   }
}

int main() {
   char ebookPath[100];
   printf("Enter the filepath of the Ebook: ");
   fgets(ebookPath, sizeof(ebookPath), stdin);
   ebookPath[strcspn(ebookPath, "\n")] = 0;
   loadEbook(ebookPath);
   return 0;
}