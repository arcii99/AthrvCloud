//FormAI DATASET v1.0 Category: Table Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// This is a Grateful Table Game, where you can express gratitude for the things in your life! 
// To play, simply follow the prompts and type in what you're grateful for. 

int main() {
  char name[20];
  char thing[50];
  bool playing = true;
  
  printf("Welcome to the Grateful Table Game! What is your name?\n");
  scanf("%s", name);
  printf("Welcome, %s! Let's begin. Think of something you're grateful for and type it in.\n", name);

  while(playing) {
    scanf("%s", thing);
    printf("Wow, %s, that's great! I'm so glad you're grateful for %s.\n", name, thing);
    printf("Would you like to keep playing? (y/n)\n");
    char answer[2];
    scanf("%s", answer);
    if(answer[0] == 'n') {
      printf("Thanks for playing! Have a great day!\n");
      playing = false;
    } else if (answer[0] != 'y') {
      printf("Sorry, I didn't understand that. Let's keep playing!\n");
    } else {
      printf("Awesome! What else are you grateful for, %s?\n", name);
    }
  }

  return 0;
}