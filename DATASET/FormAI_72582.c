//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  srand(time(NULL));

  char* topics[] = {
    "The moon landing was faked",
    "Chemtrails are controlling our minds",
    "The Illuminati controls the world",
    "9/11 was an inside job",
    "The earth is flat",
    "The government is hiding evidence of extraterrestrial life",
    "The Mandela Effect proves there are alternate realities",
    "The Holocaust never happened",
    "Bigfoot is real and being kept secret by the government"
  };

  char* evidence[] = {
    "There are no stars in the moon landing photos!",
    "Airplanes don't leave trails like that!",
    "Look at the pyramid on the dollar bill!",
    "Jet fuel can't melt steel beams!",
    "I've never seen the curve of the earth with my own eyes!",
    "Why won't the government release all their UFO files?",
    "I remember it being spelled 'Barenstien Bears'!",
    "There's no documentation of the Holocaust before the 1970s!",
    "I saw Bigfoot with my own eyes!"
  };

  char* quotes[] = {
    "Wake up sheeple!",
    "You can't handle the truth!",
    "The truth is out there!",
    "We're all being lied to!",
    "The government is hiding something!",
    "Don't believe everything you're told!"
  };

  char* actions[] = {
    "Research it for yourself!",
    "Take the red pill!",
    "Join the resistance!",
    "Spread the word!",
    "Question everything!"
  };

  int topic = rand() % 9;
  int evidence_index = rand() % 9;
  int quote_index = rand() % 6;
  int action_index = rand() % 5;

  printf("Did you know that %s?\n", topics[topic]);
  printf("It's true! %s\n", evidence[evidence_index]);
  printf("%s %s\n", quotes[quote_index], actions[action_index]);

  return 0;
}