//FormAI DATASET v1.0 Category: File handling ; Style: surprised
#include <stdio.h>

int main() {
  FILE *file = fopen("surprise.txt", "w");

  if (file == NULL) {
    printf("Oops, something went wrong!\n");
    return 0;
  }

  printf("Surprise! Enter a secret message: ");
  char message[100];
  fgets(message, 100, stdin);

  fprintf(file, "Your secret message is: %s", message);
  printf("Your message has been saved in a file called surprise.txt. Don't worry, it's safe with me!\n");

  char a;
  printf("Want to read your secret message? (Y/N) ");
  scanf("%c", &a);

  if (a == 'Y' || a == 'y') {
    FILE *readfile = fopen("surprise.txt", "r");

    if (readfile == NULL) {
      printf("Oops, something went wrong!\n");
      return 0;
    }

    char buffer[100];
    printf("Your secret message is: ");
    while (fgets(buffer, 100, readfile) != NULL) {
      printf("%s", buffer);
    }

    fclose(readfile);
  }

  fclose(file);
  return 0;
}