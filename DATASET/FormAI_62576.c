//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char sentence[100];
  int i, score = 0;

  printf("Enter your sentence: ");
  fgets(sentence, 100, stdin);

  /*Loop through each character of the sentence.*/
  for(i=0;i<strlen(sentence);i++)
  {
    switch(sentence[i])
    {
      case 'a': case 'e': case 'i': case 'o': case 'u':
        /*Vowel score is positive*/
        score+=1; 
        break;
      case 'b': case 'c': case 'd': case 'f': case 'g': 
      case 'h': case 'j': case 'k': case 'l': case 'm': 
      case 'n': case 'p': case 'q': case 'r': case 's': 
      case 't': case 'v': case 'w': case 'x': case 'y': 
      case 'z':
        /*Consonant score is negative*/
        score-=1;
        break;
      case '!': case '?':
        /*Exclamation and question marks indicate strong emotion*/
        score+=5;
        break;
      case ',':
        /*Commas indicate pause or uncertainty*/
        score-=2;
        break;
      case '.':
        /*Periods indicate end of sentence and neutral tone*/
        break;
      default:
        /*Any other characters do not affect the score*/
        break;
    }
  }
  
  /*Display the sentiment score of the sentence.*/
  if(score>=5)
    printf("The sentence has a positive sentiment with a score of %d.", score);
  else if(score<=-5)
    printf("The sentence has a negative sentiment with a score of %d.", score);
  else
    printf("The sentence has a neutral sentiment with a score of %d.", score);

  return 0;
}