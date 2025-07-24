//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printRandomWords(int numWords) {
  char* words[10] = {"hello", "world", "typing", "speed", "is", "important", 
                     "for", "coding", "skills", "improvement"};
  
  for(int i = 0; i < numWords; i++) {
    printf("%s ", words[rand()%10]);
  }
}

int main() {
  int numWords;
  printf("Welcome to the Typing Speed Test Program!!!\n\n");
  printf("You will need to type as many random words as you can in 30 seconds.\n\n");
  printf("Enter the number of words you are ready to type: ");
  scanf("%d", &numWords);
  
  printf("\n\nReady? Get set! Go!!!\n\n");
  time_t start = time(NULL);
  printRandomWords(numWords);
  time_t end = time(NULL);
  
  printf("\n\nYou have typed %d words in %d seconds!\n", numWords, (int)(end - start));
  printf("Your typing speed is %.2f words per minute!\n\n", numWords*2.0);
  
  if(numWords >= 50) {
    printf("Wow! You are a typing superstar!!!\n");
  } else if(numWords >= 30) {
    printf("Not bad, but you can do better!\n");
  } else if(numWords >= 10) {
    printf("Keep practicing for improvement!\n");
  } else {
    printf("Don't give up, practice makes progress!\n");
  }
  
  return 0;
}