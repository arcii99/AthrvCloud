//FormAI DATASET v1.0 Category: Audio processing ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the amazing audio processing program!\n");
  printf("What kind of processing would you like to do today?\n");
  printf("1. Amplify the volume\n");
  printf("2. Add an echo effect\n");
  printf("3. Reverse the audio\n");

  int choice;
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      printf("Alright! Let's amplify the volume.\n");
      // code to implement volume amplification
      break;
    case 2:
      printf("Awesome choice! Let's add an echo effect.\n");
      // code to implement echo effect
      break;
    case 3:
      printf("Interesting! Let's reverse the audio.\n");
      // code to implement audio reversal
      break;
    default:
      printf("Oops! Invalid choice.\n");
      exit(0);
  }

  printf("Processing complete! Would you like to save the file? (y/n)\n");
  char response;
  scanf(" %c", &response);

  if(response == 'y' || response == 'Y') {
    printf("Please enter the file name.\n");
    char filename[100];
    scanf("%s", filename);
    printf("File saved as %s.\n", filename);
  } else {
    printf("File not saved.\n");
  }

  printf("Thanks for using the audio processing program!\n");

  return 0;
}