//FormAI DATASET v1.0 Category: Educational ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// This program generates a random Dungeons and Dragons character sheet!

int main() {
  // Create arrays to store the character's attributes and skills
  int attributes[6] = {0};
  int skills[18] = {0};
  
  // Roll for attributes
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
      // Roll a 6-sided die
      int roll = rand() % 6 + 1;
      // Add the roll to the total
      attributes[i] += roll;
    }
    // Drop the lowest roll
    attributes[i] -= (rand() % 6 + 1);
  }
  
  // Roll for skills
  for (int i = 0; i < 18; i++) {
    // Roll a 20-sided die
    int roll = rand() % 20 + 1;
    // Add the attribute modifier
    int modifier = (attributes[i/3] - 10) / 2;
    skills[i] = roll + modifier;
  }
  
  // Print the character sheet
  printf("Name: ______________________________\n");
  printf("Race: ______________________________\n");
  printf("Class: _____________________________\n");
  printf("______________________\n");
  printf("Attributes:\n");
  printf("STR: %d\n", attributes[0]);
  printf("DEX: %d\n", attributes[1]);
  printf("CON: %d\n", attributes[2]);
  printf("INT: %d\n", attributes[3]);
  printf("WIS: %d\n", attributes[4]);
  printf("CHA: %d\n", attributes[5]);
  printf("______________________\n");
  printf("Skills:\n");
  printf("Acrobatics: %d\n", skills[0]);
  printf("Athletics: %d\n", skills[1]);
  printf("Deception: %d\n", skills[2]);
  printf("History: %d\n", skills[3]);
  printf("Insight: %d\n", skills[4]);
  printf("Intimidation: %d\n", skills[5]);
  printf("Investigation: %d\n", skills[6]);
  printf("Medicine: %d\n", skills[7]);
  printf("Nature: %d\n", skills[8]);
  printf("Perception: %d\n", skills[9]);
  printf("Performance: %d\n", skills[10]);
  printf("Persuasion: %d\n", skills[11]);
  printf("Religion: %d\n", skills[12]);
  printf("Sleight of Hand: %d\n", skills[13]);
  printf("Stealth: %d\n", skills[14]);
  printf("Survival: %d\n", skills[15]);
  printf("______________________\n");

  return 0;
}