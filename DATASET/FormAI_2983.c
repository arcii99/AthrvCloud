//FormAI DATASET v1.0 Category: Funny ; Style: innovative
#include <stdio.h>

int main() {
  char name[20];
  int age;
  printf("Hello, what's your name?\n");
  scanf("%s", name);
  printf("Nice to meet you, %s! How old are you?\n", name);
  scanf("%d", &age);
  printf("Wow, %d is a great age!\n", age);

  if(age < 18) {
    printf("Sorry, you're not old enough to drive.\n");
  } else {
    printf("Cool, you're old enough to drive!\n");
  }

  printf("What's your favorite color?\n");
  char color[20];
  scanf("%s", color);

  if(color[0] == 'b') {
    printf("Blue is my favorite color too!\n");
  } else {
    printf("%s? Really? I've never heard of that color before.\n", color);
  }

  printf("Hey %s, do you want to hear a joke?\n", name);
  char response[3];
  scanf("%s", response);

  if(response[0] == 'y') {
    printf("Knock, knock!\n");
    printf("Who's there?\n");
    printf("Boo.\n");
    printf("Boo who?\n");
    printf("Don't cry, %s, it's just a joke!\n", name);
  } else {
    printf("Okay, maybe another time then.\n");
  }

  return 0;
}