//FormAI DATASET v1.0 Category: Text processing ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

  char text[100];
  printf("Enter some text: ");
  fgets(text, 100, stdin); // take input from user and store it in a character array
  
  int len = strlen(text); // get the length of the input
  
  char surprised_text[len+1]; // declare a new character array to store the surprised text
  
  for (int i=0; i<len; i++) {
     if (text[i] == '!' || text[i] == '?') {
        strcat(surprised_text, "?!!"); // if there is an exclamation or question mark, replace it with ?!!
     }
     else {
        strcat(surprised_text, &text[i]); // otherwise, add the character as it is
     }
  }

  printf("The surprised text is: %s", surprised_text); // print the surprised text

  return 0;
}