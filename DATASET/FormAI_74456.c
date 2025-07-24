//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* json_str = "{\"name\":\"John\", \"age\":30, \"city\":\"New York\"}";

// a struct representing a JSON object
typedef struct {
  char* name;
  char* value;
} JSON;

// function to parse a JSON object from a string
JSON* parse_json(char* json_str) {
  JSON* json = malloc(sizeof(JSON));
  char* p = strchr(json_str, ':');
  int name_length = p - json_str - 2; // 2 to skip the opening quote and space
  json->name = malloc(name_length + 1);
  strncpy(json->name, json_str+1, name_length);
  json->name[name_length] = '\0';

  int value_length = strlen(json_str) - name_length - 4; // 4 to skip the closing quote, comma, and space
  json->value = malloc(value_length + 1);
  strncpy(json->value, p+2, value_length);
  json->value[value_length] = '\0';

  return json;
}

int main() {
  JSON* json = parse_json(json_str);
  printf("Name: %s\n", json->name);
  printf("Value: %s\n", json->value);
  free(json->name);
  free(json->value);
  free(json);
  return 0;
}