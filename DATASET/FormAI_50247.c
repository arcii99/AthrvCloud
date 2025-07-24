//FormAI DATASET v1.0 Category: Funny ; Style: bold
#include <stdio.h>

int main() {
  int num = 17;
  char grade = 'A';
  float price = 32.50;
  char joke[] = "Why was the computer cold? Because it left its Windows open!";
  
  printf("\n\t\tLAUGHTER IS THE BEST MEDICINE\n\n");
  printf("\t\t--------------------------\n\n");
  
  printf("Here's a joke to get us started:\n\n");
  printf("%s\n\n", joke);
  
  printf("Now, let's do some math...\n\n");
  printf("%d + 5 = %d\n", num, num + 5);
  printf("%d - 7 = %d\n", num, num - 7);
  printf("%d * 4 = %d\n", num, num * 4);
  printf("%d / 2 = %d\n\n", num, num / 2);
  
  printf("Let's round that off to the nearest hundredth...\n\n");
  printf("Price: %.2f\n\n", price);
  
  printf("What grade did you get on your exam? Oh, an %c?\n\n", grade);
  
  printf("Thanks for hanging out with me! Remember, laughter is the best medicine!\n\n");
  
  return 0;
}