//FormAI DATASET v1.0 Category: Computer Biology ; Style: bold
#include <stdio.h>

/* This program calculates the GC content of a DNA sequence */

int main()
{
   char dna[] = "ATCGCCGATAAGCGGGCGATCGATCGCTGACTGACTAGGCTCAGGGCTAGCTAGC";
   int i, count_c = 0, count_g = 0;

   for (i=0; dna[i]!='\0'; i++)
   {
      if (dna[i] == 'C')
         count_c++;
      else if (dna[i] == 'G')
         count_g++;
   }

   float gc_content = ((float) count_c + count_g) / i * 100;

   printf("The GC content of the DNA sequence: %.2f%%\n", gc_content);

   return 0;
}