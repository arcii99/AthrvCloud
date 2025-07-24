//FormAI DATASET v1.0 Category: Poker Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 52
#define FACE 13
#define SUIT 4

void shuffle(int deck[][FACE]);
void deal(int deck[][FACE], char *face[], char *suit[]);

int main(void) {
   int deck[SUIT][FACE] = {0};
   char *face[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
                    "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
   char *suit[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

   srand(time(NULL));   // seed random number generator
   shuffle(deck);  
   deal(deck, face, suit);

   return 0;
}

void shuffle(int deck[][FACE]) {
   size_t row = 0;   // row number
   size_t column = 0;   // column number
   int card = 0;   // counter

   for(card = 1; card <= SIZE; ++card) {
      do {   // choose a new random location until unoccupied one is found
         row = rand() % SUIT;
         column = rand() % FACE;
      } while(deck[row][column] != 0);   // if occupied reiterate

      deck[row][column] = card;
   }
}

void deal(int deck[][FACE], char *face[], char *suit[]) {
   int card = 0;   // counter
   size_t row = 0;   // row number
   size_t column = 0;   // column number

   for(card = 1; card <= SIZE; ++card) {
      // loop over rows of deck
      for(row = 0; row < SUIT; ++row) {
         // loop over columns of deck for current row
         for(column = 0; column < FACE; ++column) {
            // if the slot contains the current card, print card
            if(deck[row][column] == card) {
               printf("%5s of %-8s%c", face[column], suit[row],
                      card % 2 == 0 ? '\n' : '\t');
            }
         }
      }
   }
}