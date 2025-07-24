//FormAI DATASET v1.0 Category: Computer Biology ; Style: bold
#include <stdio.h>

int main() {
  int num1 = 5, num2 = 7;
  int result1 = num1 * num2;
  double num3 = 6.5, num4 = 3.2;
  double result2 = num3 / num4;

  printf("The product of %d and %d is %d\n", num1, num2, result1);
  printf("The quotient of %f and %f is %f\n", num3, num4, result2);

  char dna[] = "ATCGTACGCTAGATCG";
  int length = sizeof(dna) / sizeof(dna[0]);

  printf("The DNA sequence is: ");
  for (int i = 0; i < length; i++) {
    printf("%c", dna[i]);
  }
  printf("\n");

  int countA = 0, countC = 0, countG = 0, countT = 0;

  for (int i = 0; i < length; i++) {
    if (dna[i] == 'A') {
      countA++;
    } else if (dna[i] == 'C') {
      countC++;
    } else if (dna[i] == 'G') {
      countG++;
    } else if (dna[i] == 'T') {
      countT++;
    }
  }

  printf("Number of A's in the DNA sequence: %d\n", countA);
  printf("Number of C's in the DNA sequence: %d\n", countC);
  printf("Number of G's in the DNA sequence: %d\n", countG);
  printf("Number of T's in the DNA sequence: %d\n", countT);

  return 0;
}