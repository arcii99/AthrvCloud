//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/* 
   Genome Sequencing Simulator
   The program simulates the process of genome sequencing, which is the process of determining
   the order of nucleotides in a DNA molecule.
*/

int main(){

   /* The genome sequence to be simulated */
   char genome[] = "ATCGATCGATCGTACGCTAGCTAGCTAGCTAGCTAGCGTAGCTAGCTAGCTAGCTAGCTAGCGTAGCTAGCTAGCTAGC";

   /* The length of the genome */
   int genome_length = strlen(genome);

   /* The minimum and maximum length of the reads */
   int min_read_length = 10;
   int max_read_length = 20;

   /* The number of reads to be generated */
   int num_reads = 100;

   /* The probability that a base is incorrectly read */
   float base_error_probability = 0.01;

   /* The seed for the random number generator */
   srand(time(NULL));

   /* The output file */
   FILE* output_file = fopen("genomic_reads.txt", "w");

   /* Generate the reads */
   for(int i = 0; i < num_reads; i++){

      /* Generate a random starting position for the read */
      int start_pos = rand() % (genome_length - min_read_length);

      /* Generate a random length for the read */
      int read_length = min_read_length + (rand() % (max_read_length - min_read_length));

      /* Copy the read from the genome */
      char* read = malloc((read_length + 1) * sizeof(char));
      strncpy(read, genome + start_pos, read_length);
      read[read_length] = '\0';

      /* Introduce errors into the read */
      for(int j = 0; j < read_length; j++){
         float error_prob = ((float) rand()) / RAND_MAX;
         if(error_prob < base_error_probability){
            char wrong_base = genome[start_pos + j];
            do{
               wrong_base = "ATCG"[rand() % 4];
            }while(wrong_base == genome[start_pos + j]);
            read[j] = wrong_base;
         }
      }

      /* Write the read to the output file */
      fprintf(output_file, ">Read%d\n%s\n", i+1, read);

      /* Free the read memory */
      free(read);
   }

   /* Close the output file */
   fclose(output_file);

   return 0;
}