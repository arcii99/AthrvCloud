//FormAI DATASET v1.0 Category: Funny ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char joke[50];
  printf("Hey there, I'm the Funniest C Program you'll ever see!\n");

  printf("\nLet's start with a joke! Why don’t scientists trust atoms?\n");
  printf("Because they make up everything!\n");

  printf("\nNow it's my turn to tell a joke! Type in your favorite joke below:\n");
  fgets(joke, sizeof(joke), stdin);
  char *p = strchr(joke, '\n');
  if (p) {
    *p = '\0';
  }
  
  printf("\nHaha! That was hilarious! Okay, now let's get to some C programming!\n");

  printf("\nGive me two numbers, and I'll add them up for you!\n");
  int num1, num2;
  scanf("%d %d", &num1, &num2);
  printf("\nAdding %d and %d...\n", num1, num2);
  printf("The answer is: %d\n", num1 + num2);

  printf("\nAlright, let's try something else!\n");
  printf("Give me a sentence, and I'll print it backwards!\n");
  char sentence[100];
  scanf(" %[^\n]s", sentence);
  printf("\nReversing sentence \"%s\"...\n", sentence);
  for(int i = strlen(sentence)-1; i >= 0; i--){
      printf("%c", sentence[i]);
  }
  printf("\n");

  printf("\nI hope you had fun! That's all for me today folks!\n");

  return 0;
}