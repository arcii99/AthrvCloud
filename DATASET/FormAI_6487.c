//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *subjects[] = {
  "The government",
  "The Illuminati",
  "Aliens",
  "Time travelers",
  "The lizard people",
  "The Freemasons",
  "The deep state",
  "The interdimensional beings",
  "The New World Order",
  "The secret society of magicians"
};

char *actions[] = {
  "are manipulating",
  "are controlling",
  "are hiding", 
  "are influencing", 
  "are altering", 
  "are shaping", 
  "are programming", 
  "are brainwashing", 
  "are sabotaging", 
  "are poisoning"
};

char *objects[] = {
  "the weather",
  "our DNA",
  "our thoughts",
  "our dreams",
  "our memories",
  "our technology",
  "our food supply",
  "our education system",
  "our media",
  "our economy"
};

char *locations[] = {
  "in Area 51",
  "in the Bermuda Triangle",
  "in the hollow earth",
  "on the dark side of the moon",
  "in the Vatican catacombs",
  "in the depths of the ocean",
  "in a secret military base",
  "in a parallel universe",
  "in a time vortex",
  "in a virtual reality simulation"
};

char *proofs[] = {
  "I read it on the internet",
  "My friend saw it happen",
  "I had a dream about it",
  "I just feel it in my gut",
  "It's obvious if you connect the dots",
  "It's all in the secret symbols",
  "The aliens told me themselves",
  "The government denied it, so it must be true",
  "It's just like in that movie/book/show",
  "It's a message from God/aliens/angels"
};

int main() {
  srand(time(NULL));

  printf("\n---Random Conspiracy Theory Generator---\n\n");
  printf("Did you know that %s %s %s %s?!\n\n", 
         subjects[rand() % 10], 
         actions[rand() % 10], 
         objects[rand() % 10], 
         locations[rand() % 10]);

  printf("I have proof, it's all %s!\n\n", proofs[rand() % 10]);

  printf("Don't believe me? That's exactly what they want you to think...\n");

  return 0;
}