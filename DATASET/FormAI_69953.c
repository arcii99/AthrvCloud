//FormAI DATASET v1.0 Category: Syntax parsing ; Style: medieval
#include <stdio.h>

int main() {
  char quest[] = "What is your name?";
  char name[50];
  int age;
  char sword[20];
  int sword_length;

  printf("Hark, wayfarer! I inquirest of thee:\n");
  printf("%s ", quest);
  scanf("%s", name);

  printf("Verily, what is thy age?\n");
  scanf("%d", &age);

  if (age < 21) {
    printf("I dare not give a sword to one so young. Begone!\n");
    return 0;
  }

  printf("Now, choose thy weapon of choice. What sayest thou? (Shortsword/Longsword)?\n");
  scanf("%s", sword);

  if (strcmp(sword, "Shortsword") == 0) {
    sword_length = 30;
  } else if (strcmp(sword, "Longsword") == 0) {
    sword_length = 50;
  } else {
    printf("Thou dost not followest directions. Take your leave!\n");
    return 0;
  }

  printf("The length of thy sword is %d inches. Hail!\n", sword_length);

  return 0;
}