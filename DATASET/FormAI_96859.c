//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_PLAYERS 4

int main() {
  char sentences[MAX_SENTENCES][100];
  int player_scores[MAX_PLAYERS] = {0};
  int total_players;
  int sentence_count = 0;

  printf("Enter the total number of players (maximum %d): ", MAX_PLAYERS);
  scanf("%d", &total_players);

  printf("Enter sentences one by one (maximum %d sentences), type stop to end:\n", MAX_SENTENCES);
  char input[100];
  while (1) {
    fgets(input, 100, stdin);
    if (strcmp(input, "stop\n") == 0 || sentence_count == MAX_SENTENCES) {
      break;
    }
    strcpy(sentences[sentence_count], input);
    sentence_count++;
  }

  int current_player = 0;
  for (int i = 0; i < sentence_count; i++) {
    char *sentence = sentences[i];
    printf("\nPlayer %d, please rate the following sentence from 1 to 5:\n%s", current_player + 1, sentence);
    int score;
    scanf("%d", &score);
    player_scores[current_player] += score;
    current_player = (current_player + 1) % total_players;
  }

  printf("\nFinal scores:\n");
  for (int i = 0; i < total_players; i++) {
    printf("Player %d: %d\n", i + 1, player_scores[i]);
  }
  
  return 0;
}