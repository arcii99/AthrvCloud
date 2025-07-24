//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int words_per_line = 10;
  int num_lines = 5;
  int num_words = words_per_line * num_lines;
  char testWords[20][10] = {"romeo", "juliet", "love", "death", "passion", "betrayal", "tragedy", "fate", "destiny", "kiss",
                            "star-crossed", "feud", "forbidden", "eternal", "heart", "soul", "mournful", "forever", "parting", "embrace"
                           };
  int typedWordsCount = 0;
  int correctlyTypedWordsCount = 0;
  char typedWord[20];

  printf("Oh, who goes there, that dost thou seek this typing test? \n");
  printf("Enter each word shown below, one by one. \n");

  //shuffle words
  srand (time(NULL));
  for (int i = 0; i < num_words; i++) {
    int randomIndex = rand() % num_words;
    char temp[10];
    strcpy(temp, testWords[i]);
    strcpy(testWords[i], testWords[randomIndex]);
    strcpy(testWords[randomIndex], temp);
  }

  for (int i = 0; i < num_words; i++) {
    if (i % words_per_line == 0) {
      printf("\n");
    }
    printf("%s ", testWords[i]);
    scanf("%s", typedWord);
    typedWordsCount++;
    if (strcmp(testWords[i], typedWord) == 0) {
      correctlyTypedWordsCount++;
    } else {
      printf("O, woe is me! Thou hath typedeth wrongly. The correct word is %s \n", testWords[i]);
    }
  }

  printf("\nThou hath completedeth the typing test. Thou hath typedeth %d words, and %d were correct. \n", typedWordsCount, correctlyTypedWordsCount);
  return 0;
}