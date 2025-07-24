//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Let's build a JSON parser! But not just any JSON parser. We'll build a parser that's so funny, it'll make you LOL. */

typedef enum {
  JSON_NULL,
  JSON_BOOL,
  JSON_NUMBER,
  JSON_STRING,
  JSON_ARRAY,
  JSON_OBJECT
} JSONType;

typedef struct {
  JSONType type;
  union {
    int boolean;
    double number;
    char *string;
    struct {
      struct JSONValue *value;
      struct JSONArray *next;
    } array;
    struct {
      char *key;
      struct JSONValue *value;
      struct JSONObject *next;
    } object;
  } data;
} JSONValue;

typedef struct JSONArray {
  JSONValue *value;
  struct JSONArray *next;
} JSONArray;

typedef struct JSONObject {
  char *key;
  JSONValue *value;
  struct JSONObject *next;
} JSONObject;

JSONValue *parse(char *json) {
  /* This is where the magic happens! We'll parse the JSON string and build a JSONValue struct tree as we go. */

  return NULL; /* Just a placeholder for now. */
}

void print_json(JSONValue *json) {
  /* It wouldn't be funny if we didn't print the JSON in a way that's so funny, it'll make you ROFL. */

  printf("\nHere's your JSON, buddy:\n");

  switch (json->type) {
    case JSON_NULL:
      printf("null\n");
      break;
    case JSON_BOOL:
      printf("%s\n", json->data.boolean ? "true" : "false");
      break;
    case JSON_NUMBER:
      printf("%f\n", json->data.number);
      break;
    case JSON_STRING:
      printf("\"%s\"\n", json->data.string);
      break;
    case JSON_ARRAY:
      printf("[");
      if (json->data.array.value) {
        print_json(json->data.array.value);
      }
      printf("]\n");
      break;
    case JSON_OBJECT:
      printf("{");
      if (json->data.object.key) {
        printf("\n  \"%s\": ", json->data.object.key);
        print_json(json->data.object.value);
      }
      printf("}\n");
      break;
    default:
      break;
  }
}

int main(int argc, char **argv) {
  if (argc == 1) {
    printf("Usage: %s <json>\n", argv[0]);
    return 1;
  }

  char *json = argv[1];

  JSONValue *value = parse(json);

  if (value) {
    print_json(value);

    return 0;
  } else {
    printf("Invalid JSON: \"%s\"\n", json);

    return 1;
  }
}