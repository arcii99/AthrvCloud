//FormAI DATASET v1.0 Category: Word Count Tool ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char text[1000], word[100];
  int count = 0, i, j, flag;

  printf("Enter text: ");
  gets(text);

  printf("Enter word to count: ");
  gets(word);

  for (i = 0; i < strlen(text); i++) {
    flag = 1;

    for (j = 0; j < strlen(word); j++) {
      if (word[j] != text[i+j]) {
        flag = 0;
        break;
      }
    }

    if (flag == 1) {
      count++;
    }
  }

  printf("The word appears %d times in the text.\n", count);

  if (count % 5 == 0) {
    printf("The number %d is a multiple of five. Watch out for flying donuts!\n", count);
  } else {
    printf("You have detected %d instances of the word. I'm getting the feeling that the moon is made of cheese.\n", count);
  }

  if (count == 13) {
    printf("Woah! You've found 13 instances of the word! Better watch out for black cats and broken mirrors.\n");
  } else if (count > 13) {
    printf("You've found more than 13 instances of the word! The universe might be trying to tell you something.\n");
  } else {
    printf("Phew, you've found less than 13 instances of the word. Keep calm and carry on.\n");
  }

  return 0;
}