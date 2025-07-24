//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: funny
// Welcome to our Levenshtein Distance Calculator! 
// It's like a friendly game of 'spot the difference' with two strings.
// Let's get started!

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Our friend, main function
int main() {

  // First, let's say hello to our users
  printf("Hello there! Welcome to the Levenshtein Distance Calculator!\n");

  // Get user input
  char str1[100], str2[100];
  printf("Please enter your first string: ");
  fgets(str1, 100, stdin);

  // Clean up input
  for(int i = 0; i < strlen(str1); i++) {
    if(str1[i] == '\n') {
      str1[i] = '\0';
    }
  }

  printf("Please enter your second string: ");
  fgets(str2, 100, stdin);

  // Clean up input
  for(int i = 0; i < strlen(str2); i++) {
    if(str2[i] == '\n') {
      str2[i] = '\0';
    }
  }

  // Let's calculate the Levenshtein Distance between the two strings
  // Fear not, we have a formula for this!
  int m = strlen(str1);
  int n = strlen(str2);
  int distances[m+1][n+1];

  for(int i = 0; i <= m; i++) {
    for(int j = 0; j <= n; j++) {
      if(i == 0) {
        distances[i][j] = j;
      }
      else if(j == 0) {
        distances[i][j] = i;
      }
      else if(str1[i-1] == str2[j-1]) {
        distances[i][j] = distances[i-1][j-1];
      }
      else {
        distances[i][j] = 1 + (distances[i-1][j] < distances[i][j-1] ? (distances[i-1][j] < distances[i-1][j-1] ? distances[i-1][j] : distances[i-1][j-1]) : (distances[i][j-1] < distances[i-1][j-1] ? distances[i][j-1] : distances[i-1][j-1]));
      }
    }
  }

  // Ta-da! We have our Levenshtein Distance
  int levenshtein_distance = distances[m][n];

  // And now, the moment you've been waiting for...
  // The big reveal! The suspense! 
  printf("\n\nDrum roll please...\n\n");

  // A little more suspense, why not?
  printf("Calculating the Levenshtein Distance...\n\n");

  // And finally...
  printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", str1, str2, levenshtein_distance);

  // Thank your users and say good bye
  printf("\nThank you for using the Levenshtein Distance Calculator! Have a lovely day!\n");

  return 0;
}