//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printIntro() {
  printf("Welcome to Space Adventure!\n");
  printf("In this game, you will embark on a mission to explore the galaxy and discover new planets!\n");
}

void choosePlanet(int *planetCode) {
  printf("There are five planets that you could land on:\n");
  printf("1. Zorba\n");
  printf("2. Vega\n");
  printf("3. Orion\n");
  printf("4. Rigel\n");
  printf("5. Bellatrix\n");
  printf("Which planet would you like to land on? (enter a number from 1 to 5): ");
  scanf("%d", planetCode);
}

void explorePlanet(int planetCode) {
  printf("\n\nExploring planet ");
  switch(planetCode) {
    case 1:
      printf("Zorba\n");
      break;
    case 2:
      printf("Vega\n");
      break;
    case 3:
      printf("Orion\n");
      break;
    case 4:
      printf("Rigel\n");
      break;
    case 5:
      printf("Bellatrix\n");
      break;
    default:
      printf("Unknown planet (error)\n");
      return;
  }
  printf("-----------------------------\n\n");

  // simulate exploration of planet
  printf("You land on the planet and step outside your ship. The air is fresh and the sky is a vibrant shade of purple.\n");
  printf("As you start to explore, you notice strange creatures lurking around every corner. You pull out your laser gun to defend yourself.\n");
  printf("You find ancient ruins and artifacts that reveal the secrets of this long-forgotten civilization.\n");
  printf("You also collect samples of the flora and fauna to bring back to Earth for further analysis.\n");
  printf("After spending several hours on the planet, you return to your ship feeling accomplished and eager to explore more.\n\n\n");

}

void printOutro() {
  printf("-----------------------------\n\n");
  printf("Thanks for playing Space Adventure!\n");
  printf("We hope you had a great time exploring the galaxy and discovering new planets.\n");
  printf("Come back soon for more adventures!\n");
}

int main() {
  printIntro();
  
  // choose a random planet to explore
  int planetCode;
  srand(time(NULL));  // seed random number generator
  planetCode = rand() % 5 + 1;
  
  explorePlanet(planetCode);
  
  printOutro();
  
  return 0;
}