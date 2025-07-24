//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* theories[] = {
  "The moon landing was faked!",
  "Chemtrails are controlling our thoughts!",
  "The earth is hollow and filled with lizard people!",
  "The government is hiding the cure for cancer!",
  "The Illuminati are pulling the strings behind the scenes!",
  "The world will end in 2020!",
  "Aliens are among us and have been for centuries!",
};

void generate_theory(int num_theories) {
  if (num_theories == 0) {
    return;
  }

  int theory_index = rand() % (sizeof(theories) / sizeof(char*));
  printf("%s\n", theories[theory_index]);

  generate_theory(num_theories - 1);
}

int main() {
  srand(time(NULL));

  printf("Welcome to the Random Conspiracy Theory Generator!\n\n");
  printf("How many theories would you like to generate? ");
  int num_theories;
  scanf("%d", &num_theories);

  printf("\nGenerating theories...\n");

  generate_theory(num_theories);

  return 0;
}