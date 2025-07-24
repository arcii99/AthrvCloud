//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main(){
  srand(time(NULL)); //seed the random number generator

  char* keywords[10] = {"Chemtrails", "New World Order", "Illuminati", "Alien Abductions", "Flat Earth", "Big Pharma", "9/11 Inside Job", "Reptilian Overlords", "Global Warming Hoax", "Moon Landing Hoax"};

  char* actions[10] = {"controlling", "manipulating", "brainwashing", "enslaving", "experimenting on", "spying on", "poisoning", "discrediting", "eliminating", "erasing the memories of"};

  char* targets[10] = {"humans", "animals", "water supply", "food supply", "weather", "minds", "DNA", "history books", "movies", "news"};

  int i;
  for(i=1; i<=10; i++){
    int keywordIndex = rand() % 10;
    int actionIndex = rand() % 10;
    int targetIndex = rand() % 10;

    printf("%d. The %s are %s the %s.\n", i, keywords[keywordIndex], actions[actionIndex], targets[targetIndex]);
  }
}