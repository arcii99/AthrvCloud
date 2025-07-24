//FormAI DATASET v1.0 Category: Computer Biology ; Style: enthusiastic
#include <stdio.h>

int main() {
  printf("Welcome to the DNA Sequencer!\n");
  printf("Please enter your DNA sequence: ");

  // Limiting the sequence to 50 characters
  char sequence[50];
  scanf("%s", sequence);

  printf("Your sequence is: %s\n", sequence);

  // Determining the length of the sequence
  int length = 0;
  while (sequence[length] != '\0') {
    length++;
  }

  printf("The length of your sequence is: %d\n", length);

  // Determining the composition of the sequence
  int a_count = 0;
  int c_count = 0;
  int g_count = 0;
  int t_count = 0;
  for (int i = 0; i < length; i++) {
    if (sequence[i] == 'A' || sequence[i] == 'a') {
      a_count++;
    } else if (sequence[i] == 'C' || sequence[i] == 'c') {
      c_count++;
    } else if (sequence[i] == 'G' || sequence[i] == 'g') {
      g_count++;
    } else if (sequence[i] == 'T' || sequence[i] == 't') {
      t_count++;
    }
  }

  printf("The composition of your sequence is:\n");
  printf("A: %d\n", a_count);
  printf("C: %d\n", c_count);
  printf("G: %d\n", g_count);
  printf("T: %d\n", t_count);

  return 0;
}