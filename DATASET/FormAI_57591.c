//FormAI DATASET v1.0 Category: Scientific ; Style: funny
#include <stdio.h>

int main() {
  
  printf("Hello there!\nI am a scientific program that will calculate the funniest joke in the world!\n");
  
  float joke_level = 0.0;
  int i ,j;
  char joke[100] = "Why did the chicken cross the road? To get to the other side!";
  
  printf("Calculating joke level...\n");
  
  for(i = 0; i < 100; i++) {
    if(joke[i] == ' ') {
      for(j = i+1; joke[j] != '\0'; j++)
        if(joke[j] == 'a' || joke[j] == 'A')
          joke_level += 1.2;
        else if(joke[j] == 'e' || joke[j] == 'E')
          joke_level += 1.1;
        else if(joke[j] == 'i' || joke[j] == 'I')
          joke_level += 1.3;
        else if(joke[j] == 'o' || joke[j] == 'O')
          joke_level += 1.4;
        else if(joke[j] == 'u' || joke[j] == 'U')
          joke_level += 1.5;
    }
  }
  
  printf("The joke level is: %.2f\n", joke_level);
  
  if(joke_level > 50.0)
    printf("Congratulations! You've reached maximum joke level!\n");
  else
    printf("Please try telling funnier jokes next time.\n");
  
  return 0;
}