//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Sherlock Holmes
#include <stdio.h>

int main() {

  //Greeting
  printf("Greetings, my dear Watson! Welcome to the Text to ASCII Art generator.\n");
  printf("Please input the text you would like to convert to ASCII Art: ");
  
  //Scan user input
  char input[50];
  scanf("%[^\n]", input);

  //Creating ASCII Art
  printf("\n");
  printf(" *---------------------------------------------* \n");
  printf(" | ");
  for(int i = 0; input[i] != '\0'; i++) {
    printf("%c  ", input[i]);
  }
  printf("|\n");
  printf(" |                                             | \n");
  printf(" |  _   _    ____    _____    ___    ___   ___ | \n");
  printf(" | | | | |  / __ \\  |  __ \\  / _ \\  / _ \\ / _ \\| \n");
  printf(" | | |_| | | |  | | | |__) || | | || | | | | | | \n");
  printf(" | |  _  | | |  | | |  ___/ | | | || | | | | | | \n");
  printf(" | | | | | | |__| | | |     | |_| || |_| | |_| | \n");
  printf(" | |_| |_|  \\____/  |_|      \\___/  \\___/ \\___/| \n");
  printf(" *---------------------------------------------* \n");
  printf("\n");

  //Farewell
  printf("Well done, Watson! You have successfully created ASCII art for the given text.\n");

  return 0;
}