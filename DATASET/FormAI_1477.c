//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  This C program is a simple antivirus scanner.
  It reads the file specified by the user and checks it against a list of known viruses.
  If a virus is detected, it prints out a message indicating the file is infected.
  This is a very simple example, meant for educational purposes only.
*/

// List of known virus signatures
char* virus_signatures[] = {"Win32.Sality", "W32.SillyFDC", "Linux.Rootkit", "MacOS.iWorm"};

// Maximum number of virus signatures
#define MAX_SIGNATURES 4

// Check if a file contains a virus
int is_infected(char* filename) {
  FILE* file;
  char buffer[1024];
  int i, j;
  int infected = 0;
  file = fopen(filename, "rb");
  if (file == NULL) {
    return 0;
  }
  while (fgets(buffer, sizeof(buffer), file) != NULL) {
    for (i = 0; i < MAX_SIGNATURES; i++) {
      if (strstr(buffer, virus_signatures[i]) != NULL) {
        infected = 1;
        break;
      }
    }
    if (infected) {
      break;
    }
  }
  fclose(file);
  return infected;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: %s [filename]\n", argv[0]);
    return 0;
  }
  if (is_infected(argv[1])) {
    printf("The file %s is infected with a virus!\n", argv[1]);
  } else {
    printf("The file %s is clean!\n", argv[1]);
  }
  return 0;
}