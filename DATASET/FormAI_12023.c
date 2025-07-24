//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OBJECTS 100
#define MAX_OBJECT_NAME_LENGTH 50
#define MAX_OBJECT_ATTRIBUTES 20
#define MAX_ATTRIBUTE_NAME_LENGTH 50
#define MAX_ATTRIBUTE_VALUE_LENGTH 100

typedef struct {
  char name[MAX_OBJECT_NAME_LENGTH];
  int num_attributes;
  char attribute_names[MAX_OBJECT_ATTRIBUTES][MAX_ATTRIBUTE_NAME_LENGTH];
  char attribute_values[MAX_OBJECT_ATTRIBUTES][MAX_ATTRIBUTE_VALUE_LENGTH];
} JSON_Object;

JSON_Object json_objects[MAX_OBJECTS];
int num_objects;

char* remove_quotes(char* str) {
  int i, j;
  char* result = (char*)malloc(strlen(str) * sizeof(char));
  for (i = 1, j = 0; i < strlen(str) - 1; i++, j++) {
    result[j] = str[i];
  }
  result[j] = '\0';
  return result;
}

void parse_attribute(char* attribute, char* object_name) {
  int i = 0, j = 0, k = 0;
  char* name = (char*)malloc(MAX_ATTRIBUTE_NAME_LENGTH * sizeof(char));
  char* value = (char*)malloc(MAX_ATTRIBUTE_VALUE_LENGTH * sizeof(char));
  while (attribute[i] != ':') {
    name[j++] = attribute[i++];
  }
  name[j] = '\0';
  i++; // skip the ':' character
  while (attribute[i] != ',' && attribute[i] != '}') {
    value[k++] = attribute[i++];
  }
  value[k] = '\0';
  strcpy(json_objects[num_objects].attribute_names[json_objects[num_objects].num_attributes], name);
  strcpy(json_objects[num_objects].attribute_values[json_objects[num_objects].num_attributes], value);
  json_objects[num_objects].num_attributes++;
}

void parse_object(char* object) {
  int i = 0, j = 0;
  char* name = (char*)malloc(MAX_OBJECT_NAME_LENGTH * sizeof(char));
  while (object[i] != ':') {
    name[j++] = object[i++];
  }
  name[j] = '\0';
  i++; // skip the ':' character
  strcpy(json_objects[num_objects].name, name);
  json_objects[num_objects].num_attributes = 0;

  // parse the attributes
  j = 0;
  while (object[i] != '}') {
    if (object[i] == ',') {
      parse_attribute(&object[j+1], json_objects[num_objects].name);
      j = i;
    }
    i++;
  }
  parse_attribute(&object[j+1], json_objects[num_objects].name);
}

int main() {
  char json_string[] = "{ \"person\" : { \"name\": \"John\", \"age\": 30, \"address\": { \"street\": \"123 Main St\", \"city\": \"Anytown\" } }, \"book\" : { \"title\": \"The Great Gatsby\", \"author\": \"F. Scott Fitzgerald\", \"year\": 1925 } }";
  int i = 0, j = 0;
  while (i < strlen(json_string)) {
    if (json_string[i] == '{') {
      j = i;
      while (json_string[i] != '}') {
        i++;
      }
      char* object = (char*)malloc((i-j+2) * sizeof(char));
      strncpy(object, &json_string[j], i-j+1);
      object[i-j+1] = '\0';
      parse_object(object);
      num_objects++;
    }
    i++;
  }

  // print out the parsed JSON objects
  for (i = 0; i < num_objects; i++) {
    printf("%s:\n", json_objects[i].name);
    for (j = 0; j < json_objects[i].num_attributes; j++) {
      printf("  %s: %s\n", json_objects[i].attribute_names[j], remove_quotes(json_objects[i].attribute_values[j]));
    }
  }

  return 0;
}