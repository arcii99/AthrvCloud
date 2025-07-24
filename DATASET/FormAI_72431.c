//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

/* Cryptic Spam Detection System */

int main() {
  int i, j, k, a, b, c;
  char spam[MAX] = "Hello my friend, I am writing to offer you a business opportunity that you can't afford to miss! Earn $10000 in just one week! Reply now for more details!", message[MAX];

  printf("Enter your message: ");
  fgets(message, MAX, stdin);

  /* Encryption */
  for(i = 0; message[i] != '\0'; i++){
    message[i] += 3; /* Increment ASCII value by 3 */
  }

  if(strlen(message) > strlen(spam)){
    a = strlen(message);
    b = strlen(spam);
  } else {
    a = strlen(spam);
    b = strlen(message);
  }

  /* Comparison */
  c = 0;
  for(i = 0; i < a; i++){
    for(j = 0; j < b; j++){
      if(message[j] != spam[i]){
        break;
      } else {
        c++;
        k = i + 1;
        for(j = j + 1; j < b; j++){
          if(message[j] == spam[k]){
            c++;
            k++;
          } else {
            c = 0;
            break;
          }
        }
        if(c == b) break;
      }
    }
    if(c == b) break;
  }

  /* Decryption */
  for(i = 0; spam[i] != '\0'; i++){
    spam[i] -= 3; /* Decrement ASCII value by 3 */
  }

  if(c == b){ /* If spam detected */
    printf("ALERT! Spam detected.\n");
    printf("Original spam message: %s\n", spam);
  } else { /* If not spam */
    printf("This message is not spam.\n");
  }

  return 0;
}