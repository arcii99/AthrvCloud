//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify(char *html);

int main() {
   char html[5000];
   printf("Enter your HTML code: ");
   scanf("%[^\n]s", html); // Gets the entire input as a string
   beautify(html); // Calls the beautify function
   printf("\nBeautified HTML:\n%s\n", html);
   return 0;
}

void beautify(char *html) {
   char beautified[5000] = ""; // Initializes an empty string to store the beautified code
   int indent_size = 0; // Keeps track of the current indentation level
   for (int i = 0; i < strlen(html); i++) {
      if (html[i] == '<') { // If an opening tag is found
         if (html[i+1] == '/') indent_size--; // If it's a closing tag, reduce the indentation level
         for (int j = 0; j < indent_size; j++) { // Add indentation
            strcat(beautified, "\t");
         }
         beautified[strlen(beautified)] = html[i]; // Copy the '<' to the beautified string
         indent_size++; // Increase the indentation level
         beautified[strlen(beautified)] = '\n'; // Add a newline character
      }
      else if (html[i] == '>') { // If a closing tag is found
         beautified[strlen(beautified)] = html[i]; // Copy the '>' to the beautified string
         beautified[strlen(beautified)] = '\n'; // Add a newline character
      }
      else { // If it's not a tag, simply copy the character to the beautified string
         beautified[strlen(beautified)] = html[i];
      }
   }
   strcpy(html, beautified); // Overwrite the original string with the beautified string
}