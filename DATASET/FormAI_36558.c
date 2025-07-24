//FormAI DATASET v1.0 Category: File handling ; Style: energetic
// This program is designed to create a text file and write some energetic words into it!

#include <stdio.h>

int main() {
  FILE *text_file;

  // Opening the text file, named "my_file.txt" and writing the content into it
  text_file = fopen("my_file.txt", "w");

  if (text_file == NULL) {
    printf("An error occurred while opening the file.\n");
    return -1;
  }

  // The energetic words to write to the file
  char* words[10] = {"amazing", "fantastic", "incredible", "awesome", "inspiring", "thrilling", "exhilarating", "mind-blowing", "unbelievable", "outstanding"};

  // Looping through the words array and writing each word into the file
  for (int i = 0; i < 10; i++) {
    fprintf(text_file, "%s\n", words[i]);
  }

  printf("Successfully written to file!\n");

  // Closing the file after writing
  fclose(text_file);

  return 0;
}