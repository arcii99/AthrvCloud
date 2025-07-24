//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed the random number generator.

  int playerCount = 0;

  printf("Welcome to the Random Conspiracy Theory Generator! How many players will be participating? ");
  scanf("%d", &playerCount);

  char** players = (char**)malloc(playerCount * sizeof(char*));
  for (int i = 0; i < playerCount; i++) {
    players[i] = (char*)malloc(50 * sizeof(char));
    printf("Enter player %d's name: ", i+1);
    scanf("%s", players[i]);
  }

  char** theories = (char**)malloc(10 * sizeof(char*));
  theories[0] = "The moon landing was faked by the government.";
  theories[1] = "9/11 was an inside job.";
  theories[2] = "The Illuminati controls the world.";
  theories[3] = "The earth is flat.";
  theories[4] = "The Loch Ness monster is real.";
  theories[5] = "The government is hiding evidence of aliens.";
  theories[6] = "The Bermuda Triangle is a black hole.";
  theories[7] = "The CIA created the AIDS virus.";
  theories[8] = "The Denver airport is a portal to hell.";
  theories[9] = "The government is controlling our minds through television.";

  printf("\nPress any key to generate a conspiracy theory for each player.\n");
  getchar(); // Grab the newline character that scanf left behind.

  for (int i = 0; i < playerCount; i++) {
    printf("%s's conspiracy theory: %s\n", players[i], theories[rand() % 10]);
  }

  for (int i = 0; i < playerCount; i++) {
    free(players[i]);
  }
  free(players);
  free(theories);

  return 0;
}