//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: retro
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

/* Rretro style print function */
void print(char* str) {
  for(int i = 0; i < strlen(str); i++) {
    putchar(str[i]);
    if (i % 10 == 0) {
      putchar(' ');
    }
  }
  printf("\n");
}

int countWords(char* inputString, char wordArray[MAX_WORDS][MAX_WORD_LENGTH], int* wordFrequency) {
  int wordCount = 0;
  int i = 0;
  int j = 0;

  while (inputString[i] != '\0') {
    if (isalnum(inputString[i])) {
      wordArray[wordCount][j++] = inputString[i];
    } else {
      if (j > 0) {
        wordArray[wordCount][j] = '\0';
        wordCount++;
        j = 0;
      }
    }
    i++;
  }

  if (j > 0) {
    wordArray[wordCount][j] = '\0';
    wordCount++;
  }

  for (int i = 0; i < wordCount; i++) {
    for (int j = 0; j < wordCount; j++) {
      if (i != j && strcmp(wordArray[i], wordArray[j]) == 0) {
        wordFrequency[i]++;
      }
    }
  }

  return wordCount;
}

void printWords(char wordArray[MAX_WORDS][MAX_WORD_LENGTH], int* wordFrequency, int wordCount) {
  printf("\n%10s\t%10s\n", "Word", "Frequency");
  printf("------------------------------------\n");
  for (int i = 0; i < wordCount; i++) {
    printf("%10s\t%10d\n", wordArray[i], wordFrequency[i]);
  }
}

int main() {
  // Input string (sample from Treasure Island by Robert Louis Stevenson)
  char* inputString = "The brown quick fox jumps over the lazy dog. A red dog jumps over another dog.";
  char wordArray[MAX_WORDS][MAX_WORD_LENGTH];
  int wordFrequency[MAX_WORDS];

  for (int i = 0; i < MAX_WORDS; i++) {
    strcpy(wordArray[i], "\0");
    wordFrequency[i] = 1; // Initialize frequency to 1
  }

  int wordCount = countWords(inputString, wordArray, wordFrequency);
  print("Word frequency count");
  printWords(wordArray, wordFrequency, wordCount);
  return 0;
}