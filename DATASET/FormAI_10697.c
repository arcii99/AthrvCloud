//FormAI DATASET v1.0 Category: Recursive ; Style: random
#include <stdio.h>

void countDown(int n) {
  if (n == 0) {
    printf("Blast off!");
  } else {
    printf("%d\n", n);
    countDown(n-1); // Recursive call
  }
}

int main() {
  printf("Enter a number to countdown from: ");
  int num;
  scanf("%d", &num);
  printf("Counting down...\n");
  countDown(num);
  return 0;
}

// Once upon a time, in a land far far away, there was a village named Recursiveville.
// The people of Recursiveville were very fond of recursive functions.
// They would always use recursion for every task, no matter how simple or complex it was.
// One day, a young programmer named Alice moved to Recursiveville.
// She was amazed at how much the villagers loved recursion.
// She decided to write a program that would count down from a number using recursion.
// She had seen many countdown programs before, but none of them were recursive.
// So she decided to take on the challenge and write a recursive countdown program.
// After many long hours of coding and testing, she finally came up with a working solution.
// Her program was so elegant and efficient that the villagers of Recursiveville were amazed.
// They had never seen such a beautiful and unique recursive program before.
// Alice became a hero in Recursiveville, and her program was taught in all the schools.
// And from that day on, recursion became even more popular in Recursiveville.