//FormAI DATASET v1.0 Category: File handling ; Style: imaginative
#include <stdio.h>

int main() {
   FILE *fp;
   char str[60];

   /* Opening file for writing */
   fp = fopen("myfile.txt", "w");

   if (fp == NULL) {
      printf("Error opening file\n");
      return 1;
   }

   /* Writing to the file */
   fprintf(fp, "Once upon a midnight dreary, while I pondered, weak and\n");
   fprintf(fp, "weary,\nOver many a quaint and curious volume of forgotten\n");
   fprintf(fp, "lore—\nWhile I nodded, nearly napping, suddenly there came\n");
   fprintf(fp, "a tapping,\nAs of some one gently rapping, rapping at my\n");
   fprintf(fp, "chamber door.\n\"’Tis some visitor,\" I muttered, \"tapping at my\n");
   fprintf(fp, "chamber door—\nOnly this and nothing more.\"\n");

   /* Closing the file */
   fclose(fp);

   /* Opening file for reading */
   fp = fopen("myfile.txt", "r");

   if (fp == NULL) {
      printf("Error opening file\n");
      return 1;
   }

   /* Reading from the file */
   while (fgets(str, 60, fp) != NULL)
      printf("%s", str);

   /* Closing the file */
   fclose(fp);

   return 0;
}