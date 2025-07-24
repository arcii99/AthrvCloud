//FormAI DATASET v1.0 Category: Spam Detection System ; Style: creative
#include <stdio.h>
#include <string.h>

//Function to check for spam words
int isSpam(char message[])
{
  //List of spam words
  char spamWords[10][15] = {"buy now", "click here", "act fast", "limited time", "free", "double your", "100% satisfied", "cash prize", "win now", "money back"};

  //Check for spam words in message
  for(int i=0; i<10; i++)
  {
    if(strstr(message, spamWords[i]) != NULL)
      return 1;
  }

  return 0;
}

int main()
{
  //Get user input message
  char message[100];
  printf("Enter your message: ");
  fgets(message, 100, stdin);

  //Check if message is spam
  if(isSpam(message))
    printf("SPAM DETECTED!");
  else
    printf("Message is not spam.");

  return 0;
}