//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
  char alphabet[52] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  char userChar; 
  clock_t start, end; 
  int score = 0;
  
  printf("Welcome to the Brave Typing Speed Test! Press Enter to start.");
  getchar();
  
  start = clock();
  
  while (score < 10) {
    int randIndex = rand() % 52;
    printf("Please type the letter %c:\n", alphabet[randIndex]);
    userChar = getchar();
    
    if (tolower(userChar) == tolower(alphabet[randIndex])) {
      printf("Correct!\n");
      score++;
    } else {
      printf("Incorrect. You typed %c, but the correct answer was %c.\n", userChar, alphabet[randIndex]);
    }
    
    // Clear input buffer
    while (getchar() != '\n') {}
  }
  
  end = clock();

  int timeTaken = (int) (end - start) / CLOCKS_PER_SEC;
  int typingSpeed = (int) (600 / timeTaken);

  printf("Congratulations, you completed the Brave Typing Speed Test in %d seconds with a typing speed of %d characters per minute!\n", timeTaken, typingSpeed);

  return 0;
}