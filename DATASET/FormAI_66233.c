//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the romantic space adventure game!\n");

  char name[20];
  printf("What is your name, dear traveler?\n");
  scanf("%s", name);
  printf("Nice to meet you, %s!\n", name);

  printf("You are about to embark on a journey to explore the unknown depths of space!\n");
  printf("As you set off in your spaceship, you activate your hyperdrive and travel through a wormhole.\n");

  int choice;
  printf("You emerge in front of two stars. Which one do you wish to visit?\n");
  printf("1. The pink star\n");
  printf("2. The blue star\n");
  scanf("%d", &choice);

  if (choice == 1) {
    printf("The pink star is beautiful and tranquil, but as you land your ship, you notice that the planet is deserted.\n");
    printf("You wander around for hours but find no signs of life until you come across a message etched into a rock: 'There is no life here, but you are not alone.'\n");
  }
  else if (choice == 2) {
    printf("The blue star is lively and filled with creatures of all shapes and sizes.\n");
    printf("As you explore the planet, you come across a group of aliens that invite you to their feast.\n");
    printf("You sit down to eat, and as you take a bite of a strange-looking fruit, you are transported into a dream-like state where you see visions of love and romance.\n");
  }
  else {
    printf("Invalid choice! Please try again.\n");
    return 1;
  }

  printf("You continue your journey through space, wondering what other adventures await you.\n");
  printf("Thank you for playing the romantic space adventure game!\n");

  return 0;
}