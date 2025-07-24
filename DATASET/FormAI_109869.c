//FormAI DATASET v1.0 Category: Smart home light control ; Style: enthusiastic
#include <stdio.h>

int main() {
  char input;
  printf("Welcome to Smart Home Light Control!\n");
  do {
    printf("\nPlease choose an option:\n");
    printf("1 - Turn on lights\n");
    printf("2 - Turn off lights\n");
    printf("3 - Set brightness level\n");
    printf("4 - Exit program\n");
    scanf("%c", &input);

    switch(input) {
      case '1':
        printf("Lights are now turned on!\n");
        break;
      case '2':
        printf("Lights are now turned off!\n");
        break;
      case '3':
        printf("Please enter brightness level (0-100): ");
        int brightness;
        scanf("%d", &brightness);
        if (brightness >= 0 && brightness <= 100) {
          printf("Brightness level set to %d\n", brightness);
        } else {
          printf("Invalid brightness level entered!\n");
        }
        break;
      case '4':
        printf("Exiting Smart Home Light Control...\n");
        break;
      default:
        printf("Invalid option entered! Please enter a valid option.\n");
        break;
    }

  } while (input != '4');

  return 0;
}