//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
  srand(time(NULL)); //initialize random seed
  
  //Arrays of words to construct the conspiracy theory
  char *subject[] = {"The government", "The Illuminati", "NASA", "The Freemasons", "The Rothschilds", "The New World Order"};
  char *verb[] = {"controls", "manipulates", "brainwashes", "monitors", "influences"};
  char *object[] = {"the media", "the weather", "our thoughts", "our health", "the economy", "the education system"};

  //Randomly select words from each array to create the conspiracy theory
  printf("Did you know that %s %s %s?\n", subject[rand() % 6], verb[rand() % 5], object[rand() % 6]);
  printf("It's all a part of their grand plan!\n");
  printf("Wake up, people!\n");
  
  return 0;
}