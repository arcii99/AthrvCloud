//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  int length, i;
  unsigned char checksum = 0;

  if (argc == 2) {

    // Get the length of the input string.
    length = strlen(argv[1]);

    // Loop through each character in the string and add its value to the checksum.
    for (i = 0; i < length; i++) {
      checksum += argv[1][i];
    }

    printf("Checksum value for %s : %u\n", argv[1], checksum);

  } else {

    // Display usage instructions if the correct number of arguments were not provided.
    printf("Invalid arguments. Usage: ./checksum <string>\n");
  }

  return 0;
}