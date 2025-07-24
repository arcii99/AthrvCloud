//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold a key-value pair
typedef struct {
  char *key;
  char *value;
} KeyValuePair;

// Define a structure to hold the parsed JSON object
typedef struct {
  int count;
  KeyValuePair *pairs;
} JSONObject;

// Define a function to parse a JSON object from a string
JSONObject *parseJSON(char *jsonString) {
  // First, count the number of key-value pairs in the object
  int count = 0;
  char *token = strtok(jsonString, ":{,}");
  while (token != NULL) {
    count++;
    token = strtok(NULL, ":{,}");
  }

  // Allocate memory for the JSONObject and its KeyValuePair array
  JSONObject *jsonObject = malloc(sizeof(JSONObject));
  jsonObject->count = count;
  jsonObject->pairs = malloc(sizeof(KeyValuePair) * count);

  // Reset the string tokenizer and parse the key-value pairs
  char *key = NULL;
  token = strtok(jsonString, ":{,}");
  int index = 0;
  while (token != NULL) {
    if (key == NULL) {
      key = token;
    } else {
      KeyValuePair pair = {key, token};
      jsonObject->pairs[index++] = pair;
      key = NULL;
    }
    token = strtok(NULL, ":{,}");
  }

  return jsonObject;
}

// Define a function to free the memory used by a JSONObject
void freeJSON(JSONObject *jsonObject) {
  for (int i = 0; i < jsonObject->count; i++) {
    free(jsonObject->pairs[i].key);
    free(jsonObject->pairs[i].value);
  }
  free(jsonObject->pairs);
  free(jsonObject);
}

// Define a main function to test the JSON parser
int main() {
  char jsonString[] = "{\"name\":\"John Smith\",\"age\":35,\"married\":true}";
  JSONObject *jsonObject = parseJSON(jsonString);
  printf("Parsed JSON object with %d key-value pairs:\n", jsonObject->count);
  for (int i = 0; i < jsonObject->count; i++) {
    printf("%s: %s\n", jsonObject->pairs[i].key, jsonObject->pairs[i].value);
  }
  freeJSON(jsonObject);
  return 0;
}