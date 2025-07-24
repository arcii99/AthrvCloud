//FormAI DATASET v1.0 Category: Syntax parsing ; Style: post-apocalyptic
#include <stdio.h>

int main() {

  printf("Welcome, wanderer.\n");
  printf("Are you familiar with C Syntax? It's a powerful language that can help you survive in this post-apocalyptic world.\n");
  
  char code[1000];
  printf("Enter your code:\n");
  fgets(code, 1000, stdin);

  if (strstr(code, "for")) {
    printf("Ah, a for loop. Excellent choice for iterating through arrays of scarce resources.\n");
  } else if (strstr(code, "if")) {
    printf("An if statement, good for making decisions in this harsh environment.\n");
  } else if (strstr(code, "while")) {
    printf("A while loop, perfect for executing tasks until they're complete, just like searching for food or water.\n");
  } else {
    printf("I'm sorry, I don't recognize that syntax. Are you sure you know C?\n");
  }

  return 0;
}