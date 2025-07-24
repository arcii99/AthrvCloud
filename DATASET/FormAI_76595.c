//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random fortune
char* generateFortune() {
  // Array of possible fortunes
  char *fortunes[] = {
    "You will find love soon.",
    "Financial success is in your future.",
    "Luck is on your side today.",
    "A major decision must be made soon.",
    "Opportunities will soon present themselves.",
    "Take a risk, it will pay off.",
    "A new adventure awaits you.",
    "Your hard work will soon pay off.",
    "Your creativity will soon shine through.",
    "A change is coming, be prepared."
  };
  
  // Generate a random index to pick a fortune
  int index = rand() % 10;
  
  // Return the selected fortune
  return fortunes[index];
}

int main() {
  // Get the current time to seed the random number generator
  srand(time(NULL));
  
  // Get the user's name
  char name[20];
  printf("Welcome to the Automated Fortune Teller!\n");
  printf("Please enter your name: ");
  scanf("%s", name);
  printf("\nHello, %s!\n", name);
  
  // Generate and print the fortune
  char* fortune = generateFortune();
  printf("\nHere is your fortune: %s\n", fortune);
  
  return 0;
}