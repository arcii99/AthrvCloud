//FormAI DATASET v1.0 Category: Error handling ; Style: shocked
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
   FILE *f;
   char filename[50] = "nonexistent.txt";
   errno = 0; // ensure errno is cleared before using

   f = fopen(filename, "r");
   if (f == NULL) {
       printf("Error opening file %s: %s\n", filename, strerror(errno));
       return(errno);
   }
   // Do something with the file
   fclose(f);
   return 0;
}