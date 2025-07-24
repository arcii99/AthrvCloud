//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
  int n, i, t1 = 0, t2 = 1, nextTerm;
  
  printf("O Romeo, what number of terms shall I visualize for thee in Fibonacci's sequence?\n");
  printf("Enter the number of terms: ");
  scanf("%d", &n);
  
  printf("Ah, fair enough, I shall display the first %d terms of the sequence:\n", n);
  
  for (i = 1; i <= n; ++i) {
      if (i == 1) {
          printf("Two households, both alike in dignity,\nIn fair Verona, where we lay our scene.\n");
          printf("First two terms of Fibonacci sequence are: %d, %d\n", t1, t2);
          printf("From ancient grudge break to new mutiny,\nWhere civil blood makes civil hands unclean.\n");
          continue;
      }
      nextTerm = t1 + t2;
      t1 = t2;
      t2 = nextTerm;
      
      printf("Now old desire doth in his death-bed lie,\nAnd young affection gapes to be his heir.\n");
      printf("Term %d: %d\n", i, nextTerm);
      printf("My lips, two blushing pilgrims, ready stand\nTo smooth that rough touch with a tender kiss.\n");
  }
  
  printf("Good night, good night! Parting is such sweet sorrow,\nThat I shall say good night till it be morrow.\n");
  return 0;
}