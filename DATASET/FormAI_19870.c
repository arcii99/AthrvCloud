//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[100];
  int i, j, k, n, m;

  printf("Enter the Alien Language Code:\n");

  fgets(input, 100, stdin);
  n = strlen(input);

  for(i = 0; i < n; i++) {
    if(input[i] == 'K') {
      printf("Hello");
    } else if(input[i] == 'Z') {
      printf("How are you");
    } else if(input[i] == 'P') {
      printf("What is your name");
    } else if(input[i] == 'X') {
      printf("I am a friend");
    } else if(input[i] == 'R') {
      printf("Goodbye");
    } else if(input[i] == 'D') {
      printf("Thank you");
    } else if(input[i] == 'M') {
      printf("Please");
    } else if(input[i] == 'L') {
      printf("Sorry");
    } else if(input[i] == 'A') {
      printf("Yes");
    } else if(input[i] == 'B') {
      printf("No");
    } else {
      printf("%c", input[i]);
    }
  }
  return 0;
}