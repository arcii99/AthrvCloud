//FormAI DATASET v1.0 Category: Spell checking ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX_WORD_SIZE 50 //Maximum size of a word

//Function to check if two words are equal or not
bool areEqual(char word1[], char word2[]) {
  if(strlen(word1)!=strlen(word2)) //if length of both words are not equal, they are not equal
    return false;
  else {
    int i=0;
    while(word1[i]!='\0') {
      if(word1[i]!=word2[i]) //if any character of both words is not equal, they are not equal
        return false;
      i++;
    }
    return true; //else they are equal
  }
}

//Function to check if a given word is present in dictionary or not
bool isPresent(char word[], char dictionary[][MAX_WORD_SIZE], int dictionarySize) {
  for(int i=0; i<dictionarySize; i++) {
    if(areEqual(word, dictionary[i])) //check if word is equal to ith word of dictionary
      return true;
  }
  return false; //if not found in the dictionary
}

//Function to check if a given word has only alphabets or not
bool hasOnlyAlphabets(char word[]) {
  int i=0;
  while(word[i]!='\0') {
    if(!isalpha(word[i])) //if any character is not an alphabet
      return false;
    i++;
  }
  return true; //if all characters are alphabets
}

int main() {
  char dictionary[][MAX_WORD_SIZE] = {"hello", "world", "good", "morning", "afternoon", "evening", "night", "bye", "apple", "banana"}; //sample dictionary of words
  int dictionarySize = 10; //size of dictionary
  char input[100]; //string to store user input
  printf("Enter text:\n");
  fgets(input, 100, stdin); //get user input
  char* token = strtok(input, " \n"); //split input into words using spaces and newline as delimiters
  printf("\nIncorrectly spelled words:\n");
  while(token!=NULL) { //loop until all words are processed
    if(!isPresent(token, dictionary, dictionarySize) && hasOnlyAlphabets(token)) //if word is not in dictionary and has only alphabets
      printf("%s\n", token); //print the word
    token = strtok(NULL, " \n"); //get next word
  }
  return 0;
}