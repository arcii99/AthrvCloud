//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
  printf("Greetings, my dear Watson. I have been working on a program which will calculate the checksum for a given string of characters.\n");
  
  char str[100];
  int checksum = 0;
  printf("Please enter the string for which you would like to calculate the checksum:\n");
  scanf("%s", str);

  for(int i = 0; str[i] != '\0'; i++) {
    checksum += (int)str[i];
  }

  printf("The checksum for the string is: %d\n", checksum);
  printf("By Jove! This program works splendidly!\n");

  return 0;
}