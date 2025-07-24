//FormAI DATASET v1.0 Category: Computer Biology ; Style: cheerful
#include <stdio.h>

int main() {
  int dna[100];
  int i, j;
  
  // Populate the DNA array randomly with 0's and 1's
  srand(time(NULL));
  for (i = 0; i < 100; i++) {
    dna[i] = rand() % 2;
  }
  
  // Print out the DNA sequence
  printf("The DNA sequence is: ");
  for (i = 0; i < 100; i++) {
    printf("%d", dna[i]);
  }
  
  // Check for mutations
  int num_mutations = 0;
  for (i = 1; i < 100; i++) {
    if (dna[i] != dna[i-1]) {
      num_mutations++;
    }
  }
  
  // Print out the number of mutations
  if (num_mutations == 0) {
    printf("\nThere are no mutations in this DNA sequence! :D\n");
  } else {
    printf("\nThere are %d mutations in this DNA sequence! :( \n", num_mutations);
  }
  
  // Display a cheerful message
  printf("\nThanks for checking out this DNA sequence! Have a great day! :)\n");
  
  return 0;
}