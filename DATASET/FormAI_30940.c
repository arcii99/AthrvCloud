//FormAI DATASET v1.0 Category: Encryption ; Style: funny
#include <stdio.h>

int main() {
  printf("Welcome to the C Encryption Program!\n");
  printf("Where we take your top secret message and turn it into gibberish! \n");

  char message[100];
  printf("Please enter your message: \n");
  scanf("%[^\n]%*c", message);
  
  for (int i = 0; i < 100; i++) {
    if (message[i] == '\0') {
      break;
    }
    // Let's turn each character into ascii code
    int ascii_value = (int) message[i];
    // And then confuse it with mathematics!
    int encrypted_char = ((8*ascii_value) + 13) % 85;
    // Finally, let's print out the new character
    printf("%c", encrypted_char + 40);
  }

  printf("\nCongratulations! Your message has been successfully encrypted!\n");

  return 0;
}