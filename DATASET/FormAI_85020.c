//FormAI DATASET v1.0 Category: Computer Biology ; Style: happy
#include <stdio.h>

int main() {
  int age = 25;
  float height = 1.75;
  char name[] = "Alex";
  char grad_year[] = "2022";

  printf("Hello! My name is %s and I am %d years old.\n", name, age);
  printf("I am %.2f meters tall.\n", height);
  printf("I will be graduating from college in %s.\n", grad_year);

  printf("\nNow, let's talk about biology!\n\n");

  printf("Did you know that human blood is made up of four main components: red blood cells, white blood cells, platelets, and plasma?\n");
  printf("Let me show you how to count the number of these cells in a blood sample.\n");

  int red_blood_cells = 5000000000;
  int white_blood_cells = 7000;
  int platelets = 250000;
  float plasma = 55.0;

  printf("In this blood sample, there are %d red blood cells.\n", red_blood_cells);
  printf("And there are %d white blood cells and %d platelets.\n", white_blood_cells, platelets);
  printf("The plasma makes up %.1f percent of the blood volume.\n", plasma);

  printf("\nNow, let's talk about DNA!\n\n");

  char dna_sequence[] = "ATGCCCGTAACTGAGCCGCGTTTAGACACTG";
  int base_count = 0;
  int a_count = 0;
  int t_count = 0;
  int c_count = 0;
  int g_count = 0;

  for(int i = 0; i < sizeof(dna_sequence); i++) {
    if(dna_sequence[i] == 'A') {
      a_count++;
      base_count++;
    } else if(dna_sequence[i] == 'T') {
      t_count++;
      base_count++;
    } else if(dna_sequence[i] == 'C') {
      c_count++;
      base_count++;
    } else if(dna_sequence[i] == 'G') {
      g_count++;
      base_count++;
    }
  }

  printf("Here is the DNA sequence: %s\n", dna_sequence);
  printf("The total number of bases in this sequence is: %d\n", base_count);
  printf("The number of A bases is: %d\n", a_count);
  printf("The number of T bases is: %d\n", t_count);
  printf("The number of C bases is: %d\n", c_count);
  printf("The number of G bases is: %d\n", g_count);

  return 0;
}