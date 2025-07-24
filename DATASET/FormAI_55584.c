//FormAI DATASET v1.0 Category: HTML beautifier ; Style: funny
#include <stdio.h>

int main() {
  char html[10000]; // we're assuming that we're dealing with small HTML files only
  
  printf("Welcome to the HTML Beautifier 3000! This program will make your HTML code look like it just came from a fancy spa treatment. Please enter your HTML code (max length 10,000 characters):\n\n");
  scanf("%s", html);
  
  // here comes the magic of the HTML beautifier
  for (int i = 0; i < strlen(html); i++) {
    if (html[i] == '<') {
      printf("\n"); // let's give each HTML tag its own line for maximum visibility
    }
    printf("%c", html[i]);
    if (html[i] == '>') {
      printf("\n"); // we need to put the closing tag on its own line too, obviously
    }
  }
  
  printf("\n\nTa-daaa! Your HTML code has been transformed! Now it looks like a million bucks.\n");
  return 0; // all done, time to go home (or to grab a snack, your choice)
}