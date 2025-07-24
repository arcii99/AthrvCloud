//FormAI DATASET v1.0 Category: Computer Biology ; Style: innovative
#include <stdio.h>

int main() {
   char DNA_seq[100];
   printf("Enter DNA sequence of length 100: ");
   scanf("%s", DNA_seq);

   int A_count = 0, T_count = 0, C_count = 0, G_count = 0;
   for (int i = 0; i < 100; i++) {
      if (DNA_seq[i] == 'A')
         A_count++;
      else if (DNA_seq[i] == 'T')
         T_count++;
      else if (DNA_seq[i] == 'C')
         C_count++;
      else if (DNA_seq[i] == 'G')
         G_count++;
   }

   printf("The frequency of Adenine (A) in the DNA sequence is %d\n", A_count);
   printf("The frequency of Thymine (T) in the DNA sequence is %d\n", T_count);
   printf("The frequency of Cytosine (C) in the DNA sequence is %d\n", C_count);
   printf("The frequency of Guanine (G) in the DNA sequence is %d\n", G_count);

   return 0;
}