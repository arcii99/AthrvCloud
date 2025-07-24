//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: mind-bending
// Welcome to the most mind-bending JSON parser program!
// This program will take in a JSON file and output its contents in a unique way.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char* key;
  char* value;
} JSON_Pair;

typedef struct {
  JSON_Pair* pairs;
  size_t count;
} JSON_Object;

typedef struct {
  char* json;
  size_t position;
} JSON_Parser;

void skip_whitespace(JSON_Parser* parser) {
  while (parser->json[parser->position] == ' ' ||
         parser->json[parser->position] == '\t' ||
         parser->json[parser->position] == '\n' ||
         parser->json[parser->position] == '\r') {
    parser->position++;
  }
}

char* parse_string(JSON_Parser* parser) {
  char* string_start = parser->json + parser->position + 1;
  char* string_end = strchr(string_start, '"');
  size_t string_length = string_end - string_start;
  char* string = malloc(string_length + 1);
  strncpy(string, string_start, string_length);
  string[string_length] = '\0';
  parser->position += string_length + 2;
  return string;
}

JSON_Object* parse_object(JSON_Parser* parser) {
  JSON_Object* object = malloc(sizeof(JSON_Object));
  object->count = 0;
  object->pairs = malloc(sizeof(JSON_Pair));
  skip_whitespace(parser);
  if (parser->json[parser->position] == '}') {
    parser->position++;
    return object;
  }
  while (parser->json[parser->position] != '\0') {
    char* key = parse_string(parser);
    skip_whitespace(parser);
    if (parser->json[parser->position] != ':') {
      printf("Expected ':', found %c\n", parser->json[parser->position]);
      exit(1);
    }
    parser->position++;
    char* value = parse_string(parser);
    object->pairs = realloc(object->pairs, (object->count + 1) * sizeof(JSON_Pair));
    object->pairs[object->count].key = key;
    object->pairs[object->count].value = value;
    object->count++;
    skip_whitespace(parser);
    if (parser->json[parser->position] == '}') {
      parser->position++;
      return object;
    }
    if (parser->json[parser->position] != ',') {
      printf("Expected ',' or '}', found %c\n", parser->json[parser->position]);
      exit(1);
    }
    parser->position++;
    skip_whitespace(parser);
  }
  printf("Unexpected end of input\n");
  exit(1);
}

int main() {
  JSON_Parser parser;
  parser.json = "{\"name\": \"John\", \"age\": 42}";
  parser.position = 0;
  JSON_Object* object = parse_object(&parser);
  printf("Parsed %lu pairs:\n", object->count);
  for (size_t i = 0; i < object->count; i++) {
    printf("%s = %s\n", object->pairs[i].key, object->pairs[i].value);
  }
  return 0;
}