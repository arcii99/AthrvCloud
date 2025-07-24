//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
   char genome1[100], genome2[100], sequence[100];
   int i, j, k=0, m, n, o, p, q, r;
   
   printf("Enter the first genome sequence:\n");
   fgets(genome1, sizeof(genome1), stdin);
   
   printf("Enter the second genome sequence:\n");
   fgets(genome2, sizeof(genome2), stdin);
   
   printf("Combining the two genomes together:\n");
   
   for(i=0; i<strlen(genome1); i++) {
       if(genome1[i] != '\n') {
           sequence[k] = genome1[i];
           k++;
       }
   }
   
   for(j=0; j<strlen(genome2); j++) {
       if(genome2[j] != '\n'){
           sequence[k] = genome2[j];
           k++;
       }
   }

   printf("%s\n", sequence);
   
   printf("Now we will simulate the genome sequencing process:\n\n");
   printf("Oh Romeo, Romeo, wherefore art thou Romeo?!\n");
   printf("Deny thy father and refuse thy name;\n");
   printf("Or, if thou wilt not, be but sworn my love,\n");
   printf("And I'll no longer be a Capulet.\n");

   printf("A Capulet genome reads: %s\n", genome1);
   printf("A Montague genome reads: %s\n", genome2);
   printf("Together they will form a new genome: %s\n", sequence);
   printf("Let's start sequencing this new genome...\n\n");
   
   m = rand() % 50 + 1;
   n = rand() % 50 + 1;
   o = rand() % 50 + 1;
   p = rand() % 50 + 1;
   q = rand() % 50 + 1;
   r = rand() % 50 + 1;
   
   printf("We will randomly select six sections of the genome and sequence them:\n");
   printf("Section 1 of the genome is %d base pairs long.\n", m);
   printf("Section 2 of the genome is %d base pairs long.\n", n);
   printf("Section 3 of the genome is %d base pairs long.\n", o);
   printf("Section 4 of the genome is %d base pairs long.\n", p);
   printf("Section 5 of the genome is %d base pairs long.\n", q);
   printf("Section 6 of the genome is %d base pairs long.\n", r);

   char seq1[m], seq2[n], seq3[o], seq4[p], seq5[q], seq6[r];
   
   for(i=0; i<m; i++) {
       seq1[i] = sequence[i];
   }
   
   for(j=m; j<m+n; j++) {
       seq2[j-m] = sequence[j];
   }
   
   for(k=m+n; k<m+n+o; k++) {
       seq3[k-m-n] = sequence[k];
   }
   
   for(i=m+n+o; i<m+n+o+p; i++) {
       seq4[i-m-n-o] = sequence[i];
   }
   
   for(j=m+n+o+p; j<m+n+o+p+q; j++) {
       seq5[j-m-n-o-p] = sequence[j];
   }
   
   for(k=m+n+o+p+q; k<m+n+o+p+q+r; k++) {
       seq6[k-m-n-o-p-q] = sequence[k];
   }
   
   printf("\nSequencing section 1 of the genome: %s\n", seq1);
   printf("Sequencing section 2 of the genome: %s\n", seq2);
   printf("Sequencing section 3 of the genome: %s\n", seq3);
   printf("Sequencing section 4 of the genome: %s\n", seq4);
   printf("Sequencing section 5 of the genome: %s\n", seq5);
   printf("Sequencing section 6 of the genome: %s\n", seq6);

   printf("\nThus with a kiss I dance into the light,\n");
   printf("But soon enough the darkness falls.\n");
   printf("And now, let's put these sections together...\n");

   char new_sequence[200];
   
   for(i=0; i<m; i++) {
       new_sequence[i] = seq1[i];
   }
   
   for(j=0; j<n; j++) {
       new_sequence[m+j] = seq2[j];
   }
   
   for(k=0; k<o; k++) {
       new_sequence[m+n+k] = seq3[k];
   }
   
   for(i=0; i<p; i++) {
       new_sequence[m+n+o+i] = seq4[i];
   }
   
   for(j=0; j<q; j++) {
       new_sequence[m+n+o+p+j] = seq5[j];
   }
   
   for(k=0; k<r; k++) {
       new_sequence[m+n+o+p+q+k] = seq6[k];
   }
   
   printf("The final genome sequence is: %s\n", new_sequence);

   printf("What's in a name? That which we call a rose\n");
   printf("By any other name would smell as sweet.\n");
   printf("But this genome sequence is unique and special...\n");
   
   return 0;
}