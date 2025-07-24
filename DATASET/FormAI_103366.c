//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 256
#define MAX_SPAM_WORDS 10

int main() {
  char email[MAX_EMAIL_LENGTH];
  char spam_words[MAX_SPAM_WORDS][MAX_EMAIL_LENGTH];

  int num_spam_words;
  printf("Enter the number of spam words to detect: ");
  scanf("%d", &num_spam_words);

  for (int i = 0; i < num_spam_words; i++) {
    printf("Enter spam word %d: ", i+1);
    scanf("%s", spam_words[i]);
  }

  printf("Enter the email to check for spam: ");
  scanf("%s", email);

  int is_spam = 0;

  for (int i = 0; i < num_spam_words; i++) {
    if (strstr(email, spam_words[i]) != NULL) {
      is_spam = 1;
      break;
    }
  }

  if (is_spam) {
    printf("This email is marked as spam!\n");
  } else {
    printf("This email is not marked as spam.\n");
  }

  return 0;
}