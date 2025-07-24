//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define a JSON structure
typedef struct {
  char* key;
  char* value;
} JSONKeyValue;

// Define a function to parse a single JSON key-value pair
JSONKeyValue* parseJSONKeyValue(char* jsonString) {
  JSONKeyValue* keyValue = malloc(sizeof(JSONKeyValue));
  char* splitPoint = strchr(jsonString, ':');

  // Extract key and value
  keyValue->key = strndup(jsonString, splitPoint - jsonString);
  keyValue->value = strdup(splitPoint + 1);

  // Remove quotes from the value
  if(keyValue->value[0] == '"' && keyValue->value[strlen(keyValue->value) - 1] == '"') {
    keyValue->value[strlen(keyValue->value) - 1] = '\0';
    keyValue->value++;
  }

  return keyValue;
}

// Define a function to parse a JSON object
JSONKeyValue** parseJSONObject(char* jsonString) {
  // Find the number of key-value pairs in the JSON object
  int numPairs = 0;
  for(int i = 0; i < strlen(jsonString); i++) {
    if(jsonString[i] == ',') {
      numPairs++;
    }
  }

  // Allocate memory for the key-value pairs
  JSONKeyValue** keyValuePairs = malloc(sizeof(JSONKeyValue*) * (numPairs + 1));

  // Parse each key-value pair
  char* remainingString = jsonString;
  char* nextPair;
  bool isFirstPair = true;
  int i = 0;
  while((nextPair = strtok_r(remainingString, "}", &remainingString))) {
    // If this isn't the first pair, add back the closing curly brace
    if(!isFirstPair) {
      nextPair[strlen(nextPair)] = '}';
    }
    else {
      isFirstPair = false;
    }

    // Parse the key-value pair and add it to the array
    keyValuePairs[i] = parseJSONKeyValue(nextPair);
    i++;
  }

  return keyValuePairs;
}

int main(void) {
  // Example JSON string
  char jsonString[] = "{\"name\": \"John Smith\", \"age\": 42, \"city\": \"New York\"}";

  // Parse the JSON object
  JSONKeyValue** keyValuePairs = parseJSONObject(jsonString);

  // Print the key-value pairs
  for(int i = 0; keyValuePairs[i] != NULL; i++) {
    printf("%s: %s\n", keyValuePairs[i]->key, keyValuePairs[i]->value);
  }

  // Clean up memory
  for(int i = 0; keyValuePairs[i] != NULL; i++) {
    free(keyValuePairs[i]->key);
    free(keyValuePairs[i]->value);
    free(keyValuePairs[i]);
  }
  free(keyValuePairs);

  return 0;
}