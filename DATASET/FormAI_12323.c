//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: funny
#include<stdio.h>

int main() {
  int sides;

  printf("Hey there! Let's play a game!\n");
  printf("I'm going to ask you to enter the number of sides of a polygon,\n");
  printf("and I'll tell you what shape it is!\n");
  
  printf("Enter the number of sides (between 3 and 10): ");
  scanf("%d", &sides);

  if(sides < 3 || sides > 10) {
    printf("Oops, that's not a valid input. Let's try again, shall we?\n");
    main(); // recursion to restart the game
  }
  else if(sides == 3) {
    printf("Triangle! The first shape we learn as kids. You love me three times, don't you?\n");
  }
  else if(sides == 4) {
    printf("Square! It's like a rectangle, but more hipster because it has equal sides.\n");
  }
  else if(sides == 5) {
    printf("Pentagon! If a circle had corners, it would look like this.\n");
  }
  else if(sides == 6) {
    printf("Hexagon! Sounds like a Harry Potter spell, doesn't it?\n");
  }
  else if(sides == 7) {
    printf("Heptagon! It's not a dragon, but it's still cool.\n");
  }
  else if(sides == 8) {
    printf("Octagon! The shape of stop signs and infinity stones.\n");
  }
  else if(sides == 9) {
    printf("Nonagon! It's like a unicorn for shapes.\n");
  }
  else if(sides == 10) {
    printf("Decagon! It's like a pentagon, but with twice as many sides.\n");
  }

  printf("Hope you had fun playing! Goodbye!\n");

  return 0; 
}