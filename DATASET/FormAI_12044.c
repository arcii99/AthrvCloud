//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_JSON_OBJECTS 100
#define MAX_JSON_STRING_LENGTH 100

typedef enum {
  JSON_NULL,
  JSON_BOOLEAN,
  JSON_STRING,
  JSON_NUMBER,
  JSON_OBJECT_START,
  JSON_OBJECT_END,
  JSON_ARRAY_START,
  JSON_ARRAY_END
} json_type_t;

typedef struct {
  json_type_t type;
  union {
    bool boolean_value;
    char string_value[MAX_JSON_STRING_LENGTH];
    double number_value;
  } value;
} json_object_t;

typedef struct {
  char *input_string;
  json_object_t objects[MAX_JSON_OBJECTS];
  int objects_count;
} json_parser_t;

void add_json_object(json_parser_t *parser, json_type_t type, const char *value) {
  json_object_t object;
  object.type = type;
  switch (type) {
    case JSON_NULL:
      break;
    case JSON_BOOLEAN:
      object.value.boolean_value = (strcmp(value, "true") == 0);
      break;
    case JSON_STRING:
      strncpy(object.value.string_value, value, MAX_JSON_STRING_LENGTH);
      break;
    case JSON_NUMBER:
      object.value.number_value = atof(value);
      break;
    case JSON_OBJECT_START:
    case JSON_OBJECT_END:
    case JSON_ARRAY_START:
    case JSON_ARRAY_END:
      break;
  }
  parser->objects[parser->objects_count++] = object;
}

void parse_json(json_parser_t *parser) {
  int i;
  bool in_string = false;
  char buffer[MAX_JSON_STRING_LENGTH];
  int buffer_index = 0;

  for (i = 0; i < strlen(parser->input_string); i++) {
    char c = parser->input_string[i];

    if (in_string) {
      if (c == '\"') {
        in_string = false;
        add_json_object(parser, JSON_STRING, buffer);
        memset(buffer, 0, MAX_JSON_STRING_LENGTH);
        buffer_index = 0;
      } else {
        buffer[buffer_index++] = c;
      }
    } else {
      if (c == '\"') {
        in_string = true;
      } else if (c == '{') {
        add_json_object(parser, JSON_OBJECT_START, NULL);
      } else if (c == '}') {
        add_json_object(parser, JSON_OBJECT_END, NULL);
      } else if (c == '[') {
        add_json_object(parser, JSON_ARRAY_START, NULL);
      } else if (c == ']') {
        add_json_object(parser, JSON_ARRAY_END, NULL);
      } else if (c == 't') {
        add_json_object(parser, JSON_BOOLEAN, "true");
        i += 3;
      } else if (c == 'f') {
        add_json_object(parser, JSON_BOOLEAN, "false");
        i += 4;
      } else if (c == 'n') {
        add_json_object(parser, JSON_NULL, NULL);
        i += 3;
      } else if (c == ',' || c == ':') {
        // Do nothing
      } else if ((c >= '0' && c <= '9') || c == '-') {
        buffer[buffer_index++] = c;
        while ((parser->input_string[i + 1] >= '0' && parser->input_string[i + 1] <= '9') || parser->input_string[i + 1] == '.') {
          buffer[++buffer_index] = parser->input_string[++i];
        }
        add_json_object(parser, JSON_NUMBER, buffer);
        memset(buffer, 0, MAX_JSON_STRING_LENGTH);
        buffer_index = 0;
      }
    }
  }
}

int main() {
  json_parser_t parser;
  char input_string[] = "{\"name\":\"John Doe\",\"age\":33,\"isMarried\":true,\"pets\":[\"dog\",\"cat\"]}";
  parser.input_string = input_string;
  parser.objects_count = 0;
  parse_json(&parser);

  printf("Parsed JSON:\n");
  int i;
  for (i = 0; i < parser.objects_count; i++) {
    json_object_t obj = parser.objects[i];
    switch (obj.type) {
      case JSON_NULL:
        printf("NULL\n");
        break;
      case JSON_BOOLEAN:
        printf("%s\n", obj.value.boolean_value ? "true" : "false");
        break;
      case JSON_STRING:
        printf("%s\n", obj.value.string_value);
        break;
      case JSON_NUMBER:
        printf("%f\n", obj.value.number_value);
        break;
      case JSON_OBJECT_START:
        printf("{\n");
        break;
      case JSON_OBJECT_END:
        printf("}\n");
        break;
      case JSON_ARRAY_START:
        printf("[\n");
        break;
      case JSON_ARRAY_END:
        printf("]\n");
        break;
    }
  }

  return 0;
}