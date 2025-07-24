//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: scalable
// Building a JSON Parser example program in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum {
  JSON_OBJECT,
  JSON_ARRAY,
  JSON_STRING,
  JSON_NUMBER,
  JSON_BOOL,
  JSON_NULL
} JsonType;

typedef struct {
  JsonType type;
  union {
    /* data */
    char *string;
    int number;
    bool boolean;
  } value;
} Json;

static char *json_string;
static int json_position;

// Helper Function to check whether the given character is a white space
static bool is_whitespace(char c) {
  return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

// Helper Function to skip the whitespace
static void skip_whitespace() {
  while (is_whitespace(json_string[json_position])) {
    json_position++;
  }
}

// Helper Function to parse the JSON object
static Json parse_object() {
  Json json = {
    .type = JSON_OBJECT
  };
  return json;
}

// Helper Function to parse the JSON array
static Json parse_array() {
  Json json = {
    .type = JSON_ARRAY
  };
  return json;
}

// Helper Function to parse the JSON string
static Json parse_string() {
  Json json = {
    .type = JSON_STRING
  };
  return json;
}

// Helper Function to parse the JSON number
static Json parse_number() {
  Json json = {
    .type = JSON_NUMBER
  };
  return json;
}

// Helper Function to parse the JSON Boolean
static Json parse_boolean() {
  Json json = {
    .type = JSON_BOOL
  };
  return json;
}

// Helper Function to parse the null value
static Json parse_null() {
  Json json = {
    .type = JSON_NULL
  };
  return json;
}

// Function to parse the JSON string and return the parsed JSON object
Json parse_json(char *json_str) {
  json_string = json_str;
  json_position = 0;

  skip_whitespace();
  if (json_string[json_position] == '{') {
    return parse_object();
  }
  else if (json_string[json_position] == '[') {
    return parse_array();
  }
  else if (json_string[json_position] == '\"') {
    return parse_string();
  }
  else if (json_string[json_position] == '-' || (json_string[json_position] >= '0' && json_string[json_position] <= '9')) {
    return parse_number();
  }
  else if (json_string[json_position] == 't' || json_string[json_position] == 'f') {
    return parse_boolean();
  }
  else if (json_string[json_position] == 'n') {
    return parse_null();
  }
  else {
    printf("Invalid JSON string");
    exit(1);
  }
}

void print_json(Json *json) {
  if (json->type == JSON_OBJECT)
    printf("JSON Object\n");
  else if (json->type == JSON_ARRAY)
    printf("JSON Array\n");
  else if (json->type == JSON_STRING)
    printf("JSON String\n");
  else if (json->type == JSON_NUMBER)
    printf("JSON Number\n");
  else if (json->type == JSON_BOOL)
    printf("JSON Boolean\n");
  else if (json->type == JSON_NULL)
    printf("JSON Null\n");
}

int main() {
  char json_str[] = "{\"name\":\"John\", \"age\":30, \"married\":true, \"hobbies\":[\"reading\", \"swimming\", \"gardening\"]}";

  Json json = parse_json(json_str);
  print_json(&json);

  return 0;
}