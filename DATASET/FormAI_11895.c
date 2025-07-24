//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Ada Lovelace
/* Welcome to the Spam Detection System in C Example Program
   Created by Ada Lovelace
   Description: This program scans input for certain keywords commonly used in spam messages,
   and determines whether the input is likely spam or not.
*/

#include <stdio.h>
#include <string.h>

int main() {
  char input[500];
  char keywords[10][20] = {"money", "free", "discount", "winner", "prize", "offer", "urgent", "claim", "limited", "act now"};
  int num_keywords = 10;
  int spam_count = 0;
  
  printf("Welcome to the Spam Detection System!\nEnter your message: ");
  fgets(input, 500, stdin);

  // check input for keywords
  for (int i = 0; i < num_keywords; i++) {
    if (strstr(input, keywords[i]) != NULL) {
        spam_count++;
    }
  }

  // determine if input is likely spam or not
  if (spam_count >= 3) {
    printf("\nSPAM DETECTED: This message is likely spam.\n");
  } else {
    printf("\nNO SPAM DETECTED: This message is likely not spam.\n");
  }

  return 0;
}