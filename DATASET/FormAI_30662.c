//FormAI DATASET v1.0 Category: Educational ; Style: Romeo and Juliet
#include<stdio.h>

int main() {

  // Declare variables
  int romeo = 0;
  int juliet = 0;
  int marriage = 0;
  
  // Romeo's quest for his soulmate
  while(!loveFound()) {
    romeo += 1;
    printf("Romeo searches for his soulmate...\n");
    if(romeo == 1000) {
      printf("Romeo has searched for too long, he gives up!\n");
      return 0;
    }
  }
  
  // Juliet appears, Romeo's heart skips a beat
  juliet = loveFound();
  printf("Romeo finally finds his soulmate, it's Juliet! Oh, how his heart races!\n");
  
  // Romeo proposes to Juliet
  printf("Romeo gets down on one knee and proposes to Juliet...\n");
  if(juliet == 1) {
    printf("And she accepts! They are now engaged!\n");
    marriage = 1;
  } else {
    printf("But she rejects him, Romeo is heartbroken...\n");
    return 0;
  }
  
  // Wedding bells ring for Romeo and Juliet
  printf("The wedding day arrives and Romeo and Juliet become husband and wife!\n");
  if(marriage == 1) {
    printf("They live happily ever after...\n");
  }
  
  return 0;
}

// A function to simulate finding true love
int loveFound() {
  int love = rand() % 2;
  return love;
}