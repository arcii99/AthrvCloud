//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_SIZE 100

/* Helper functions */
int isNumeric(char* token) {
  int i;
  for (i = 0; i < strlen(token); i++) {
    if (!isdigit(*(token + i))) {
      return 0;
    }
  }
  return 1;
}

/* Main function */
int main() {
  // Initialize variables
  char json[MAX_JSON_SIZE];
  char *token;
  char *key;
  int value;
  int count = 0;

  // Get JSON data from user
  printf("Enter the JSON data:\n");
  fgets(json, MAX_JSON_SIZE, stdin);

  // Extract key-value pairs from JSON data
  token = strtok(json, "{},\"");
  while (token != NULL) {
    if (count % 2 == 0) { // Key
      key = token;
    } else { // Value
      if (isNumeric(token)) { // Value is numeric
        value = atoi(token);
        printf("Key: %s, Value: %d\n", key, value);
      } else { // Value is string
        printf("Key: %s, Value: %s\n", key, token);
      }
    }
    count++;
    token = strtok(NULL, "{},\"");
  }

  return 0;
}