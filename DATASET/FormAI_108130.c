//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for storing the JSON data
typedef struct {
  char* key;
  char* value;
} json_data;

// Define a function to parse the JSON data
json_data* json_parse(char* json_str, int* num_elements) {
  // Count the number of elements in the JSON string
  int num_items = 0;
  for (int i = 0; i < strlen(json_str); i++) {
    if (json_str[i] == ':') {
      num_items++;
    }
  }

  // Allocate memory for the JSON data struct
  json_data* data = malloc(num_items * sizeof(json_data));

  // Parse the JSON string and store the data in the struct
  char* token;
  char* rest = json_str;
  int count = 0;
  while ((token = strtok_r(rest, ":", &rest))) {
    // Remove extraneous characters from the key
    char* key = strtok(token, "\"");
    key = strtok(NULL, "\"");

    // Remove extraneous characters from the value
    char* value = strtok(rest, ",");
    value = strtok(value, "\"");
    value = strtok(NULL, "\"");

    // Add the key-value pair to the struct
    data[count].key = key;
    data[count].value = value;
    count++;
  }

  // Set the number of elements and return the JSON data struct
  *num_elements = num_items;
  return data;
}

int main() {
  // Define a sample JSON string
  char* json_str = "{\"name\": \"John Doe\", \"age\": 30, \"address\": \"123 Main St\"}";

  // Parse the JSON string and print the data
  int num_elements = 0;
  json_data* data = json_parse(json_str, &num_elements);
  printf("Number of Elements: %d\n", num_elements);
  for (int i = 0; i < num_elements; i++) {
    printf("Key: %s, Value: %s\n", data[i].key, data[i].value);
  }

  // Free memory allocated for the JSON data struct
  free(data);

  return 0;
}