//FormAI DATASET v1.0 Category: Poker Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int deck[], int size) {
   int i, j, temp;
   for(i=0; i<size; i++) {
      j = rand() % size;
      temp = deck[i];
      deck[i] = deck[j];
      deck[j] = temp;
   }
}

int main() {
   int deck[52];
   int i;
   srand(time(NULL));
   for(i=0; i<52; i++)
      deck[i] = i+1;
   shuffle(deck, 52);
   for(i=0; i<52; i++)
      printf("%d ", deck[i]);
   return 0;
}