//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
  srand(time(NULL));
  char words[10][20] = {
    "mystify",
    "luminous",
    "sesquipedalian",
    "juxtaposition",
    "onomatopoeia",
    "supercalifragilisticexpialidocious",
    "antidisestablishmentarianism",
    "pneumonoultramicroscopicsilicovolcanoconiosis",
    "floccinaucinihilipilification",
    "hippopotomonstrosesquipedaliophobia"
  };
  
  int i, j, correct = 0, incorrect = 0;
  
  printf("Welcome to the Typing Speed Test!\n\n");
  printf("Type the word as fast as you can and hit enter!\n\n");

  for (i = 0; i < 10; i++) {
    printf("%s\n", words[i]);
    clock_t start = clock();
    char input[20];
    scanf("%s", input);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    if (strcmp(input, words[i]) == 0) {
      correct++;
      printf("Correct! Time taken: %lf seconds\n", time_spent);
    } else {  
      incorrect++;
      printf("Incorrect. Time taken: %lf seconds\n", time_spent);
    }
    printf("\n");
  }
  
  printf("Typing test complete!\n");
  printf("You got %d words correct and %d words incorrect.\n", correct, incorrect);
  return 0;
}