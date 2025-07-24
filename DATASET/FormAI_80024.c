//FormAI DATASET v1.0 Category: Browser Plugin ; Style: surrealist
#include <stdio.h>

int main() {
  printf("Welcome to the Surrealist Browser Plugin!\n");
  printf("This plugin will randomly generate absurd and surrealistic sentences whenever you load a web page.\n");
  printf("Please enter your name to personalize your experience: ");
  
  char name[20];
  scanf("%s", name);
  
  printf("Thank you, %s. Now sit back and enjoy the weirdness.\n", name);
  
  // List of surrealistic phrases to be randomly chosen from
  char *phrases[] = {"The moon wears a top hat.", 
                     "The trees speak in tongues.",
                     "The sun has a crush on Jupiter.", 
                     "Fish fly and birds swim.", 
                     "The world is an oyster, and we are the pearls.", 
                     "The sky is made of jelly.", 
                     "Time is a thief, and we are its victims."};
                     
  // Get length of the phrases array
  int num_phrases = sizeof(phrases) / sizeof(phrases[0]);
                     
  // Generate a random index to choose a phrase from the array
  srand(time(NULL));
  int rand_index = rand() % num_phrases;
  
  // Display the chosen phrase
  printf("Surreal phrase of the day: %s\n", phrases[rand_index]);
  
  return 0;
}