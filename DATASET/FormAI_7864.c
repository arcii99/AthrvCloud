//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
  // Welcome Message
  printf("Welcome to the Random Conspiracy Theory Generator!\n\n");

  // Array of Words
  char* words[] = {"Moon Landing", "Flat Earth", "Illuminati", "Chemtrails", "9/11", "Alien Invasion", "Area 51", "Reptilian Elite", "Global Warming", "Vaccines", "New World Order", "Bigfoot", "Fake News", "Cloning"};

  // Array of Adjectives
  char* adjectives[] = {"Impossible", "Unbelievable", "Shocking", "Mind-blowing", "Alarming", "Distrustful", "Horrifying", "Devastating", "Frightening", "Terrifying"};

  // Seed the Random Number Generator
  srand(time(NULL));

  // Generate a Random Conspiracy Theory
  int random_word_index = rand() % 14;
  int random_adjective_index = rand() % 10;
  printf("%s %s!\n", adjectives[random_adjective_index], words[random_word_index]);

  // Goodbye Message
  printf("\nThank you for using the Random Conspiracy Theory Generator. Stay Vigilant!\n");

  return 0;
}