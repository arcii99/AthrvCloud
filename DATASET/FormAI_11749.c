//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {FALSE, TRUE} bool;

typedef struct {
  char *key;
  char *value;
} JSONPair;

typedef struct {
  int num_pairs;
  JSONPair *pairs;
} JSONObject;

JSONPair parse_pair(char **json_str) {
  JSONPair pair;
  char tmp[100];
  int i = 0, j;

  // Skip whitespace
  while (isspace((*json_str)[i])) {
    i++;
  }

  // Read key
  j = 0;
  while ((*json_str)[i] != ':') {
    tmp[j] = (*json_str)[i];
    i++; j++;
  }
  tmp[j] = '\0';
  pair.key = strdup(tmp);

  // Skip colon and whitespace
  i += 2;
  while (isspace((*json_str)[i])) {
    i++;
  }

  // Read value
  j = 0;
  while ((*json_str)[i] != ',' && (*json_str)[i] != '}') {
    tmp[j] = (*json_str)[i];
    i++; j++;
  }
  tmp[j] = '\0';
  pair.value = strdup(tmp);

  // Update string pointer
  *json_str = &(*json_str)[i];

  return pair;
}

JSONObject parse_object(char **json_str) {
  JSONObject obj;
  char tmp[100];
  int i = 1;

  // Count number of pairs
  obj.num_pairs = 0;
  while ((*json_str)[i] != '}') {
    if ((*json_str)[i] == ',') {
      obj.num_pairs++;
    }
    i++;
  }
  obj.num_pairs++;

  // Allocate memory for pairs
  obj.pairs = (JSONPair*) malloc(sizeof(JSONPair) * obj.num_pairs);

  // Parse each pair
  i = 1;
  for (int j = 0; j < obj.num_pairs; j++) {
    obj.pairs[j] = parse_pair(json_str);
    if (j < obj.num_pairs - 1) {
      i++; // Skip comma
    }
    i++; // Skip whitespace
  }

  // Update string pointer
  *json_str = &(*json_str)[i];

  return obj;
}

JSONObject parse_json(char *json_str) {
  JSONObject obj;

  // Check for opening brace
  if (json_str[0] != '{') {
    printf("Invalid JSON! Expected opening brace.\n");
    obj.num_pairs = 0;
    obj.pairs = NULL;
    return obj;
  }

  json_str++; // Skip opening brace
  obj = parse_object(&json_str);
  if (json_str[0] != '\0') {
    printf("Invalid JSON! Unexpected character: %c\n", json_str[0]);
    obj.num_pairs = 0;
    obj.pairs = NULL;
  }

  return obj;
}

int main() {
  char json_str[] = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";
  JSONObject obj = parse_json(json_str);

  printf("Parsed JSON object:\n");
  for (int i = 0; i < obj.num_pairs; i++) {
    printf("%s: %s\n", obj.pairs[i].key, obj.pairs[i].value);
  }

  // Free memory
  for (int i = 0; i < obj.num_pairs; i++) {
    free(obj.pairs[i].key);
    free(obj.pairs[i].value);
  }
  free(obj.pairs);

  return 0;
}