//FormAI DATASET v1.0 Category: Smart home light control ; Style: retro
// Retro-style Smart Home Light Control Program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIGHT_OFF 0
#define LIGHT_ON 1

typedef struct {
  int brightness;
  int color[3]; // RGB color values
} Light;

// Function to randomize light color
void randomizeColor(int *color) {
  for (int i = 0; i < 3; i++) {
    color[i] = rand() % 256;
  }
}

// Function to print color in RGB format
void printColor(int *color) {
  printf("(%03d, %03d, %03d)", color[0], color[1], color[2]);
}

int main() {
  srand(time(0)); // Seed for randomization

  Light livingRoomLight = {0, {0, 0, 0}};
  Light bedroomLight = {0, {0, 0, 0}};
  Light kitchenLight = {0, {0, 0, 0}};

  int livingRoomState = LIGHT_OFF;
  int bedroomState = LIGHT_OFF;
  int kitchenState = LIGHT_OFF;

  printf("Welcome to Retro Smart Home Light Control Program!\n\n");
  printf("Type 'help' for a list of available commands.\n");
	
  while(1) {
    char input[10];
    printf("\n> ");
    fgets(input, 10, stdin);
		
    if (strcmp(input, "help\n") == 0) {
      printf("Available commands:\n");
      printf("  - turn on [room]\n");
      printf("  - turn off [room]\n");
      printf("  - dim [room] [percent]\n");
      printf("  - randomize [room]\n");
      printf("  - quit\n");
    }
    else if (strcmp(input, "quit\n") == 0) {
      printf("Goodbye!\n");
      return 0;
    }
    else if (strncmp(input, "turn on", 7) == 0) {
      sscanf(input, "%*s %s", input);
      if (strcmp(input, "livingroom") == 0) {
        livingRoomState = LIGHT_ON;
        printf("Living room light turned on!\n");
      }
      else if (strcmp(input, "bedroom") == 0) {
        bedroomState = LIGHT_ON;
        printf("Bedroom light turned on!\n");
      }
      else if (strcmp(input, "kitchen") == 0) {
        kitchenState = LIGHT_ON;
        printf("Kitchen light turned on!\n");
      }
      else {
        printf("Invalid input. Type 'help' for a list of available commands.\n");
      }
    }
    else if (strncmp(input, "turn off", 8) == 0) {
      sscanf(input, "%*s %s", input);
      if (strcmp(input, "livingroom") == 0) {
        livingRoomState = LIGHT_OFF;
        printf("Living room light turned off!\n");
      }
      else if (strcmp(input, "bedroom") == 0) {
        bedroomState = LIGHT_OFF;
        printf("Bedroom light turned off!\n");
      }
      else if (strcmp(input, "kitchen") == 0) {
        kitchenState = LIGHT_OFF;
        printf("Kitchen light turned off!\n");
      }
      else {
        printf("Invalid input. Type 'help' for a list of available commands.\n");
      }
    }
    else if (strncmp(input, "dim", 3) == 0) {
      int percent;
      sscanf(input, "%*s %s %d", input, &percent);
      if (strcmp(input, "livingroom") == 0) {
        if (percent < 0 || percent > 100) {
          printf("Invalid input. Dim level must be between 0 and 100.\n");
        }
        else {
          livingRoomLight.brightness = percent;
          printf("Living room light dimmed to %d%%!\n", percent);
        }
      }
      else if (strcmp(input, "bedroom") == 0) {
        if (percent < 0 || percent > 100) {
          printf("Invalid input. Dim level must be between 0 and 100.\n");
        }
        else {
          bedroomLight.brightness = percent;
          printf("Bedroom light dimmed to %d%%!\n", percent);
        }
      }
      else if (strcmp(input, "kitchen") == 0) {
        if (percent < 0 || percent > 100) {
          printf("Invalid input. Dim level must be between 0 and 100.\n");
        }
        else {
          kitchenLight.brightness = percent;
          printf("Kitchen light dimmed to %d%%!\n", percent);
        }
      }
      else {
        printf("Invalid input. Type 'help' for a list of available commands.\n");
      }
    }
    else if (strncmp(input, "randomize", 9) == 0) {
      sscanf(input, "%*s %s", input);
      if (strcmp(input, "livingroom") == 0) {
        randomizeColor(livingRoomLight.color);
        printf("Living room light randomized! New color: ");
        printColor(livingRoomLight.color);
        printf("\n");
      }
      else if (strcmp(input, "bedroom") == 0) {
        randomizeColor(bedroomLight.color);
        printf("Bedroom light randomized! New color: ");
        printColor(bedroomLight.color);
        printf("\n");
      }
      else if (strcmp(input, "kitchen") == 0) {
        randomizeColor(kitchenLight.color);
        printf("Kitchen light randomized! New color: ");
        printColor(kitchenLight.color);
        printf("\n");
      }
      else {
        printf("Invalid input. Type 'help' for a list of available commands.\n");
      }
    }
    else {
      printf("Invalid input. Type 'help' for a list of available commands.\n");
    }
  }
  return 0;
}