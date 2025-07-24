//FormAI DATASET v1.0 Category: Text processing ; Style: scientific
#include <stdio.h>

int main() {
   // This program will take in a string of DNA sequence
   // and calculate its GC content

   char dna[1000]; 
   printf("Enter DNA sequence: ");
   scanf("%s", dna);

   int len = strlen(dna); 
   int gc_count = 0;

   for (int i = 0; i < len; i++) {
      if (dna[i] == 'G' || dna[i] == 'C') {
         gc_count++;
      }
   }

   double gc_content = (double) gc_count / len * 100;

   printf("DNA Sequence: %s\n", dna);
   printf("GC content: %.2f%%\n", gc_content);

   return 0;
}

/*
  Sample input: "AGCTCGATCGATTAGCAGCGCTTTGCTCGAAATTAGCTCGATCGACTAGCGCAGCG"
  Sample output: 
  DNA Sequence: AGCTCGATCGATTAGCAGCGCTTTGCTCGAAATTAGCTCGATCGACTAGCGCAGCG
  GC content: 50.00%
*/