//FormAI DATASET v1.0 Category: Funny ; Style: thoughtful
#include <stdio.h>

int main() {
  // greeting message
  printf("Hello, welcome to the \"Make A Joke\" program\n");
  printf("Please enter a funny word: ");
  
  // get user input
  char word[50];
  fgets(word, 50, stdin);
  
  // replace vowels with the next vowel in the alphabet
  char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
  char new_vowels[] = {'e', 'i', 'o', 'u', 'a', 'E', 'I', 'O', 'U', 'A'};
  for (int i = 0; i < sizeof(word)/sizeof(word[0]); i++) {
    for (int j = 0; j < sizeof(vowels)/sizeof(vowels[0]); j++) {
      if (word[i] == vowels[j]) {
        word[i] = new_vowels[j];
        break;
      }
    }
  }
  
  // add some humor
  printf("Here's your funny word: %s", word);
  printf("Why did the %s cross the road? To get to the other side!\n", word);
  
  return 0;
}