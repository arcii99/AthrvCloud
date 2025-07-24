//FormAI DATASET v1.0 Category: Recursive ; Style: cheerful
#include <stdio.h>

void recursive_function(int n) 
{
  if (n <= 0) 
  {
    printf("It's party time! 🎉🎉🎉\n");
    return;
  } 
  else 
  {
    printf("%d little monkeys jumping on the bed 🐒🐒🐒\n", n);
    printf("One fell off and bumped his head 😱😱😱\n");
    recursive_function(n-1);
  }
}

int main() 
{
  int num_monkeys = 10;
  printf("Let's sing a song about %d little monkeys! 🎶🐵🎶🐵🎶\n", num_monkeys);
  recursive_function(num_monkeys);
  return 0;
}