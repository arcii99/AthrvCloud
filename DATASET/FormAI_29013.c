//FormAI DATASET v1.0 Category: Browser Plugin ; Style: romantic
#include <stdio.h>
#include <stdbool.h>

#define HEART "❤️"
#define ROSE "🌹"
#define KISS "💋"

bool loveFound = false;

void displayMessage();
void displayHeart();
void displayFlower();
void displayKiss();

int main() {
  printf("\nStarting the romantic C browser plugin...\n\n");

  displayMessage();

  if (loveFound) {
    displayHeart();
    displayFlower();
    displayKiss();
  }

  printf("\nExiting the romantic C browser plugin...\n\n");

  return 0;
}

void displayMessage() {
  printf("I'm searching for love...\n");

  // Simulating the search for love through browsing
  for (int i = 0; i < 10; i++) {
    printf("Browsing page %d...\n", i+1);

    // Randomly finding love
    if ((rand() % 10) == 0) {
      loveFound = true;
      break;
    }
  }

  printf("\n");
}

void displayHeart() {
  printf("%s %s %s\n", HEART, HEART, HEART);
  printf("   %s   \n", HEART);
  printf("    %s   \n", HEART);
  printf("     %s  \n", HEART);
  printf("    %s   \n", HEART);
  printf("   %s   \n", HEART);
  printf("%s %s %s\n", HEART, HEART, HEART);
}

void displayFlower() {
  printf("\n%s\n", ROSE);
  printf("  %s %s\n", ROSE, ROSE);
  printf(" %s %s %s\n", ROSE, ROSE, ROSE);
  printf("  %s %s\n", ROSE, ROSE);
}

void displayKiss() {
  printf("\n%s\n", KISS);
}