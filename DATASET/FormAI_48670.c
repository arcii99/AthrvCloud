//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int choice = 0;
  int key = rand() % 3 + 1; // randomly generate a key between 1 and 3
  int attempts = 3;
  printf("You have arrived at a haunted house, do you dare enter?\n");
  printf("1) Yes\n");
  printf("2) No\n");
  scanf("%d", &choice);
  if (choice == 2) {
    printf("You turn around and leave the haunted house.\n");
    return 0;
  }
  printf("You enter the haunted house and find a door with a lock.\n");
  while (attempts > 0) {
    printf("There seems to be some strange symbols on the wall. Which one do you choose?\n");
    printf("1) ☠️\n");
    printf("2) 🔮\n");
    printf("3) 🕯️\n");
    printf("You have %d attempts left.\n", attempts);
    scanf("%d", &choice);
    if (choice == key) {
      printf("The lock clicks open and the door creaks open. As you enter the next room, you hear a strange noise...\n");
      printf("You turn to leave but the door slams shut and you hear a sinister laugh...\n");
      printf("You are trapped in the haunted house. Be careful and try to find a way out.\n");
      break;
    } else {
      printf("The symbol does not match the key. The lock remains locked.\n");
      attempts--;
    }
  }
  if (attempts == 0) {
    printf("You have failed to open the lock and the haunted house consumes you. GAME OVER.\n");
    return 0;
  }
  // continue the simulation with more rooms and spooky situations  
  return 0;
}