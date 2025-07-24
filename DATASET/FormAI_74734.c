//FormAI DATASET v1.0 Category: Spam Detection System ; Style: artistic
#include<stdio.h>
#include<ctype.h>
#include<string.h>

// Define the maximum message length
#define MAX_MSG_LEN 1000

// Define the threshold value for spam detection
#define SPAM_THRESHOLD 0.3

// Function to calculate the spam score of a message
double calculate_spam_score(char* msg) {
  double score = 0.0;
  int len = strlen(msg);
  int num_upper = 0;  // Number of uppercase characters
  int num_digits = 0; // Number of digits
  int num_spaces = 0; // Number of spaces
  int num_symbols = 0; // Number of symbols

  // Loop through each character in the message
  for(int i = 0; i < len; i++) {
    // Check if character is uppercase
    if(isupper(msg[i])) {
      num_upper++;
    }
    // Check if character is a digit
    else if(isdigit(msg[i])) {
      num_digits++;
    }
    // Check if character is a whitespace
    else if(isspace(msg[i])) {
      num_spaces++;
    }
    // Check if character is a symbol
    else {
      num_symbols++;
    }
  }

  // Calculate the spam score based on the above criteria
  score = (double)num_upper/len + (double)num_digits/len + (double)num_symbols/len + (double)num_spaces/len;

  return score;
}

int main() {
  // Get the message from the user
  char msg[MAX_MSG_LEN];
  printf("Enter the message: ");
  fgets(msg, MAX_MSG_LEN, stdin);

  // Calculate the spam score of the message
  double spam_score = calculate_spam_score(msg);

  // Check if the spam score is above the threshold
  if(spam_score > SPAM_THRESHOLD) {
    printf("This message may be spam!");
  }
  else {
    printf("This message is not spam.");
  }

  return 0;
}