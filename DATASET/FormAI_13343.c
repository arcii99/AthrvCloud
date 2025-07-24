//FormAI DATASET v1.0 Category: Table Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  // initialize game variables
  int turn = 1;
  int p1_score = 0;
  int p2_score = 0;

  printf("Welcome to Romeo and Juliet's Table Game!\n");

  while(p1_score < 50 && p2_score < 50) {
    // player 1's turn
    if(turn == 1) {
      printf("\nIt's Romeo's turn.\n");
      printf("Press ENTER to roll the die.");
      getchar(); // wait for user input

      int roll = rand() % 6 + 1;
      printf("Romeo rolls a %d.\n", roll);

      if(roll == 1) {
        printf("Oh no! Romeo lost his sword and loses the turn.\n");
        turn = 2;
      } else if(roll == 2) {
        printf("Romeo has found a love letter from Juliet and gains 10 points!\n");
        p1_score += 10;
      } else if(roll == 3) {
        printf("Romeo serenades Juliet and gains 5 points!\n");
        p1_score += 5;
      } else if(roll == 4) {
        printf("Romeo has a fight with Tybalt and loses 5 points.\n");
        p1_score -= 5;
      } else if(roll == 5) {
        printf("Romeo and Juliet have a romantic dance and gain 7 points!\n");
        p1_score += 7;
      } else {
        printf("Romeo gets married to Juliet and gains 20 points!\n");
        p1_score += 20;
      }
    } 
    // player 2's turn
    else {
      printf("\nIt's Juliet's turn.\n");
      printf("Press ENTER to roll the die.");
      getchar(); // wait for user input

      int roll = rand() % 6 + 1;
      printf("Juliet rolls a %d.\n", roll);

      if(roll == 1) {
        printf("Oh no! Juliet lost her ring and loses the turn.\n");
        turn = 1;
      } else if(roll == 2) {
        printf("Juliet has found a poem from Romeo and gains 10 points!\n");
        p2_score += 10;
      } else if(roll == 3) {
        printf("Juliet reads a love letter from Romeo and gains 5 points!\n");
        p2_score += 5;
      } else if(roll == 4) {
        printf("Juliet has an argument with Lady Capulet and loses 5 points.\n");
        p2_score -= 5;
      } else if(roll == 5) {
        printf("Juliet and Romeo have a romantic picnic and gain 7 points!\n");
        p2_score += 7;
      } else {
        printf("Juliet and Romeo elope and gain 20 points!\n");
        p2_score += 20;
      }
    }

    // print the scores
    printf("\nScore:\n");
    printf("Romeo: %d\n", p1_score);
    printf("Juliet: %d\n", p2_score);

    // switch turns
    if(turn == 1) {
      turn = 2;
    } else {
      turn = 1;
    }
  }

  // declare winner
  if(p1_score >= 50) {
    printf("Congratulations Romeo! You have won the game!\n");
  } else {
    printf("Congratulations Juliet! You have won the game!\n");
  }

  return 0;
}