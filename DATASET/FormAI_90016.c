//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  FILE *fp;
  char buffer[BUFFER_SIZE], *ptr;
  char tagName[50], attribute[50], value[100];
  int i, j, k;

  // validate command line input
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    exit(1);
  }

  // open XML file for reading
  if ((fp = fopen(argv[1], "r")) == NULL) {
    printf("Error opening file %s\n", argv[1]);
    exit(1);
  }

  // read file line by line
  while (fgets(buffer, BUFFER_SIZE, fp)) {
    // skip comments and header
    if (strncmp(buffer, "<!--", 4) == 0 || strncmp(buffer, "<?", 2) == 0) {
      continue;
    }

    // check for open tag
    if (*buffer == '<') {
      // extract tag name
      for (i = 1; buffer[i] != ' ' && buffer[i] != '>'; i++) {
        tagName[i - 1] = buffer[i];
      }
      tagName[i - 1] = '\0';

      // extract attributes
      ptr = &buffer[i];
      while (*ptr != '>') {
        // skip white space
        while (*ptr == ' ') {
          ptr++;
        }

        // extract attribute name
        for (j = 0; ptr[j] != '='; j++) {
          attribute[j] = ptr[j];
        }
        attribute[j] = '\0';

        // extract attribute value
        ptr = &ptr[j + 1];
        for (k = 0; ptr[k] != '"' && ptr[k] != '\0'; k++) {
          value[k] = ptr[k];
        }
        value[k] = '\0';

        // display attribute
        printf("Tag: %s, Attribute Name: %s, Value: %s\n", tagName, attribute, value);

        // move pointer to next attribute
        ptr = &ptr[k + 1];
      }
    }
  }

  // close file
  fclose(fp);

  return 0;
}