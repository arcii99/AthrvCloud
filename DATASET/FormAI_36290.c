//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  // Introduction
  printf("Welcome to the Cryptic Adventure Game!\n");
  printf("In this game, you will embark on a journey filled with mystery and intrigue.\n");
  printf("You must solve cryptic puzzles and clues to progress through the game.\n");
  printf("Are you ready to begin? (y/n)\n");
  
  // Player Input: Start or Quit
  char input[10];
  fgets(input, 10, stdin);
  if (input[0] == 'n' || input[0] == 'N') {
    printf("That's too bad. Maybe you'll be ready to play another time.\n");
    return 0;
  }
  
  // Level One
  printf("\n==== LEVEL ONE ====\n");
  printf("You find yourself in a dark room with a single door and a cryptic message scrawled on the wall:\n");
  printf("4 8 3, 9 1 6, 2 7 5\n");
  printf("What do you do?\n");
  
  // Player Input: Solve Puzzle or Quit
  fgets(input, 10, stdin);
  if (input[0] == 'n' || input[0] == 'N') {
    printf("That's too bad. Maybe you'll be ready to play another time.\n");
    return 0;
  }
  
  // Level One: Puzzle
  printf("\nThe puzzle looks like a magic square, where the sum of each row, column, and diagonal equals fifteen.\n");
  printf("What numbers should you put in the blank spaces?\n");
  printf("4 _ 3, _ 1 _, 2 _ 5\n");
  
  // Player Input: Solve Puzzle or Quit
  fgets(input, 10, stdin);
  if (input[0] == 'n' || input[0] == 'N') {
    printf("\nYou didn't even try! Game over.\n");
    return 0;
  }
  
  // Level One: Puzzle Solution
  printf("\nYou fill in the blank spaces with 8, 9, and 6, and the door unlocks!\n");
  printf("You step through the door and find yourself in a new room filled with even more cryptic messages and puzzles.\n");
  
  // Level Two
  printf("\n==== LEVEL TWO ====\n");
  printf("You see a strange machine in the center of the room with strange runes etched on its surface.\n");
  printf("Next to it is a note with some instructions and a cryptic code:\n");
  printf("- 1 = A B\n- 2 = B A B\n- 3 = C D C\n- 4 = D C D\n\n");
  printf("ca1cd2bac4?adb3ad\n");
  printf("What do you do?\n");
  
  // Player Input: Solve Puzzle or Quit
  fgets(input, 10, stdin);
  if (input[0] == 'n' || input[0] == 'N') {
    printf("\nYou can't handle the pressure? Too bad. Game over.\n");
    return 0;
  }
  
  // Level Two: Puzzle
  printf("\nThis code seems to be a series of runes and numbers. What does it all mean?\n");
  printf("After studying the code for a while, you realize that the numbers correspond to the instructions given.\n");
  printf("So, the code could be translated to: caACcbADbDCadbCDDad\n");
  printf("What could that possibly mean?\n");
  printf("You notice that the runes in each instruction contain opposite letters. A and B are opposite, C and D are opposite.\n");
  printf("Maybe you can use that information to solve the code!\n");
  
  // Player Input: Solve Puzzle or Quit
  fgets(input, 10, stdin);
  if (input[0] == 'n' || input[0] == 'N') {
    printf("\nYou're giving up now? Game over for you.\n");
    return 0;
  }
  
  // Level Two: Puzzle Solution
  printf("\nYou decode the message by translating the runes:\n");
  printf("caACcbADbDCadbCDDad => CLUE FOUND: cold\n");
  printf("Suddenly, the machine in the center of the room whirs to life and the door to the next room opens!\n");
  
  // Level Three
  printf("\n==== LEVEL THREE ====\n");
  printf("You enter the next room, but it appears to be empty.\n");
  printf("As you walk towards the other end of the room, you hear a faint clicking sound under your feet.\n");
  printf("Suddenly, a trapdoor opens up and you're falling down a dark pit!\n");
  printf("You land on a pile of soft cushions, but you're trapped in a small room with no exits.\n");
  printf("In the center of the room is a cryptic message written in blood:\n");
  printf("I am the beginning of the end, and the end of time and space. I am essential to creation, and I surround every place.\n");
  printf("What am I?\n");
  
  // Player Input: Solve Puzzle or Quit
  fgets(input, 10, stdin);
  if (input[0] == 'n' || input[0] == 'N') {
    printf("\nYou're giving up now? This trapdoor was your undoing. Game over.\n");
    return 0;
  }
  
  // Level Three: Puzzle
  printf("\nYou've heard this riddle before, but it's been a while since you've thought about it.\n");
  printf("Let's see... the beginning of the end? The end of time and space?\n");
  printf("The answer is clear: the letter 'e'.\n");
  
  // Level Three: Puzzle Solution
  printf("\nYou answer the riddle correctly, and the walls of the room begin to shift and change.\n");
  printf("Suddenly, a secret door appears and you are free!\n");
  
  // Conclusion
  printf("\n==== CONGRATULATIONS! YOU HAVE WON THE CRYPTIC ADVENTURE GAME! ====\n");
  printf("Thanks for playing! We hope you enjoyed the game.\n");
  return 0;
}