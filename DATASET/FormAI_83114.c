//FormAI DATASET v1.0 Category: Compression algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct player {
  char name[MAX_SIZE];
  int score;
};

void compressString(char *str){
  int size = 1;
  char temp = str[0];
  int j = 0, i;

  for(i = 1; i < strlen(str); i++){
    if(str[i] == temp){
      size++;
    }
    else{
      str[j] = temp;
      temp = str[i];
      str[j+1] = size + '0';
      j += 2;
      size = 1;
    }
  }
  str[j] = temp;
  str[j+1] = size + '0';
  str[j+2] = '\0';
}

void printGameStatus(struct player *p, int numOfPlayers){
  printf("\n----------GAME STATUS----------\n");
  int i;
  for(i = 0; i < numOfPlayers; i++){
    printf("Player %s: Score = %d\n", p[i].name, p[i].score);
  }
  printf("--------------------------------\n\n");
}

void updateScores(struct player *p, int numOfPlayers, char *compressedString){
  int i, j = 0;
  for(i = 0; i < numOfPlayers; i++){
    p[i].score += compressedString[j+1] - '0';
    j += 2;
  }
}

void playGame(struct player *p, int numOfPlayers){
  char str[MAX_SIZE];
  int i;
  while(1){
    fflush(stdin);
    printf("Enter the string: ");
    fgets(str, MAX_SIZE, stdin);
    compressString(str);
    printf("Compressed string: %s\n", str);
    updateScores(p, numOfPlayers, str);
    printGameStatus(p, numOfPlayers);
  }
}

int main() {
  int numOfPlayers, i;
  printf("How many players will play the game? ");
  scanf("%d", &numOfPlayers);
  struct player p[numOfPlayers];
  
  for(i = 0; i < numOfPlayers; i++){
    printf("Enter the name of player %d: ", i+1);
    scanf("%s", p[i].name);
    p[i].score = 0;
  }
  
  printf("\n----------LET THE GAME BEGIN!----------\n\n");
  playGame(p, numOfPlayers);

  return 0;
}