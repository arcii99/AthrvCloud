//FormAI DATASET v1.0 Category: File Encyptor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main() {
   char filename[100], ch;
   FILE *fpIn, *fpOut;

   // get filename from user
   printf("Enter name of file to encrypt : ");
   scanf("%s", filename);

   // open input file
   fpIn = fopen(filename, "r");
   if (fpIn == NULL) {
      printf("Cannot open file, please check if the file exists.\n");
      exit(0);
   }

   // create output file
   strcat(filename, ".enc");
   fpOut = fopen(filename, "w");
   if (fpOut == NULL) {
      printf("Cannot create output file.\n");
      exit(0);
   }

   // encryption key
   int key = 4;

   // read input file character by character and write encrypted characters to output file
   while ((ch = fgetc(fpIn)) != EOF) {
      ch = ch + key;
      fputc(ch, fpOut);
   }

   // close the files
   fclose(fpIn);
   fclose(fpOut);

   printf("Encryption successful.\n");
   return 0;
}