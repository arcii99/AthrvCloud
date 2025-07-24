//FormAI DATASET v1.0 Category: Text processing ; Style: grateful
#include <stdio.h>

int main() {
  printf("Hello, I am a grateful chatbot!\n");
  printf("Today, I am here to show you a sample program in C that counts the number of words in a text file and displays them with a message.\n");

  //Opening text file
  FILE *fp;
  char filename[] = "sample_text.txt";
  fp = fopen(filename, "r");

  //Initializing the word count to zero
  int word_count = 0;

  //Checking if file is accessible
  if(fp == NULL) {
    printf("Error: Unable to open file %s.\n", filename);
    return -1;
  }
  
  //Processing the file and counting words
  char ch;
  while((ch = fgetc(fp)) != EOF) {
    //Checking if current character is space or newline
    if(ch == ' ' || ch == '\n') {
        word_count++;
    }
  }

  //Closing the text file
  fclose(fp);
  
  printf("The number of words in the file %s is: %d\n", filename, word_count);
  printf("Thank you for running this program and have a great day!\n");

  return 0;
}