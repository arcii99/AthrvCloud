//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int main() {

  char question1[100] = "Oh Romeo, how doth thou feel today?";
  printf("%s\n", question1);

  char response1[100];
  fgets(response1, sizeof(response1), stdin);

  int love_score = 0;
  int hate_score = 0;

  char love_words[6][10] = {
    "love",
    "adore",
    "cherish",
    "smitten",
    "passion",
    "amour"
  };

  char hate_words[6][10] = {
    "hate",
    "loathe",
    "despise",
    "detest",
    "abhor",
    "revile"
  };

  // Check response for love words
  for (int i = 0; i < 6; i++) {
    if (strstr(response1, love_words[i])) {
      love_score++;
    }
  }

  // Check response for hate words
  for (int i = 0; i < 6; i++) {
    if (strstr(response1, hate_words[i])) {
      hate_score++;
    }
  }

  if (love_score > hate_score) {
    printf("Thou art in love!\n");
  } else if (hate_score > love_score) {
    printf("Thou art filled with hate!\n");
  } else {
    printf("Thou art neutral in thy feelings.\n");
  }

  return 0;
}