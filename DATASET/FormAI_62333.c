//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: ephemeral
#include <stdio.h>

int main() {
  char msg[100], watermark[] = "thisisawatermark";
  int msgLen, wmLen, i, j;
  
  printf("Enter a message: ");
  fgets(msg, 100, stdin);
  
  msgLen = strlen(msg);
  wmLen = strlen(watermark);

  // Embedding the watermark into message
  for(i=0, j=0; i<msgLen && j<wmLen; i++) {
    if(msg[i] >= 'a' && msg[i] <= 'z') {
      if((msg[i] + watermark[j] - 'a') <= 'z') {
        msg[i] += watermark[j] - 'a';
      } else {
        msg[i] = msg[i] + watermark[j] - 'a' - 26;
      }
      j = (j+1)%wmLen;
    } else if(msg[i] >= 'A' && msg[i] <= 'Z') {
      if((msg[i] + watermark[j] - 'A') <= 'Z') {
        msg[i] += watermark[j] - 'A';
      } else {
        msg[i] = msg[i] + watermark[j] - 'A' - 26;
      }
      j = (j+1)%wmLen;
    }
  }
  
  printf("\nWatermarked message: %s\n", msg);
  
  // Retrieving the watermark from the watermarked message
  for(i=0, j=0; i<msgLen && j<wmLen; i++) {
    if(msg[i] >= 'a' && msg[i] <= 'z') {
      if((msg[i] - watermark[j] + 'a') >= 'a') {
        msg[i] -= watermark[j] - 'a';
      } else {
        msg[i] = msg[i] - watermark[j] + 'a' + 26;
      }
      j = (j+1)%wmLen;
    } else if(msg[i] >= 'A' && msg[i] <= 'Z') {
      if((msg[i] - watermark[j] + 'A') >= 'A') {
        msg[i] -= watermark[j] - 'A';
      } else {
        msg[i] = msg[i] - watermark[j] + 'A' + 26;
      }
      j = (j+1)%wmLen;
    }
  }
  
  printf("\nRetrieved watermark: %s\n", msg);
  
  return 0;
}