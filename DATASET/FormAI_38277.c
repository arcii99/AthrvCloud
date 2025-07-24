//FormAI DATASET v1.0 Category: Image Editor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main()
{
   FILE *fp1, *fp2;
   int ch;
   char file_name[25], new_file_name[25];

   printf("Enter the name of the image file to edit: ");
   gets(file_name);

   fp1 = fopen(file_name, "rb");

   if (fp1 == NULL)
   {
      printf("Error opening file");
      exit(1);
   }

   printf("Enter the name of the new file: ");
   gets(new_file_name);

   fp2 = fopen(new_file_name, "wb");

   if (fp1 == NULL)
   {
      printf("Error opening file");
      exit(1);
   }

   while(1)
   {
      ch = fgetc(fp1);
      if (ch == EOF) break;

      // edit the image here
      ch = ch+50;

      fputc(ch, fp2);
   }

   fclose(fp1);
   fclose(fp2);

   printf("Image edited successfully.\n");

   return 0;
}