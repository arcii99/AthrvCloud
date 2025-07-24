//FormAI DATASET v1.0 Category: Syntax parsing ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char* name;
  int type;
  int size;
} Identifier;

int parseInput(char* buffer, Identifier* idList, int numIdentifiers) {
  int numParsed = 0;
  char* delimiters = " ,();";
  char* token = strtok(buffer, delimiters);
  while (token != NULL) {
    if (numParsed >= numIdentifiers) {
      printf("Error: Too many identifiers.\n");
      return -1;
    }
    idList[numParsed].name = malloc(sizeof(char) * strlen(token));
    strcpy(idList[numParsed].name, token);

    token = strtok(NULL, delimiters);
    if (token == NULL) {
      printf("Error: No type specified for identifier %s.\n", idList[numParsed].name);
      return -1;
    }
    if (strcmp(token, "int") == 0) {
      idList[numParsed].type = 0;
    } else if (strcmp(token, "float") == 0) {
      idList[numParsed].type = 1;
    } else if (strcmp(token, "char") == 0) {
      idList[numParsed].type = 2;
    } else {
      printf("Error: Invalid type '%s' for identifier %s.\n", token, idList[numParsed].name);
      return -1;
    }

    token = strtok(NULL, delimiters);
    if (token == NULL) {
      printf("Error: No size specified for identifier %s.\n", idList[numParsed].name);
      return -1;
    }
    idList[numParsed].size = atoi(token);

    numParsed++;
    token = strtok(NULL, delimiters);
  }
  return numParsed;
}

int main() {
  char inputBuffer[256];
  printf("Enter a list of identifiers (format: name type size, name type size, ...):\n");
  fgets(inputBuffer, 256, stdin);

  Identifier idList[10];
  int numIdentifiers = parseInput(inputBuffer, idList, 10);
  if (numIdentifiers > 0) {
    printf("Parsed %d identifiers:\n", numIdentifiers);
    for (int i = 0; i < numIdentifiers; i++) {
      printf("%s, Type: %d, Size: %d\n", idList[i].name, idList[i].type, idList[i].size);
    }
  }

  for (int i = 0; i < numIdentifiers; i++) {
    free(idList[i].name);
  }
  return 0;
}