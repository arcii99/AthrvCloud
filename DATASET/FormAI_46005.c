//FormAI DATASET v1.0 Category: Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void surreal_game() {
  int x, y, choice;
  srand(time(NULL));
  x = rand()%10 + 1;
  y = rand()%10 + 1;
  printf("Welcome to the Surrealist Game!\n");
  printf("Choose a number between 1-10 and see what surreal thing happens to you..\n");
  scanf("%d", &choice);
  printf("You have chosen %d\n", choice);
  if(choice == x) {
    printf("Congratulations! You have won a trip to the giant floating fish in the sky!\n");
  } else if(choice == y) {
    printf("Oh no, you have been transported to a world where everything is made of broccoli!\n");
  } else if(choice % 2 == 0) {
    printf("You have shrunk to the size of a pencil lead and are currently sitting on the head of a giant cat!\n");
  } else {
    printf("You are now running through a field of rainbow-colored jellybeans, chasing a talking squirrel!\n");
  }
}

int main() {
  surreal_game();
  return 0;
}