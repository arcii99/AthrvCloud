//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: medieval
#include <stdio.h>

int main() {
  int input;
  int checksum = 0;
  printf("Greetings, brave knight! This is the Checksum Calculator.\n");
  printf("Please enter your secret message in lowercase: ");
  
  while ((input = getchar()) != '\n') {
    checksum += (input - 'a');
  }
  printf("Your message checksum is: %d\n", checksum);
  
  printf("To check if your message was received correctly by your squire, please enter the checksum you received from them: ");
  int received_checksum;
  scanf("%d", &received_checksum);
  
  if (checksum == received_checksum) {
    printf("Huzzah! Your squire has received your message correctly.\n");
  } else {
    printf("Alas! The checksum did not match. Your message was lost in transmission.\n");
  }
  
  return 0;
}