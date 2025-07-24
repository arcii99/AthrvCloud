//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: funny
#include<stdio.h>

int main() {

  char* joke = "Why was the computer cold?";
  char* punchline = "Because it left its Windows open!";

  char* greeting = "How are you feeling today?";
  char* sad_response = "I'm feeling blue :(";
  char* happy_response = "I'm on cloud nine! :D";

  printf("%s\n", joke);
  printf("%s\n", punchline);

  printf("%s\n", greeting);

  char response[20];
  scanf("%s", response);

  int sentiment = 0;

  if (strcmp(response, "good") == 0 ||
      strcmp(response, "great") == 0 ||
      strcmp(response, "happy") == 0) {
    sentiment = 1;
    printf("%s\n", happy_response);
  } else if (strcmp(response, "bad") == 0 ||
             strcmp(response, "terrible") == 0 ||
             strcmp(response, "sad") == 0) {
    sentiment = -1;
    printf("%s\n", sad_response);
  } else {
    printf("I'm sorry, I didn't understand your response.\n");
  }

  return sentiment;
}