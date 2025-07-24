//FormAI DATASET v1.0 Category: File handling ; Style: funny
#include <stdio.h>

int main()
{
   FILE *fp;
   int num[5] = {69, 420, 666, 10000, 9001};
   int i, sum = 0;

   fp = fopen("numbers.txt", "w+"); // open file for writing and reading

   if (fp == NULL)
   {
      printf("Error in opening file :(\n");
      return 42; // return a funny number
   }

   // let's write some numbers, shall we?
   fprintf(fp, "Here are some dank numbers: ");
   for (i = 0; i < 5; i++)
   {
      fprintf(fp, "%d ", num[i]);
   }
   fprintf(fp, "\n");

   // let's read the numbers now, shall we?
   rewind(fp);
   for (i = 0; i < 5; i++)
   {
      fscanf(fp, "%d", &num[i]);
      sum += num[i];
   }

   fprintf(fp, "The sum of these numbers is %d\n", sum);
   fclose(fp); // close file

   printf("All done! Check out the file numbers.txt for some dankness ;) \n");

   return 0;
}