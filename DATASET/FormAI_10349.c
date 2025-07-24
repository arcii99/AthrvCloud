//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  const char * nouns[10] = {
    "government",
    "aliens",
    "Illuminati",
    "corporations",
    "New World Order",
    "freemasons",
    "shadow government",
    "deep state",
    "reptilians",
    "rogue AI"
  };
  
  const char * verbs[10] = {
    "controlling",
    "manipulating",
    "brainwashing",
    "monitoring",
    "spying on",
    "poisoning",
    "experimenting on",
    "creating",
    "influencing",
    "silencing"
  };
  
  const char * adjectives[10] = {
    "secret",
    "invisible",
    "powerful",
    "unstoppable",
    "omnipotent",
    "malevolent",
    "sinister",
    "maniacal",
    "deceitful",
    "horrific"
  };
  
  const char * theories[10] = {
    "chemtrails are controlling our minds",
    "COVID-19 was created by the government as a bioweapon",
    "the moon landing was faked",
    "9/11 was an inside job",
    "the earth is flat",
    "vaccines are a government conspiracy",
    "Area 51 is hiding evidence of alien life",
    "Elvis is still alive and living in hiding",
    "AIDS is a man-made disease",
    "fluoride in water is a mind control agent"
  };
  
  srand(time(NULL));
  
  printf("Welcome to the Random Conspiracy Theory Generator!\n");
  printf("Here is your unique theory:\n\n");
  
  printf("The %s are %s the world with their %s %s!\n",
         nouns[rand() % 10], verbs[rand() % 10], adjectives[rand() % 10], theories[rand() % 10]);
  
  printf("\nStay woke!\n");
  
  return 0;
}