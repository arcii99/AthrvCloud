//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: funny
#include <stdio.h>

int main() {
  int sun, mercury, venus, earth, mars, jupiter, saturn, uranus, neptune;

  printf("Welcome to the wacky world of the solar system simulator!\n");
  printf("Get ready to blast off on a wild ride to the edges of the universe!\n");

  sun = 1;
  mercury = 2;
  venus = 3;
  earth = 4;
  mars = 5;
  jupiter = 6;
  saturn = 7;
  uranus = 8;
  neptune = 9;

  printf("\n\nHere are the planets in our solar system:\n");
  printf("1. SUN\n");
  printf("2. Mercury\n");
  printf("3. Venus\n");
  printf("4. Earth\n");
  printf("5. Mars\n");
  printf("6. Jupiter\n");
  printf("7. Saturn\n");
  printf("8. Uranus\n");
  printf("9. Neptune\n\n");

  printf("Where would you like to go? Input the planet number from the above list: ");
  scanf("%d", &earth);
  
  while (earth != 4) {
    printf("\nSorry, you can only visit Earth for now. Try again later!\n");
    printf("Where would you like to go? Input the planet number from the above list: ");
    scanf("%d", &earth);
  }

  printf("\n\nWelcome to Earth! This is where all the cool kids hang out.\n");
  printf("Check out the blue skies, the green grass, and the cute animals. Woo hoo!\n");

  printf("\n\nThanks for visiting! See you soon on our wacky journey through the universe!\n");

  return 0;
}