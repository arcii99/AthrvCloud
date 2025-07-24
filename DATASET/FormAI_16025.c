//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a JSON object structure
typedef struct {
  char *key;
  char *value;
} json_obj;

// A utility function to trim whitespaces from a string
char *trim(char *str) {
  char *end;

  while (isspace(*str)) str++;

  if (*str == 0) return str;

  end = str + strlen(str) - 1;
  while (end > str && isspace(*end)) end--;

  *(end+1) = 0;

  return str;
}

// A function to parse a JSON string and extract key-value pairs
json_obj *parse_json(char *json_str, int *num_objs) {
  json_obj *json_objs = NULL;
  int i = 0;
  char *token;

  token = strtok(json_str, "{}\":, ");

  while (token != NULL) {
    if (strcmp(token, "}") == 0) break;

    if (strcmp(token, "\"") == 0) {
      // We are parsing a key
      token = strtok(NULL, "\"");

      json_objs = realloc(json_objs, (i+1) * sizeof(json_obj));
      json_objs[i].key = strdup(trim(token));

    } else if (strcmp(token, ":") == 0) {
      // We are parsing a value
      token = strtok(NULL, "{}\":, ");
      json_objs[i].value = strdup(trim(token));
      i++;

    } else {
      token = strtok(NULL, "{}\":, ");
    }
  }

  *num_objs = i;

  return json_objs;
}

int main() {
  char json_str[] = "{\"name\": \"John\", \"age\": 25}";

  // Parse JSON object
  int num_objs = 0;
  json_obj *json_objs = parse_json(json_str, &num_objs);

  // Print key-value pairs
  for (int i = 0; i < num_objs; i++) {
    printf("%s: %s\n", json_objs[i].key, json_objs[i].value);
  }

  // Free memory
  for (int i = 0; i < num_objs; i++) {
    free(json_objs[i].key);
    free(json_objs[i].value);
  }
  free(json_objs);

  return 0;
}