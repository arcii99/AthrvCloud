//FormAI DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *fp;
   int num[5] = {10, 20, 30, 40, 50};
   int i;

   fp = fopen("numbers.txt", "w+"); //opening the file in write mode, "+" opens for both reading and writing

   for(i = 0; i < 5; i++) {
      fprintf(fp, "%d\n", num[i]); //writing numbers in the file
   }

   rewind(fp); //resetting file pointer back to the beginning of the file

   int read_num[5];
   i = 0;

   while(fscanf(fp, "%d", &read_num[i]) != EOF) { //reading the numbers and storing them in the array
      i++;
   }

   printf("Numbers in the file: ");

   for(i = 0; i < 5; i++) {
      printf("%d ", read_num[i]); //printing the numbers from the array
   }

   fclose(fp);

   return 0;
}