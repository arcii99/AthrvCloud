//FormAI DATASET v1.0 Category: Text Summarizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000

int main() {
  char input[SIZE];
  char output[SIZE];
  char temp[SIZE];
  int count = 0;
  int words = 0;
  int sentences = 0;
  float average = 0.0;
  int index = 0;

  printf("Enter some text: ");
  fgets(input, SIZE, stdin);

  count = strlen(input);

  // Loop through the input to format it into a proper string
  for(int i = 0; i < count; i++) {
    if(input[i] == '.' || input[i] == '?' || input[i] == '!') {
      sentences++;
      output[index] = input[i];
      index++;
      output[index] = '\n'; // Add a newline character after each sentence
      index++;
    } else if(input[i] == ' ' || input[i] == '\n') {
      words++;
      output[index] = ' ';
      index++;
    } else {
      output[index] = input[i];
      index++;
    }
  }
  words++;

  // Output the formatted text
  printf("\nFormatted text:\n");
  printf("%s\n", output);

  // Loop through the formatted text to generate the summary
  for(int i = 0; i < index; i++) {
    if(output[i] == ' ' || output[i] == '\n') {
      words++;
    }
    if(output[i] == '.' || output[i] == '?' || output[i] == '!') {
      sentences++;

      // Generate the summary sentence
      for(int j = 0; j < SIZE; j++) {
        if(temp[j] == '\n') {
          printf("%s\n", temp);
          break;
        } else {
          printf("%c", temp[j]);
        }
      }
      printf("\n");

      temp[0] = '\0';
      average = (float)words / sentences;

      // Check if the summary is too long or too short
      if(words >= 10 && words <= 20 && average < 15) {
        continue;
      } else {
        // Generate a new summary sentence
        for(int j = i - words; j <= i; j++) {
          if(j >= 0 && output[j] != '\n') {
            strncat(temp, &output[j], 1);
          }
        }
      }
      words = 0;
    } else {
      // Add to the temp buffer for the next sentence
      strncat(temp, &output[i], 1);
    }
  }

  return 0;
}