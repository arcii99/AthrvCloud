//FormAI DATASET v1.0 Category: Error handling ; Style: Ada Lovelace
#include <stdio.h>
#include <errno.h>
#include <string.h>

// Define an error handler function
void err_handler(int errno_val)
{
   if(errno_val == EACCES)
   {
      printf("You do not have permission to open this file\n");
   }
   else if(errno_val == ENOENT)
   {
      printf("The file you are trying to open does not exist\n");
   }
   else
   {
      printf("An error occurred with error no: %d\n", errno_val);
   }
}

int main()
{
   FILE* fp = fopen("example.txt", "r");

   if (fp == NULL)
   {
      err_handler(errno); // Call the error handler function
      return 1;
   }

   // Do something with the file
   char buf[100];
   while (fgets(buf, 100, fp) != NULL)
   {
      printf("%s", buf);
   }

   fclose(fp);
   return 0;
}