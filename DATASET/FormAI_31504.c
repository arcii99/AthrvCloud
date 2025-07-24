//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Structure representing a JSON element */
typedef struct {
  char key[100];
  char value[100];
} json_element;

/* Function to parse a JSON string */
void parse_json(char *json_string, json_element *elements, int *num_elements) {
  int i = 0, j = 0;
  char *token;
  char *key, *value;

  /* Tokenize the JSON string */
  token = strtok(json_string, "{\":,}");

  while (token != NULL) {
    switch (i) {
      case 0:
        /* Beginning of a new element */
        key = token;
        i++;
        break;
      case 1:
        /* Element key */
        strcpy(elements[j].key, key);
        value = token;
        i++;
        break;
      case 2:
        /* Element value */
        strcpy(elements[j].value, value);
        i = 0;
        j++;
        (*num_elements)++;
        break;
      default:
        /* Invalid JSON format */
        printf("JSON format is invalid.\n");
        return;
    }
    token = strtok(NULL, "{\":,}");
  }
}

/* Main function to test the parser */
int main() {
  char json_string[100] = "{ \"name\": \"John\", \"age\": 25 }";
  json_element elements[10];
  int num_elements = 0;

  parse_json(json_string, elements, &num_elements);

  /* Print the parsed elements */
  for (int i = 0; i < num_elements; i++) {
    printf("%s: %s\n", elements[i].key, elements[i].value);
  }

  return 0;
}