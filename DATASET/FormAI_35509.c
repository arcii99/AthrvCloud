//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
   srand(time(NULL));
   char* subjects[] = {"The Illuminati", "Aliens", "The Government", "Big Pharma", 
                       "The Rothschilds", "The NWO", "Deep State", "The Vatican", 
                       "Reptilians", "The CIA", "Masonic Lodge", "Google", "Facebook", 
                       "The Elders of Zion", "Time Travelers", "The Mandela Effect"};
   char* verbs[] = {"plotted", "conspired with", "controlled", "manipulated", "brainwashed", 
                    "used", "hid behind", "infiltrated", "secretly operated", "silenced"};
   char* objects[] = {"9/11", "Area 51", "the moon landing", "JFK assassination", 
                      "global warming", "vaccinations", "chemtrails", "HAARP", 
                      "the Flat Earth theory", "the Loch Ness Monster", "crop circles",
                      "Elvis Presley's death", "the Titanic sinking", "the Bermuda Triangle",
                      "the end of the world", "Bitcoin's invention"};

   int subject_index = rand() % 16;
   int verb_index = rand() % 10;
   int object_index = rand() % 16;
   
   printf("Did you know that %s have %s %s?\n", subjects[subject_index], verbs[verb_index], objects[object_index]);

   return 0;
}