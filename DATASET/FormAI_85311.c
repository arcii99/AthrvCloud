//FormAI DATASET v1.0 Category: Data recovery tool ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   printf("Oh no! All my data is gone!\n");
   printf("But don't worry, I've got this!\n");

   char filename[50];
   printf("Enter the name of the file you want to recover: ");
   scanf("%s", filename);

   FILE *fp = fopen(filename, "rb");
   if (fp == NULL) {
      printf("Oops! I couldn't find that file.\n");
      printf("Please make sure you typed the name correctly or try another file name.\n");
      return 1;
   }

   fseek(fp, 0, SEEK_END);
   long file_size = ftell(fp);
   fseek(fp, 0, SEEK_SET);

   char *data = malloc(file_size + 1);
   if (data == NULL) {
      printf("Uh-oh! I couldn't allocate enough memory to recover that file.\n");
      printf("Please try freeing up some memory or try another file.\n");
      fclose(fp);
      return 1;
   }

   size_t num_read = fread(data, 1, file_size, fp);
   if (num_read != file_size) {
      printf("Hmmm...there seems to be an issue reading that file.\n");
      printf("Please try another file or contact technical support.\n");
      free(data);
      fclose(fp);
      return 1;
   }

   printf("Phew! I found your data and it looks like it's fully intact!\n");
   printf("%s", data);

   free(data);
   fclose(fp);
   return 0;
}